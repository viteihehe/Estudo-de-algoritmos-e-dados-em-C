#include <stdio.h>
#include <stdlib.h>

#define CHEKIN(j) (j.tem_pulo_duplo == 0) ? "Nao" : "Sim"

struct Jogador {
    float pos_x;
    int pontuacao;
    int tem_pulo_duplo;
};


int main() {
    struct Jogador heroi;
    heroi.pos_x = 50;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;


        printf("Inicio da fase! Posicao X %.1f, Pontos %d, Pulo duplo: %s\n", heroi.pos_x, heroi.pontuacao, CHEKIN(heroi));

            heroi.pontuacao = 10;
            heroi.tem_pulo_duplo = 1;

                printf("Inicio da fase! Posicao X %.1f, Pontos %d, Pulo duplo: %s\n", heroi.pos_x, heroi.pontuacao, CHEKIN(heroi));

    return 0;
}