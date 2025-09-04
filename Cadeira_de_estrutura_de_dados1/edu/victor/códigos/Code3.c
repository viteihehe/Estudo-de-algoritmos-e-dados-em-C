#include <stdio.h>
#include <stdlib.h>

int main() {
    int quantidade;

    printf("Insira o tanto de valores lidos: \n");
    scanf("%d", &quantidade);

    int *pquantidade = (int *) malloc(quantidade * sizeof(int));


    for(int i = 0; i < n; i++) {
        printf("Insira o %d numero:\n", i+1);
        scanf("%d", pquantidade+i);
    }

    int menor = *pn;
    int posicao = 0;

    for(int i = 0; i < n; i++) {
        if(*(pquantidade + i) < menor) {
            menor = *(pn + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d \n", menor, posicao);

    free(pn);
    pn = NULL;


    return 0;
}