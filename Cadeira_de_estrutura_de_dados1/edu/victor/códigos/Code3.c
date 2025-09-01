#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Insira o tanto de valores lidos: \n");
    scanf("%d", &n);

    int *pn = (int *) malloc(n * sizeof(int));


    for(int i = 0; i < n; i++) {
        printf("Insira o %d numero:\n", i+1);
        scanf("%d", pn+i);
    }

    int menor = *pn;
    int posicao = 0;

    for(int i = 0; i < n; i++) {
        if(*(pn + i) < menor) {
            menor = *(pn + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\nPosicao: %d \n", menor, posicao);

    free(pn);
    pn = NULL;


    return 0;
}