//somatorio elementos vetor
#include <stdio.h>




int aux_sum(int n [], int tam , int acc) {
    if(tam == 0) {
        return acc;
    }

    return aux_sum(n+1, tam-1 ,acc+(*n));
}

int soma(int n [], int tam) {
    return aux_sum(n, tam, 0);
}


int main() {

    int n [] = {1, 1, 1, 1, 1};
    int tam = sizeof(n)/sizeof(n[0]);
    int x = soma(n, tam);

    printf("%d", x);

    return 0;
}