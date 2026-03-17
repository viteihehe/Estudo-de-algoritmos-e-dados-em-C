//Inversor vetor
#include <stdio.h>

int inversor(int v[], int tam) {
    if(tam == 0) {
        return 1;
    }
    int temp = (*v);
    (*v) = *(v+(tam-1));
    *(v+(tam-1)) = temp;
     
    return inversor(v+1, tam-2);


}

int entrada(int v[], int tam) {
    return inversor(v, tam); 
}

int main() {

    int v [100];

    for(int i = 0; i < 100; i++) {
        v[i] = i+1;
    }

    int tam = sizeof(v)/sizeof(v[0]);

    entrada(v, tam);

    for(int i = 0; i < 100; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}