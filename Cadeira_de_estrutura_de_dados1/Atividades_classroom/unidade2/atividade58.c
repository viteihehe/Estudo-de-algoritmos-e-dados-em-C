#include <stdio.h>

int calcularDanoEco(int n) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    return calcularDanoEco(n-1)+calcularDanoEco(n-2);
}

int main() {
    int n;
    printf("Insira o numero de golpes:\n");
    scanf("%d", &n);

    int r = calcularDanoEco(n);
    printf("Dano bonus: %d\n", r);



    return 0;
}