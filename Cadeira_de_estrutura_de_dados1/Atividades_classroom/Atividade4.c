#include <stdio.h>


void aplicar_powerup_pontuacao_dupla(int *ppontuacao_jogador);


int main() {
    int pontuacao_jogador = 1500;
    int *ppontuacao_jogador = &pontuacao_jogador;
    printf("Pontuacao antes do power-up: %d\n", pontuacao_jogador);

    aplicar_powerup_pontuacao_dupla(ppontuacao_jogador);

    printf("Pontuacao apos o power-up: %d\n", *ppontuacao_jogador);


    return 0;
}

void aplicar_powerup_pontuacao_dupla(int *ppontuacao_jogador){
    *pontuacao_jogador = 2 * *pontuacao_jogador;
}
