#include <stdio.h>

int positivos(int n, int v[], int i) {
    if(i == n) {
        return 0;
    }
    if(v[i] > 0) {
        return 1+positivos(n, v, i+1);
    }
    return positivos(n, v, i+1);
}

int main() {
    int n;
    printf("Insira a quantidade de cristais:\n");
    scanf("%d", &n);

    int v[n];
    int i;
    for( i = 0; i < n; i++) {
        printf("Insira o nivel de carga do cristal %d:\n", i+1);
        scanf("%d", &v[i]);
    }

    int total = positivos(n, v, 0);

    printf("Quantidade de cristais com carga positiva: %d\n", total);


    return 0;
}