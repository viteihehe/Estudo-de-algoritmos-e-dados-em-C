//Hiperfatorial
#include <stdio.h>
#include <stdlib.h>

int expI(int k, int n, int acc) {
    if(n == 0) {
        return acc;
    }
    return expI(k, n-1, k*acc);
}

int hiperFat_aux(int n, int acc) {
    if(n <= 1) {
        return acc;
    }
    int temp = expI(n, n, 1);
    return hiperFat_aux(n-1, temp*acc);
}

int hiperFat(int n) {
    return hiperFat_aux(n, 1);
}

int main(int argc, char *argv[]) {

    int x = atoi(argv[1]);

    printf("Hiperfatoriad de %d é %d\n", x, hiperFat(x));

    return 0;
}