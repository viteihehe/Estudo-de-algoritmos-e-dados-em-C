#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int vida = 100;
    int *ponteiroVida;

    vida = 50;
    printf("O jogador sofreu dano! Vida atual: %d\n", vida);
    ponteiroVida = &vida;

    *ponteiroVida = 100;

    printf("Power-up coletado! Vida restaurada: %d\n", *ponteiroVida);

    return 0;
}