#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int saude;
    int pontuacao;
    int posX;
    int posY;
} Heroi;

int main () {
    Heroi meuHeroi = {100, 0, 0, 0};

    printf("Estado inicial: %d %d %d %d\n", meuHeroi.saude, meuHeroi.pontuacao, meuHeroi.posX, meuHeroi.posY);

        Heroi *ptrHeroi = &meuHeroi;

        ptrHeroi -> saude -= 25;
        printf("Voce sofreu danos! Saude: %d\n",  ptrHeroi -> saude);

        ptrHeroi -> pontuacao += 50;
          printf("Voce achou um saco de moedas! Pontuacao: %d\n",  ptrHeroi -> pontuacao);

        ptrHeroi -> posX += 10;
        ptrHeroi -> posY -= 5;

        printf("Voce achou um saco de moedas! PosX: %d PosY: %d\n",  ptrHeroi -> posX, ptrHeroi -> posY);

            printf("Estado Final: %d %d %d %d\n", ptrHeroi -> saude, ptrHeroi -> pontuacao, ptrHeroi -> posX, ptrHeroi -> posY);
        



          return 0;
}       
    

