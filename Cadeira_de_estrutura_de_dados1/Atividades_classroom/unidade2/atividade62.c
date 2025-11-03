#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome [50];
    int numeroDeEliminacoes;
} Jogador;

void ler(Jogador* Jogador) {
    printf("Insira o nome:\n");
    scanf(" %[^\n]s", Jogador->nome);
    printf("Insira o numero de eliminacoes:\n");
    scanf("%d", &Jogador->numeroDeEliminacoes);
}

void ordenacao(Jogador jogadores[], int tamanho) {
    int i, j;
    for(i = 0; i < tamanho-1; i++) {
        int indiceMaior = i;
        for(j = 0; j < tamanho; j++) {
            if(jogadores[j].numeroDeEliminacoes > jogadores[i].numeroDeEliminacoes) {
                indiceMaior = j;
            }
        }
        if(indiceMaior != i) {
        Jogador temp = jogadores[i];
        jogadores[i] = jogadores[indiceMaior];
        jogadores[indiceMaior] = temp;
        }
    }
    
}

int main() {    
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    Jogador* jogadores = (Jogador *)calloc(n, sizeof(Jogador));
    if(jogadores == NULL) {
        printf("Ouve um erro na alocacao\n");
        exit(0);
    }

    for(int i = 0; i < n; i++) {
        ler(&jogadores[i]);
    }

    ordenacao(jogadores, n);

    for(int i = 0; i < n; i++) {
        printf("Nome: %s Eliminacoes: %d\n", jogadores[i].nome, jogadores[i].numeroDeEliminacoes);
    }

    free(jogadores);

    return 0;
}