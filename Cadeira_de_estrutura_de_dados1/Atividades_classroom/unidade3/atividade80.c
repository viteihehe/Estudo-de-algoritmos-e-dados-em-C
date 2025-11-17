#include "personagem/personagem.h"
#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de personagens:\n");
    scanf("%d", &n);

    Personagem* p = cria_party(n);
    registra_membros(p, n);
    exibe_relatorio(p, n);
    libera_party(p);

    return 0;
}