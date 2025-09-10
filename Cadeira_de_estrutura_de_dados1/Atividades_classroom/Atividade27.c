#include <stdio.h>
#include <stdlib.h>

struct Inimigo {
    int vida;
    int ataque;
    float velocidade;
};

int main() {
    struct Inimigo cogumelo_zumbi; 
    struct Inimigo cavaleiro_esqueleto;

    cogumelo_zumbi.vida = 20;
    cogumelo_zumbi.ataque = 5;
    cogumelo_zumbi.velocidade = 0.8;

    cavaleiro_esqueleto.vida = 80;
    cavaleiro_esqueleto.ataque = 15;
    cavaleiro_esqueleto.velocidade = 1.2;

    printf("--Atributos do inimigo: Cogumelo Zumbi--\n");
    printf("Vida: %d\n", cogumelo_zumbi.vida);
    printf("Ataque: %d\n", cogumelo_zumbi.ataque);
    printf("Velocidade: %.1f\n", cogumelo_zumbi.velocidade);

    printf("--Atributos do inimigo: Cavaleiro Esqueleto--\n");
    printf("Vida: %d\n", cavaleiro_esqueleto.vida);
    printf("Ataque: %d\n", cavaleiro_esqueleto.ataque);
    printf("Velocidade: %.1f\n", cavaleiro_esqueleto.velocidade);

    

    return 0;
}