//Fatorial usando recursão
#include <stdio.h>

//recursão comum
int fatorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n*fatorial(n-1);
    }
}

int fat_aux(int n, int acc) {
    if(n == 0) {
        return 1;
    } else {
        return fat_aux(n, n*acc);
    }
}

//Recursão de cauda
int fat_calda(int n) {
    return fat_aux(n, 0);
}

int main() {

    int x = 4;

    int resultado = fatorial(x);

    printf("O fatorial de %d é: %d\n", x, resultado);

    return 0;
}