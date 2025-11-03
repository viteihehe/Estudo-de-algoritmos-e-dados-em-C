#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    int i,j;
    int* jogadores = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        printf("Insira a pontuacao:\n");
        scanf("%d", &jogadores[i]);
    }

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(jogadores[j] > jogadores[j+1]) {
                int temp = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d ", jogadores[i]);
    }

    free(jogadores);
}