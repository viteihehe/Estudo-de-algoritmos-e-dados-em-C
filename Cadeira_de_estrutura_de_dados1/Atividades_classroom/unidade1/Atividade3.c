#include <stdio.h>

int main() {
    float coordenada_x;
    float *ponteiro_x;
    ponteiro_x = &coordenada_x;

    printf("Insira a coordenada x do portal: \n");
    scanf("%f", ponteiro_x);

    printf("Posicao do portal no eixo X: %.2f\n", *ponteiro_x);

    printf("Endereco do portal para teletransporte: %p\n", ponteiro_x);

    return 0;
}