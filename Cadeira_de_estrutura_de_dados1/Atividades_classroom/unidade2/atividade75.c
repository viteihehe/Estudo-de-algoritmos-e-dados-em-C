#include <stdio.h>

int particao(int e, int d, int v[]) {
    int pivo = v[d];
    int j = e-1;
    int i;

    for(int i = e; i < d; i++) {
        if(v[i] <= pivo) {
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[d];
    v[d] = v[j+1];
    v[j+1] = temp;
    return j+1;
}

void quicksort(int inicio, int fim, int v[]) {
    if(inicio < fim) {
        int p = particao(inicio, fim, v);
        quicksort(inicio, p-1, v);
        quicksort(p+1, fim, v);
    }
}


int main() {
    int n;
    printf("Insira a quantidade de jogadores:\n");
    scanf("%d", &n);

    int v[n];

    for(int i = 0; i < n; i++) {
        printf("Insira o MMRs do jogador %d:\n", i+1);
        scanf("%d", &v[i]);
    }

    quicksort(0, n-1, v);

    for(int i = 0 ; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}