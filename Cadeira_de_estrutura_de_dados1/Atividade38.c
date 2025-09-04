#include <stdio.h>

enum EstadoPersonagem {PARADO, CORRENDO, PULANDO};

int main() {
    enum EstadoPersonagem estado_atual;
    int temp;

        printf("Insira um numero inteiro entre 0 e 2\n");
        scanf("%d", &temp);
        estado_atual = temp;
        switch (estado_atual)
        {
        case PARADO:
            printf("O personagem esta parado\n");
            break;
        case CORRENDO:
            printf("O personagem esta correndo!\n");
            break;
        case PULANDO:
            printf("O personagem esta pulando no ar!\n");
            break;
        
        default:
            printf("Estado invalido\n");
            break;
        }
}