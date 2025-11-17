#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int pontuacao;
} Jogador;

int particao(int e, int d, Jogador v[]) {
    srand(time(NULL));
    int idx = e + (rand() % (d-e));
    Jogador temp = v[d];
    v[d] = v[idx];
    v[idx] = temp;

    Jogador pivo = v[d];
    int j = e-1;
    int i;
    for(i = e; i < d; i++) {
        if(v[i].pontuacao >= pivo.pontuacao) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    temp = v[j+1];
    v[j+1] = v[d];
    v[d] = temp;
    return j+1;
}

void quicksort(int i, int f, Jogador v[]) {
    if(i < f) {
        int p = particao(i, f, v);
        quicksort(i, p-1, v);
        quicksort(p+1, f, v);
    }
}

int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    Jogador v[n];

    for(int i = 0; i < n; i++) {
        printf("Insira o id do jogador %d:\n", i+1);
        scanf("%d", &v[i].id);
        printf("Insira a pontucao:\n");
        scanf("%d", &v[i].pontuacao);
    }

    quicksort(0, n-1, v);

    for(int i = 0; i < n; i++) {
        printf("ID: %d Pontucao: %d\n", v[i].id, v[i].pontuacao);
    }


    return 0;
}