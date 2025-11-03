#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
    printf("=====================\n");
    printf("1 - Buscar livro\n");
    printf("2 - Quantidade de livros pares\n");
    printf("3 - calculo de evolucao da multa\n");
    printf("========================\n");
    printf("Escolha uma opcao:\n");
}

int buscaRecusiva(int inicio, int fim, int v[], int indice) {
    if(inicio > fim) {
        return -1;
    }
    int meio = (inicio+fim)/2;
    if(v[meio] < indice) {
        return buscaRecusiva(meio+1, fim, v, indice);
    }
    if(v[meio] > indice) {
        return buscaRecusiva(inicio, meio-1, v, indice);
    }
    if(v[meio] == indice) {
        return meio;
    }
    return -1;
}

int main() {
    int n;
    srand(time(NULL));
    printf("Insira o tamanho do vetor:\n");
    scanf("%d", &n);
    int *v = (int *)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) {
        v[i] = rand() % 20 + 1;
    }
    
    int i, j;

    

    for( i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

while(1) {


    int op;
    menu();
    scanf("%d", &op);

    switch (op) {
        case 1:
            int id;
            printf("Insira o id que deseja buscar:\n");
            scanf("%d", &id);
            int r = buscaRecusiva(0, n-1, v, id);
            if(r != -1) {
                printf("Id encontrado! Indice %d\n", r);
            }else{
                printf("Id nao existente!\n");
            }
            break;
        case 2:
            int quantidadePares = contadorPar(v, n);
            if(quantidadePares != -1) {
                printf("Total de numero pares: %d\n", quantidadePares);
            }else{
                printf("A biblioteca nao possui livro catalogados!\n");
            }
            break;
        case 3:
            break;
        default:
            printf("Opcao invalida\n");
            exit(0);
            break;

        
        }
   
    }


    return 0;
}