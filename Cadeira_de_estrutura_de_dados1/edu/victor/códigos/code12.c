#include <stdio.h>

void menu() {
    printf("=== escolha uma opcao ===\n");
    printf("1 - cadastrar\n");
    printf("2 - listar\n");
    printf("3 - editar\n");
    printf("4 - desempenho\n");
    printf("0 - sair\n");
    printf("==========================\n");
}

typedef struct code12
{
   char nome [100];
   int numero_matricula;
   float notas [3];
   float media;
}Estudante;


void cadastrar(Estudante*e, int *n) {
    
    printf("Insira o nome do estudante:\n");
    scanf(" %[^\n]s", e->nome);

    printf("Insira a matricula:\n");
    scanf("%d", &e->numero_matricula);

    for(int i = 0; i < 3; i++) {
        printf("Insira a %d nota:\n", i+1);
        scanf("%f", &e->notas[i]);
    }
    (*n)++;

}

void listar(Estudante *e, int n) {
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\nMatricula: %d\n", e[i].nome, e[i].numero_matricula);
    }
}

void editar(Estudante *e, int n) {
    
        int op = 1;
        while(op != 0) {
        printf("O que você deseja alterar?\n");
        printf("1 - nome\n");
        printf("2 - matricula\n");
        printf("3 - notas\n");
        printf("0 - sair\n");
        printf("==========================\n");
        scanf("%d", &op);

            switch (op)
            {
            case 1:
                printf("Insira o novo nome: \n");
                scanf(" %[^\n]s", e->nome);
                break;
            case 2:
                printf("Insira a nova matricula:\n");
                scanf("%d", &e->numero_matricula);
                break;
            case 3:
                int notatemp;
                printf("Qual nota voce deseja editar:\n");
                scanf("%d", &notatemp);
                notatemp--;

               if(notatemp >-1 && notatemp < 3) {
                 printf("Insira a nova nota:\n");
                 scanf("%f", &e->notas[notatemp]);
               }  

                break;
            
            default:
                printf("Não existe essa opcao\n");
                break;
            }
        }
    

}

void media(Estudante *e, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            e[i].media = e[i].notas[j];
        }
    }
}

void desempenho(Estudante *e, int n) {
    media(e, n);
    for(int i = 0; i < n; i++) {
        if(e[i].media >= 7) {
            printf("%s esta com bom desepenho!!!\n", e[i].nome);
        }
    }
}

int busca(Estudante *e, int n) {
    int temp;
    printf("Insira a matricula:\n");
    scanf("%d", &temp);
    for(int i = 0 ; i < n; i++) {
        if(temp == e->numero_matricula) {
            return i;
            break;
        }else{
            printf("O estudante não existe!\n");
            return 1001;
           
        }
    }
}



int main() {
    int op;
    menu();
    scanf("%d", &op);
    int max = 1000;
    int n = 0;
    Estudante e[max];
    while (op != 0) {
        if (op == 1) {
            cadastrar(&e[n],&n);
        }else if (op == 2)
        {
            listar(e, n);
        }else if (op == 3) {
            int temp = busca(e, n);
            if(temp != 1001) {
                editar(&e[temp], n);
            }
    
        }else if (op == 4)
        {
            desempenho(&e, n);
        }
        
        
        menu();
        scanf("%d", &op);
    }
    
    return 0;
}