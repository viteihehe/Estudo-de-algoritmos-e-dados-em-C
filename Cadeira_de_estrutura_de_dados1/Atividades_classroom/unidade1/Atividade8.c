#include <stdio.h>

int main() {
    int fase[] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0}, moedas_coletadas = 0;
    int *ponteiro_jogador = fase;

    for(int i = 0; i < 10; i++) {
        if(*(ponteiro_jogador+i)){
            moedas_coletadas++;
        }
    }

    printf("O jogador coletou um total de %d moedas!", moedas_coletadas);


    return 0;
}