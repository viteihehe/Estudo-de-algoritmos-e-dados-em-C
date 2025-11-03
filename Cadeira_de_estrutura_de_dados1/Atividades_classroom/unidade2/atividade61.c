#include <stdio.h>

int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);
    
    int pontuacao[n];

    int j, i;

    for(i = 0; i < n; i++) {
        printf("Insira o %d valor:\n", i+1);
        scanf("%d", &pontuacao[i]);
    }

    for( i = 0; i < n-1; i++) {
        int indiMenor = i;
          for( j = i+1; j < n; j++) {
            if(pontuacao[j] < pontuacao[indiMenor])
                indiMenor = j; 
          }
        int temp = pontuacao[i];
        pontuacao[i] = pontuacao[indiMenor];
        pontuacao[indiMenor] = temp;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", pontuacao[i]);
    }

    return 0;
}