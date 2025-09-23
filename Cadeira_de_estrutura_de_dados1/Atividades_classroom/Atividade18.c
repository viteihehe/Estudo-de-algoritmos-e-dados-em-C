#include <stdio.h>
#include <stdlib.h>

#define ERRO do { \
    printf("\a\aERRO\n"); \
    exit(0); \
} while(0)

int main() {
    int *vida_inimigo = (int *) malloc(sizeof(int));

    if(vida_inimigo == NULL) ERRO;

    *vida_inimigo = 80;

    printf("Um novo inimigo apareceu com %d de vida!\n", *vida_inimigo);
    
    *vida_inimigo -= 35;

    printf("O jogador atacou! Vida restante do inimigo: %d\n", *vida_inimigo);


    return 0;
}