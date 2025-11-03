#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome [50];
    int hp;
    int ataque;
} Monstro;

int busbaBinariaRecursiva( int inicio, int fim, Monstro monstro[], int id) {
    if(inicio > fim) {
        return -1;
    }
    int meio = (inicio+fim)/2;
    if(monstro[meio].id == id) {
        return meio;
    }
    if(monstro[meio].id < id) {
        return busbaBinariaRecursiva(meio+1, fim, monstro, id);
    }else {
        return busbaBinariaRecursiva(inicio, meio-1, monstro, id);
    }
}

int main() {
    int n, loop = 1, temp = 0;
    printf("Insira a quantidade de monstros:\n");
    scanf("%d", &n);

    Monstro *monstro = (Monstro *)malloc(n*sizeof(Monstro));

    for(int i = 0; i < n; i++) {
        printf("Insira o nome do monstro %d:\n", i+1);
        scanf(" %[^\n]s", monstro[i].nome);
        printf("Insira o atk e o hp:\n");
        scanf("%d %d", &monstro[i].ataque, &monstro[i].hp);
        monstro[i].id = ++temp;
    } 
    while(loop != 0) {
        printf("Insira o id desejado:\n");
        scanf("%d", &loop);
        int id = busbaBinariaRecursiva(0, n-1, monstro, loop);
        if(id != -1) {
            printf("Monstro Encontrado: %s, (ID: %d) - HP: %d, Ataque: %d\n", monstro[id].nome, monstro[id].id, monstro[id].hp, monstro[id].ataque);
        }else{
            printf("Monstro com ID %d nao encontrado.\n", loop);
        }
    }


    return 0;
}