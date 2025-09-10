#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pontos;
    float pos_x;
    float pos_y;
} Coletavel;

int main() {
    Coletavel gema_rara;

        printf("Insira o valor em pontos a posicao x e a posicao y:\n");
        scanf("%d %f %f", &gema_rara.pontos, &gema_rara.pos_x, &gema_rara.pos_y);

            printf("Coletável criado! Valor: [%d] pontos. Posição: (X=[%.1f], Y=[%.1f])", gema_rara.pontos, gema_rara.pos_x, gema_rara.pos_y);

    return 0;
}