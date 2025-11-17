#include <stdio.h>
#include "combate.h"

typedef struct {
    int ataque;
    int bonus;
} Heroi;

int main() {
    int vida_inimigo;
    Heroi heroi;
    printf("Insira o ataque base, o bonus e a vida do inimigo:\n");
    scanf("%d %d %d", &heroi.ataque, &heroi.bonus, &vida_inimigo);

    int ataque_total = calcular_ataque_total(heroi.ataque, heroi.bonus); 
    vida_inimigo = aplicar_dano(vida_inimigo, ataque_total);

    printf("Dano total do heroi: %d\nVida restante do inimigo: %d\n",
    ataque_total, vida_inimigo);

    return 0;
}