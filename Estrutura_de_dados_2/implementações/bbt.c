//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Criação da struct base da árvore
typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

//Declaração dos protótipos das funções
No *inserir(No *, int);
int isempty(No *);
int altura(No *);
int maior(int a, int b);
void in_ordem(No *raiz);
No *remover(No *, int);
No *busca(No *, int);
No *sucessor(No *);
No *inserir_No(No *, No *);

int main() {

    srand(time(NULL));
    No * raiz = NULL;

    int v [10];
    for(int i = 0; i < 10; i++) {
        v[i] = (rand() % 19)+1;
    }
    for(int i = 0; i < 10; i++) {
        raiz = inserir(raiz, v[i]);
    }
    printf("Altura árvore: %d\n", altura(raiz));
    in_ordem(raiz);
    printf("\n");

    return 0;
}

int isempty(No *raiz) {
    if(raiz == NULL) {
        return 1;
    }
    return 0;
}

No *inserir(No *raiz, int valor) {
    if(isempty(raiz)) {
        No * novo_no = (No*)malloc(sizeof(No));
        novo_no->valor = valor;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    if(valor <= raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    
    return raiz;
}

int maior(int a, int b) {
    if(a > b) return a;
    return b;
}

int altura(No *atual) {
    if(!isempty(atual)) {
        return maior(altura(atual->esq), altura(atual->dir))+1;
    }
    return -1;
}

void in_ordem(No *raiz) {
    if(!isempty(raiz)) {
        in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->dir);
    }
    
}


No *busca(No *raiz, int valor) {
    if(!isempty(raiz)) {
        if(raiz->valor == valor) {
            return raiz;
        }
        if(valor < raiz->valor) {
            return busca(raiz->esq, valor);
        }
        else {
            return busca(raiz->dir, valor);
        }
    }
    return raiz;
}

No *sucessor(No *raiz) {
    if(!isempty(raiz)) {
        if(raiz->dir != NULL && raiz->dir->esq != NULL) {
            No *pivo;
            for(pivo = raiz->dir; raiz->esq != NULL; pivo = raiz->esq);
            return pivo;
        } else {
            printf("Não é possivel pegar um valor maior que esse! \n");
        }
    }
    return NULL;
}

No *inserir_No(No *destino, No *origem) {
    if(isempty(destino)) {
        return origem;
    }
    if(origem->valor <= destino->valor) {
        destino->esq = inserir_No(destino->esq, origem);
    }
    else {
        destino->dir = inserir_No(destino->dir, origem);
    }
    return destino;
}

No *remover(No *atual, int valor) {
    if(!isempty(atual)) {
        if(valor < atual->valor) {
            atual->esq = remover(atual->esq, valor);
        }
        else if(valor > atual->valor) {
            atual->dir = remover(atual->dir, valor);
        }
        else {
            if(atual->dir == NULL && atual->esq == NULL) {
                free(atual);
                return NULL;
            }
            if(atual->dir != NULL && atual->esq != NULL) {
                No *pivo = sucessor(atual);
                atual->valor = pivo->valor;
                atual->dir = remover(atual->dir, pivo->valor);
                return atual;
            }
            if(atual->esq != NULL) {
                No *filho = atual->esq;
                free(atual);
                return filho;
            } 
            if(atual->dir != NULL) {
                No *filho = atual->esq;
                free(atual);
                return filho;
            }
        }
    }
    return NULL;
}

