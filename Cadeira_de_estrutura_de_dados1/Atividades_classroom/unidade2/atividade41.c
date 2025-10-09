#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("================================\n");
    printf("1 - Registrar evento\n");
    printf("2 - Sair\n");
    printf("===================================\n");
}

int main() {
    int loop = 1, op;
    FILE *file = fopen("./game_log.txt", "a");

    while(loop) {
        menu();
        scanf("%d", &op);
        switch(op) {
            case 1:
                char evento [50];
                printf("Descreva o evento: (sem espaços)\n");
                scanf(" %s", evento);
                fprintf(file, "%s\n", evento);
                fflush(file);
                break;
            case 2:
                printf("Encerrando o programa!\n");
                loop = 0;
                break;
        }
    }

    fclose(file);



    return 0;
}