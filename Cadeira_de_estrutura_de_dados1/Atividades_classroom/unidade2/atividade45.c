#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome [50];
    int nivel;
    float vida;
    float mana;
} Personagem;

void menu() {
    printf("================================\n");
    printf("1 - Criar Novo Personagem\n");
    printf("2 - Sair\n");
    printf("===================================\n");
}

int main() {
    int op, loop = 1;
    FILE *file = fopen("./savegame.sav", "wb");
    if(file == NULL) {
        printf("erro ao criar o arquivo!\n");
        exit(0);
    }
    Personagem p;
    while(loop) {
        menu();
        scanf("%d", &op);
        switch(op) {

            case 1:
                printf("Insira o nome:\n");
                scanf(" %[^\n]s", p.nome);
                p.nivel = 1;
                p.vida = 20;
                p.mana = 10;

                fwrite(&p, sizeof(Personagem), 1, file);
                fflush(file);

                break;
            case 2:
                printf("Finalizando programa!\n");
                loop = 0;
                break;
            default:
                printf("opcao invalida!!!\n");
                break;
        }
    }

    fclose(file);




    return 0;
}