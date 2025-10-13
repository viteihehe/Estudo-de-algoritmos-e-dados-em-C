#include <stdio.h>

typedef struct {
    char nome [50];
    int HP;
} Inimigo;

int main() {
    int n;
    printf("Insira o numero de unidades:\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        Inimigo inimigo;
        printf("Insira o nome e o HP:\n");
        scanf(" %s %d", inimigo.nome, &inimigo.HP);
        printf("Inimigo: %s, HP: %d\n", inimigo.nome, inimigo.HP);
    }


    return 0;
}