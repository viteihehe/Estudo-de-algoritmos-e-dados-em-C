#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particao(int e, int d, int v[]) {
    srand(time(NULL));
    int idx = e+(rand() % (d-e));
    int temp = v[d];
    v[d] = v[idx];
    v[idx] = temp;

    int pivo = v[d];
    int j = e-1;
    int i;
    for(i = e; i < d; i++) {
        if(v[i] <= pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    temp = v[j+1];
    v[j+1] = v[d];
    v[d] = temp;
    return j+1;
}

void quicksort(int i, int f, int v[]) {
    if(i < f) {
        int p = particao(i, f, v);
        quicksort(i, p-1, v);
        quicksort(p+1, f, v);
    }
}

void intercalar(int inicio, int m, int f, int v[]) {
    int n1 = (m-inicio)+1;
    int n2 = (f-m);
    int a[n1], b[n2];
    int k = inicio;
    int i, j;
    for(i = 0; i < n1; i ++) {
        a[i] = v[inicio+i];
    }
    for(j = 0; j < n2; j++) {
        b[j] = v[m+1+j];
    }

    i=0;
    j=0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            v[k] = a[i];
            i++;
        }else {
            v[k] = b[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        v[k] = a[i];
        k++;
        i++;
    }

    while(j < n2) {
        v[k] = b[j];
        j++;
        k++;
    }

}

void mergesort(int i, int f, int v[]) {
    int m = (i+f)/2;
    mergesort(i, m, v);
    mergesort(m+1, f, v);
    intercalar(i, m, f, v);
}

int main() {
    int v[] = {5, 6, 3, 2,1, 7, 9};

    quicksort(0, 6, v);

    for(int i = 0; i < 7; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
