#include <stdio.h>

typedef struct {
    char nome [50];
    int posicao;
} Piloto;

void intercalar(int inicio, int meio, int fim, Piloto v[]) {
    int tamanho1 = (meio-inicio)+1;
    int tamanho2 = (fim - meio);
    int temp = inicio;
    Piloto E[tamanho1];
    Piloto D[tamanho2];

    int i, j;
    for(i = 0; i < tamanho1; i++) {
        E[i] = v[inicio+i];
    }
    for(j = 0; j < tamanho2; j++) {
        D[j] = v[meio+1+j];
    }
    i = 0;
    j = 0;

    while(i < tamanho1 && j < tamanho2) {
        if(E[i].posicao < D[j].posicao) {
            v[temp] = E[i];
            i++;
        }else{
            v[temp] = D[j];
            j++;
        }
        temp++;
    }

    while(i < tamanho1) {
        v[temp] = E[i];
        i++;
        temp++;
    }

    while(j < tamanho2) {
        v[temp] = D[j];
        j++;
        temp++;
    }

}

void merger_sort(int inicio, int fim, Piloto v[]) {
    if(inicio < fim) {
        int meio = (inicio+fim)/2;
        merger_sort(inicio, meio, v);
        merger_sort(meio+1, fim, v);
        intercalar(inicio, meio, fim, v);
    }
}


int main() {
    int n;
    printf("Insira o total de corredores:\n");
    scanf("%d", &n);

    Piloto pilotos[n];
    for(int i = 0; i < n; i++) {
        printf("Insira o nome do piloto %d:\n", i+1);
        scanf(" %[^\n]s", pilotos[i].nome);
        printf("Insira sua posicao final:\n");
        scanf("%d", &pilotos[i].posicao);
    }

    merger_sort(0, n-1, pilotos);

    for(int i = 0; i < n; i++) {
        printf("Posicao: %d Nome: %s\n", pilotos[i].posicao, pilotos[i].nome);
    }


    return 0;
}