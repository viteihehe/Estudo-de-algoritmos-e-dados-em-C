#include <stdio.h>

typedef struct {

    int posX;
    int posY;
    int moedas;

} Personagem;

void atualizarPersonagem(Personagem *p);

int main() {
    Personagem jogador = {0, 0, 0};
    printf("Posicao inicial: (%d, %d) Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);

    atualizarPersonagem(&jogador);

    printf("Posicao inicial: (%d, %d) Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);

    return 0;
}

void atualizarPersonagem(Personagem *p) {
    p -> posX = 10; 
    p -> posY = 10;
    p -> moedas = 1;
}