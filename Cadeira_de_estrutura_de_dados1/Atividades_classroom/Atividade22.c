#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

int main() {
    int n_inimigos;
    int *ponteiro_onda;

    printf("Insira a quantidade de inimigos:\n");
    scanf("%d", &n_inimigos);

    ponteiro_onda = (int *) malloc(n_inimigos * sizeof(int));

    int tamanho = n_inimigos;

    for(int i = 0; i < tamanho; i++) {
        printf("Insira o %d ID:\n", i+1);
        scanf("%d", (ponteiro_onda + i));
        fflush(stdin);
    }

    printf("Onda de inimigos criada com sucesso! IDS:");
    for(int i = 0; i < tamanho; i++) {
        printf(" %d ", *(ponteiro_onda + i));
    }
    free(ponteiro_onda);
    ponteiro_onda = NULL;

    return 0;
}