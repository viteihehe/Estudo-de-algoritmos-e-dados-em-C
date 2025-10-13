#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ID;
    char nome [50];
    int forca;
    int agilidade;
    int inteligencia;

} Personagem;

void registrar(Personagem *p, int auxi) {
    printf("Insira seu nome:\n");
    scanf(" %s", p->nome);
    p->ID = auxi;
    printf("Insira sua forca:\n");
    scanf("%d", &p->forca);
    printf("Insira sua agilidade:\n");
    scanf("%d", &p->agilidade);
    printf("Insira sua inteligencia:\n");
    scanf("%d", &p->inteligencia);
}

void menu() {
    printf("=============================\n");
    printf("1 - Consultar Personagem\n");
    printf("2 - Sair\n");
    printf("=============================\n");
}

int pesquisar(Personagem pv[], int id, int n) {
    for(int i = 0; i < n; i++) {
        if(pv[i].ID == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, auxi = 1, loop = 1;

        printf("Insira a quantidade de personagens:\n");
        scanf("%d", &n);

        Personagem p[n];

        for(int i = 0; i < n; i++) {
            printf("Personagem %d:\n", i+1);
            registrar(&p[i], auxi);
            auxi++;
        }

    while(loop) {
        int op;
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            float media;
            int tempid;
            printf("Insira o id do personagem:\n");
            scanf("%d", &tempid);
            int temp = pesquisar(p, tempid, n);
            media = (p[temp].forca + p[temp].inteligencia + p[temp].agilidade)/3;
            printf("%s\nMedia de atributos: %.2f\n", p[temp].nome, media);
            break;
        case 2:
            printf("Encerrando o programa!\n");
            loop = 0;
            break;

        default:
            printf("Entrada invalida!\a\a\n");
            break;
        }
    }





    return 0;
}

