#include <stdio.h>
#include <stdlib.h>

int main() {
    int *mochila = (int *) malloc(3 * sizeof(int));

        if(mochila == NULL){
            exit(0);
        }

    for(int i = 0; i < 3; i++) {
        printf("Um novo item! Adicione o valor na mochila: \n");
        scanf("%d", mochila+i);
    }

    printf("mochila:\n");
        for(int i = 0; i < 3; i++) {
            printf(" %d ", *(mochila+i));
        }
        printf("\n");

        printf("Voce encontrou um item de expasao de mochila, voce tem mais 3 espaços!\n");

        mochila = (int *) realloc(mochila, 6 * sizeof(int));

             for(int i = 3; i < 6; i++) {
                printf("Um novo item! Adicione o valor na mochila: \n");
                scanf("%d", mochila+i);
            }

            printf("mochila:\n");
                for(int i = 0; i < 6; i++) {
                printf(" %d ", *(mochila+i));
                }

                free(mochila);
                mochila = NULL;



    return 0;
}