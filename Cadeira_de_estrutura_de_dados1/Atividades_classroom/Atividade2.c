#include <stdio.h>

int main() {
    int tesouro_local;
    int *plataforma_secreta;

    plataforma_secreta = &tesouro_local;

    printf("O tesouro ainda nao apareceu. Valor: %d\n", tesouro_local);

    *plataforma_secreta = 1;

    printf("O personagem pisou na plataforma secreta! O tesouro apareceu! Valor: %d\n", *plataforma_secreta);

    return 0;
}