#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
} Lista;



void inserir_inicio(Lista *lista, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void inserir_final(Lista *lista, int dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *temp;
        for (temp = lista->inicio; temp->prox != NULL; temp = temp->prox);
        temp->prox = novo;
    }
}

void remover_inicio(Lista *lista)
{
    if (lista->inicio == NULL)
    {
        printf("A lista esta vazia \n\a");
    }
    else
    {
        No *temp = lista->inicio;
        lista->inicio = temp->prox;
        free(temp);
    }
}

void remover_final(Lista *lista)
{
    if (lista->inicio == NULL)
    {
        printf("A lista esta vazia\n");
    }
    else if (lista->inicio->prox == NULL) 
    {
       remover_inicio(lista);
    }else {
         No *temp;
        No *temp2;
        for (temp = lista->inicio; temp->prox->prox != NULL; temp = temp->prox);
        temp2 = temp->prox;
        temp->prox = NULL;
        free(temp2);
    }
}

No *pesquisar(Lista *lista, int id)
{
    No *pi;
    No *pj;
    for (pi = lista->inicio; pi->dado != id && pi != NULL; pi = pi->prox)
    {
        pj = pi;
    }
    return pj;
}

void remover_no_id(Lista *lista, int id)
{
    if (lista->inicio == NULL)
    {
        printf("A lista esta vazia!\n");
    }
    else
    {
        No *temp = pesquisar(lista, id);
        No *remover = temp->prox;
        temp->prox = remover->prox;
        free(remover);
    }
}

void mostrar(Lista lista) {
    if(lista.inicio == NULL) {
        printf("A lista esta vazia\n");
    }else {
        No* temp;
        printf("==================================================\n");
        for(temp = lista.inicio; temp != NULL; temp = temp->prox) {
            printf("Valor: %d\n", temp->dado);
        }
        printf("==================================================\n");
    }
}

int tamanho_lista(Lista* lista) {
    int cont = 0;
    if(lista->inicio == NULL) {
        return cont;
    }else {
        for(No* temp = lista->inicio; temp != NULL; temp = temp->prox) {
            cont++;
        }
        return cont;
    }
}



int particao(int e, int d, int v[]) {
    srand(time(NULL));
    int idx = e+(rand() % (d-e));
    int temp = v[idx];
    v[idx] = v[d];
    v[d] = temp;

    int j = e-1;
    int i;
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


void quick_sort(int i, int f, int v[]) {
    if(i < f) {
        int p = particao(i, f, v);
        quick_sort(p+1, f, v);
        quick_sort(i , p-1, v);
    }
}

void ordenar(Lista *l) {
    int tamanho = tamanho_lista(l);
    int e = 0;
    int d = tamanho-1;
    int v [tamanho];

    No* aux = l->inicio;
    for(int i = 0; i < tamanho; i++) {
        v[i] = aux->dado;
        aux = aux->prox;
    }

    quick_sort(e, d, v);

    aux = l->inicio;

    for(int i = 0; i < tamanho; i++) {
        aux->dado = v[i];
        aux = aux->prox;
    }


}

void menu() {
    printf("==========================================\n");
    printf("1: Inserir item no inicio da fila\n");
    printf("2: inserir item no final da fila\n");
    printf("3: Mostrar fila\n");
    printf("4: Ordenar\n");
    printf("5: Remover inicio\n");
    printf("6: Remover fim\n");
    printf("7: Remover por id\n");
    printf("8: Sair\n");
    printf("==========================================\n");
}

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op = 1;
    int temp;
    srand(time(NULL));

    while(op) {
        menu();
        scanf("%d", &op);

        switch (op) {
            case 1:
                temp = (rand() % 100)+1;
                inserir_inicio(&lista, temp);
                break;
            case 2:
                temp = (rand() % 100)+1;
                inserir_final(&lista, temp);
                break;
            case 3:
                mostrar(lista);
                break;
            case 4:
                ordenar(&lista);
                break;
            case 5: 
                remover_inicio(&lista);
                break;
            case 6:
                remover_final(&lista);
                break;
            case 7:
                int id;
                printf("Insira o valor:\n");
                scanf("%d", &id);
                remover_no_id(&lista, id);
                break;
            case 8:
                op = 0;
                break;
            

            default:
                op = 1;
                break;
        }
    }


    return 0;
}