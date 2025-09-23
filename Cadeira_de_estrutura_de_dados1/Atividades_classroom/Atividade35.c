#include <stdio.h>

typedef struct 
{
    char nome[50];
    int valor_pontos;

} ItemColetavel;

int main() {
    ItemColetavel inventario[3];

    for(int i = 0; i < 3; i++) {
        printf("Insira o nome e o valor em pontos do item %d \n", i+1);
        scanf("%s %d", inventario[i].nome, &inventario[i].valor_pontos);

    }

        ItemColetavel mais_valioso = inventario[0];

        for(int i = 1; i < 3; i++) {
            if(mais_valioso.valor_pontos < inventario[i].valor_pontos) {
                 mais_valioso = inventario[i];
            }
        }

        printf("O item mais valioso coletado foi: [%s]", mais_valioso.nome);

    return 0;
}