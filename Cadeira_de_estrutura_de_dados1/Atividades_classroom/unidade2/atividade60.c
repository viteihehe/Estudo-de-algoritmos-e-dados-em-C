#include <stdio.h>

typedef struct{
    char nome [50];
    int HP;
} Monstro;

void ler(Monstro *m) {
    printf("Insira o nome:\n");
    scanf(" %s", m->nome);
    printf("Insira o hp:\n");
    scanf("%d", &m->HP);
}

int main() {
    int n;
    printf("Insira a quantidade de monstros:\n");
    scanf("%d", &n);

    Monstro monstros[n];

    for(int i = 0; i < n; i++) {
        ler(&monstros[i]);
    }

    int indiceMenor = 0;
    for(int i = 1; i < n; i++) {
        if(monstros[indiceMenor].HP > monstros[i].HP) {
            indiceMenor = i;
        }
    }

    printf("Alvo prioritario: %s ([HP] %d)\n", monstros[indiceMenor].nome, monstros[indiceMenor].HP);


    return 0;
}