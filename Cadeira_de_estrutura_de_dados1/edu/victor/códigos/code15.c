#include <stdio.h>

int buscabinaria(int inicio, int fim, int id, int v[]) {
    while(inicio <= fim) {
        int meio = (inicio+fim)/2;
        if(id == v[meio]) {
            return 1;
        }
        if(v[meio] < id) {
            inicio = meio+1;
        }
        if(v[meio] > id) {
            fim = meio -1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Insira o tamanho da lista:\n");
    scanf("%d", &n);

    int lista1[n];
    int lista2[n];
    int lista3[n];
    for(int i = 0 ; i < n; i++) {
        lista1[i] = i+1;
        lista2[i] = i*2;
        lista3[i] = i*3;
    }
    
        for(int j = 0; j < n; j++) {
            printf("%d ", lista1[j]);
        }
        printf("\n");
        for(int j = 0; j < n; j++) {
            printf("%d ", lista2[j]);
        }
        printf("\n");
        for(int j = 0; j < n; j++) {
            printf("%d ", lista3[j]);
        }
        printf("\n");

        for(int j = 0; j < n; j++) {
            int cont = 0;
            cont += buscabinaria(0, n, lista1[j], lista1); 
            cont += buscabinaria(0, n, lista1[j], lista2); 
            cont += buscabinaria(0, n, lista1[j], lista3); 
           
            if(cont == 3) {
                printf("%d ", lista1[j]);
            }
        }
    
    return 0;
}