//Sequência decrescente
#include <stdio.h>

int imprimir_aux(int n, int pivo) {
    if(n < pivo) {
        return 1;
    }
    printf("%d ", n-pivo);
    return imprimir_aux(n, pivo+1);
}

int imprimir(int n) {
    return imprimir_aux(n, 0);
}

int main() {

    imprimir(10);

    return 0;
}