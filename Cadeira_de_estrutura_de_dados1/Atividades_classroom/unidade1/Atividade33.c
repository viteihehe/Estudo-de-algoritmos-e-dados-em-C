#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Posicao;

void mover_personagem(Posicao *p, int movimento_x, int movimento_y);

int main() {
    Posicao posicao_jogador = {0, 0};
    Posicao *ponteiro_posicao = &posicao_jogador;

    printf("Posicao inicial do jogador: X: %d Y: %d\n", (*ponteiro_posicao).x, (*ponteiro_posicao).y);

    mover_personagem(ponteiro_posicao, 10, 5);

    printf("Posicao final do jogador: X: %d Y: %d\n", (*ponteiro_posicao).x, (*ponteiro_posicao).y);

    return 0;
}

void mover_personagem(Posicao *p, int movimento_x, int movimento_y) {
    (*p).x += movimento_x;
    p -> y += movimento_y;

}