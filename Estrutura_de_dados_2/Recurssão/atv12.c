//Impressão natual
#include <stdio.h>

int imprimir_aux(int n, int pivo) {
    if(pivo < 0) {
        return 1;
    }
    printf("%d ", n-pivo);
    return imprimir_aux(n, pivo-1);
}

int imprimir(int n) {
    return imprimir_aux(n, n);
}

int main() {

    imprimir(10);

    return 0;
}