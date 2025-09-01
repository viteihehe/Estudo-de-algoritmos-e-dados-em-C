#include <stdio.h>
#include <string.h>

int main() {
    char inventario[5][20];
    char temp[20];

        for(int i = 0; i < 5; i++) {
            printf("Insira o %dº item:\n", i+1);
            scanf("%[^\n]s", inventario + i);
            getchar();
        }
        printf("Insira o item necessario para abrir a porta:\n");
        scanf("%[^\n]s", temp);

        for(int i = 0; i < 5; i++) {
            if(strcmp(inventario[i], temp) == 0){
                printf("Porta aberta!\n");
                break;
            }else if(i == 4){
                 printf("Voce nao tem o item necessario\n");
            }

        }

    return 0;
}
