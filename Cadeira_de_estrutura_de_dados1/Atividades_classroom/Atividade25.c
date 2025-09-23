#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade_inimigos;

        printf("Insira a quantidade de inimigos:\n");
        scanf("%d", &quantidade_inimigos);

        if(quantidade_inimigos < 0) {
            quantidade_inimigos *= -1;
        }

            int *status_inimigos = (int *) calloc(quantidade_inimigos, sizeof(int));

                if(status_inimigos == NULL) {
                    printf("Erro!");
                    exit(0);
                }
            for(int i = 0; i < quantidade_inimigos; i++) {
                printf("Inimigo %d: inativo (%d)\n", i+1, *(status_inimigos+i));
            }

            for(int i = 0; i < quantidade_inimigos; i++) {
                *(status_inimigos+i) = 1;
                printf("Inimigo %d: Ativo (%d)\n", i+1, *(status_inimigos+i));
            }

            free(status_inimigos);
            status_inimigos = NULL;
            
            


    return 0;
}