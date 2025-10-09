#include <stdio.h>

typedef struct  {
    char nome [50];
    int potuacao;
} Jogador;

int main() {
    int n;

    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    Jogador v[n];

    for(int i = 0; i < n; i++) {
        printf("Insira o nome do %d jogador:\n", i+1);
        scanf(" %[^\n]s", v[i].nome);

        printf("Insira a pontuacao:\n");
        scanf("%d", &v[i].potuacao);
    }

    int maior = v[0].potuacao;
    int indice = 0;
    for(int i = 1; i < n; i++) {
        if(maior < v[i].potuacao) {
            maior = v[i].potuacao;
            indice = i;
        }
    }

    FILE *file = fopen("./highscore.txt", "w");
    fprintf(file, "Nome: %s, Potuacao: %d", v[indice].nome, maior);

    fclose(file);


    return 0;
}