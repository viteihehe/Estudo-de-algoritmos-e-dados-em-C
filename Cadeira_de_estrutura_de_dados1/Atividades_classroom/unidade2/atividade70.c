#include <stdio.h>

int sistemaBusca(int inicio, int fim, int v[]) {
    if(inicio < fim) {
        int meio = (inicio+fim)/2;
        int e = sistemaBusca(inicio, meio, v);
        int e1 = sistemaBusca(meio+1, fim, v);
        if(e > e1) {return e;
        } else {return e1;}
    }
    return v[inicio];
}

int main() {
    int n;
    printf("Insira a quantidade Fragmentos de Alma:\n");
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int valor_maximo = sistemaBusca(0, n-1, v);
    printf("Valor máximo encontrado: %d\n", valor_maximo);

    return 0;
}