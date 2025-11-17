#include <stdio.h>

int particao(int n, int v[]) {
    int pivo = v[n-1];
    int j = -1;
    int i;
    for(i = 0; i < n-1; i++) {
        if(v[i] < pivo) {
            j++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[j+1];
    v[j+1] = v[n-1];
    v[n-1] = temp;
}


int main() {
    int n;
    printf("Insira a quantidade de mechas:\n");
    scanf("%d", &n);

    int mechas[n];

    for(int i = 0; i < n; i++) {
        printf("Insira a quantidade de hp do mecha %d:\n", i+1);
        scanf("%d", &mechas[i]);
    }

    particao(n, mechas);

    for(int i = 0 ; i < n; i++) {
        printf("%d ", mechas[i]);
    }

    return 0;
}