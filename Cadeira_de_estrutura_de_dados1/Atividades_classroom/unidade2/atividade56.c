#include <stdio.h>

int dano(int n) {
    if(n == 1) {
        return 1;
    }
    return n + dano(n-1);
}

int main() {
    int nivel;

    printf("Insira o nivel do mago:\n");
    scanf("%d", &nivel);

    int danoCascata = dano(nivel);

    printf("Dano total: %d\n", danoCascata);


    return 0;
}