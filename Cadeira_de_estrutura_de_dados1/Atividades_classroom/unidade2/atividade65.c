#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome [50];
    int pontuacao;
} Jogador;

int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    Jogador* jogadores = (Jogador *)calloc(n, sizeof(Jogador));

    int i, j;
    for(i = 0; i < n; i++) {
        printf("Insira o nome do %d jogador:\n", i+1);
        scanf(" %[^\n]s", jogadores[i].nome);
        printf("Insira a pontuacao:\n");
        scanf("%d", &jogadores[i].pontuacao);
    }

    for(i = 1; i < n; i++) {
        Jogador x = jogadores[i];
        for(j = i-1; j >= 0 && x.pontuacao < jogadores[j].pontuacao; j--) {
            jogadores[j + 1] = jogadores[j];
        }
        jogadores[j+1] = x;
    }
    
    for(i = 0; i < n; i++) {
        printf("%d %s\n", jogadores[i].pontuacao, jogadores[i].nome);
    }

    return 0;
}