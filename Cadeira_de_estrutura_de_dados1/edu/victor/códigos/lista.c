#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Lista;

void inserir_inicio(Lista *l, int valor) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void mostrar(Lista l) {
    if(l.inicio == NULL) {
        printf("A lista esta vazia\n");
    }else {
        No * temp;
        for(temp = l.inicio; temp != NULL; temp = temp->prox) {
            printf("%d ", temp->dado);
        }
        printf("\n");
    }
}

void inserir_fim(Lista *l, int valor) {
    No * novo = (No *)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    if(l->inicio == NULL) {
        l->inicio = novo;
    }else {
        No * temp;
        for(temp = l->inicio; temp->prox != NULL; temp = temp->prox);
        temp->prox = novo;
    }
}

int particao(int e, int d, int v[]) {
    srand(time(NULL));
    int idx = e+(rand() % (d-e));
    int temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;

    int i;
    int j = e-1;
    int pivo = v[d];
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
        quicksort(p+1, f, v);
        quicksort(i, p-1, v);
    }
}

int tamanho(Lista *l) {
    if(l->inicio == NULL) {
        return 0;
    }else {
        int cont = 0;
        No * temp;
        for(temp = l->inicio; temp != NULL; temp = temp->prox) {
            cont++;
        }
        return cont;
    }
}

int intercala(int inicio, int meio, int fim) {
    int n1 = (meio-inicio)+1;
    int n2 = (fim-meio);
    int e[n1];
    int d[n2];

    int i, j;

    for(i = 0; i < meio; i++) {
        
    }
}

void ordenar(Lista *l) {
    int tam = tamanho(l);
    int inicio = 0;
    int fim = tam-1;
    int v[tam];

    No * temp = l->inicio;
    for(int i = inicio; i < tam; i++) {
        v[i] = temp->dado;
        temp = temp->prox;
    }

    quicksort(inicio, fim, v);

    temp = l->inicio;
    for(int i = inicio; i < tam; i++) {
       temp->dado = v[i];
       temp = temp->prox;
    }
    
    
}

void menu() {
    printf("==========================================\n");
    printf("1: Inserir item no inicio da fila\n");
    printf("2: inserir item no final da fila\n");
    printf("3: Mostrar fila\n");
    printf("4: Ordenar\n");
    printf("5: Sair\n");
    printf("==========================================\n");
}

int main() {
    srand(time(NULL));
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    int aux;

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                aux = (rand() % 100)+1;
                inserir_inicio(&lista, aux);
                break;
            case 2:
                aux = (rand() % 100)+1;
                inserir_fim(&lista, aux);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                ordenar(&lista);
                break;
            case 5:
                op = 0;
                break;

            default:
                op = 1;
                break;
        }
    }
}