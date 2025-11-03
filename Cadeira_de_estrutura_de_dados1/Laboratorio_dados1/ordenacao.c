#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand(time(NULL));
    printf("Insira a quantidade de ids:\n");
    scanf("%d", &n);
    int id[n];
    for(int i = 0; i < n; i++) {
        id[i] = (rand() % 30) +1;
    }
    int i, j;
    for(i = 0; i < n-1; i++) {
        int indMenor = i;
        for(j = i+1; j < n; j++) {
            if(id[j] < id[indMenor]) {
                indMenor = j;
            }
        } 
        int temp = id[i];
        id[i] = id[indMenor];
        id[indMenor] = id[i];
    }

    for(i = 0; i < n; i++) {
        printf("%d ", id[i]);
    }

    int novoElemento;
    printf("Insira um novo elemento:\n");
    scanf("%d", &novoElemento);

    for(i = n-1; i >= 0 && novoElemento < id[i]; i--) {
        id[i+1] = id[i];
    }
    id[i+1] = novoElemento;

     for(i = 0; i < n; i++) {
        printf("%d ", id[i]);
    }
}