#include <stdio.h>

typedef struct{
    int ID;
    int pontuacao;
} Jogador;

void ler(Jogador* jogador) {
    printf("Insira o id:\n");
    scanf("%d", &jogador->ID);
    printf("Insira a pontuacao:\n");
    scanf("%d", &jogador->pontuacao);
}

void bubbleSort(Jogador jogadores[], int n) {
    for(int i = 0; i < n-1; i++) {
        int trocou = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(jogadores[j].ID < jogadores[j+1].ID) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = temp;
                trocou = 1;
            }
        }
        if(!trocou) {
            return;
        }
    }
}

int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    Jogador jogadores[n];
    for(int i = 0; i < n; i++) {
        ler(&jogadores[i]);
    }

    bubbleSort(jogadores, n);

    for(int i = 0; i < n; i++) {
        printf("ID: %d, Pontuacao: %d\n", jogadores[i].ID, jogadores[i].pontuacao);
    }

    return 0;
}