#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome [10];
    int diasRestantes;
} Livro;

char bd[20] = "biblioteca.b";

void adicionarLivro(int n);

void buscarLivro();

void menu() {
    printf("=================================\n");
    printf("1 - Adicionar livro\n");
    printf("2 - Lista de livros\n");
    printf(" - Sair\n");
    printf("=================================\n");
}
void listarLivros();

float calcularatraso(Livro livro);
int situacao(Livro *livro);

int main() {
    int loop = 1, op;
   
    while(loop) {
        menu();
        scanf("%d", &op);
        switch(op){

            case 1:
                int n;
               
                printf("Insira a quantidade de livros que deseja inserir:\n");
                scanf("%d", &n);
                adicionarLivro(n);

                break;
            case 2:
                listarLivros();
                break;

            default:
                printf("Opcao invalidade tente novamente!\n");
            break;

        }

    } 
    
}

void adicionarLivro(int n) {    
    for(int i = 0; i < n; i++) {
        Livro livro;
        int tempid;
        printf("Insira o id:\n");
        scanf("%d", &tempid);
        FILE *file = fopen(bd, "rb");
        while(fread(&livro, sizeof(Livro), 1, file)) {
            if(tempid == livro.id) {
                printf("Esse id já foi cadastrado");
                break;
            }
        }
        fclose(file);

        livro.id = tempid;
        printf("Insira o nome do livro:\n");
        scanf(" %[^\n]s", livro.nome);
        printf("Insira os dias para devolucao:\n");
        scanf("%d", &livro.diasRestantes);

        file = fopen( bd, "ab");
        fwrite(&livro, sizeof(Livro), 1, file);
        fflush(file);
        fclose(file);
    }
}

void listarLivros() {
    FILE *file = fopen(bd, "rb");
    Livro livro;
    int i = 1;
    while(fread(&livro, sizeof(Livro), 1, file)) {
        printf("================================\n");
        printf("Livro %d:\n", i);
        printf("ID: %d\n", livro.id);
        printf("Titulo: %s\n", livro.nome);
        printf("Dias Restantes: %d\n", livro.diasRestantes);
        float temp = calcularatraso(livro);
        if(temp) {
            printf("Situacao: Atrasado\n");
            printf("Multa: %.2f R$\n", temp);
        }else {
            printf("Situacao: Em dia\n");
        }
        printf("================================\n");
        i++;
    }
    fclose(file);
}

int situacao(Livro *livro) {
    if(livro->diasRestantes < 0) {
        return 1;
    }else {
        return 0;
    }
}

float calcularatraso(Livro livro) {
    Livro *pliv = &livro;
    if(situacao(pliv)) {
        int multa = livro.diasRestantes*(-1.5);
        return multa;
    }else{
        return 0;
    }
}

void buscarLivro() {
    FILE *file = fopen(bd, "rb");
    Livro livro;
    int tempid;
    printf("Insira o id do livro:\n");
    scanf("%d", &tempid);
    while(fread(&livro, sizeof(Livro), 1, file)) {
        if(tempid == livro.id) {
            printf("================================\n");
        printf("Livro:\n");
        printf("ID: %d\n", livro.id);
        printf("Titulo: %s\n", livro.nome);
        printf("Dias Restantes: %d\n", livro.diasRestantes);
        float temp = calcularatraso(livro);
        if(temp) {
            printf("Situacao: Atrasado\n");
            printf("Multa: %.2f R$\n", temp);
        }else {
            printf("Situacao: Em dia\n");
        }
        printf("================================\n");
        }
    }
}