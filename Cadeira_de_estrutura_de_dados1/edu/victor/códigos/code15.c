#include <stdio.h>

int intercala(int inicio, int meio, int fim, int v[]) {
    int n1 = (meio-inicio)+1;
    int n2 = (fim-meio);
    int E[n1];
    int D[n2];
    int k = inicio;
    int i, j;

    for(i = 0; i < n1; i++) {
        E[i] = v[inicio+i];
    }
    for(j = 0; j < n2; j++) {
        D[j] = v[meio+1+j];
    }
    int total_invercoes = 0;
    i=0;
    j=0;

    while(i < n1 && j < n2) {
        if(E[i] < D[j]) {
            v[k] = E[i];
            i++;
        } else {
            v[k] = D[j];
            j++;
            total_invercoes += (n1-i);
        }
        k++;
    }

    while(i < n1) {
        v[k] = E[i];
        k++;
        i++;
    }

    while(j < n2) {
        v[k] = D[j];
        k++;
        j++;
    }

    return total_invercoes;
}

int mergesort(int i, int f, int v[]) {
    if(i < f) {
        int m = (i+f)/2;
        int ai = mergesort(i, m, v );
        int bi = mergesort(m+1, f, v );
        int temp = intercala(i, m, f, v);
        return temp+ai+bi;
    }
    return 0;
}


int main() {
    printf("Sistema de recomendacao:\n");
    int v[] = {3, 1, 2, 4, 5};

    int temp = mergesort(0, 4, v);

    printf("Total de inverC'C5es: %d\n", temp);


    return 0;
}