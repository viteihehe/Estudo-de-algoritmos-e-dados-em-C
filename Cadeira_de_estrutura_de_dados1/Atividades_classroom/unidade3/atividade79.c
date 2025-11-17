#include "heroi/heroi.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Insira a quantidade de herois:\n");
    scanf("%d", &n);

    Heroi* herois = criar(n);

    ler(n, herois);
    imprimir(n, herois);

    free(herois);

    return 0;
}