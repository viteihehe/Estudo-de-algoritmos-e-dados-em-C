#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    struct No *esq;
    struct No *dir;
    int valor;
} No;

No *criar_no(int);
No *inserir(No*, int);
No *buscar(No*, int);
void in_ordem(No*);
int altura(No*);
int maior(int a, int b);

int main() {
    No *raiz = criar_no(50);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 80);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 90);
    in_ordem(raiz);
    printf("ALtura: %d\n", altura(raiz));
    No *ret = buscar(raiz, 100);
    if(ret == NULL) {
        printf("O valor não existe, ou a árvore está vazia!\n");
    } else {
        printf("Valor buscado: %d\n", ret->valor);
    }

    return 0;
}

No *criar_no(int valor) {
    No *novo_no = (No*)malloc(sizeof(No));
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    novo_no->valor = valor;
    return novo_no;
}

No *inserir(No *raiz, int valor) {
    if(raiz == NULL) {
        raiz = criar_no(valor);
        return raiz;
    }
    if(valor <= raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if(valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void in_ordem(No *raiz) {
    if(raiz == NULL) return;
    in_ordem(raiz->esq);
    printf("%d \n", raiz->valor);
    in_ordem(raiz->dir);
}

int altura(No* raiz) {
    if(raiz == NULL) return -1;
    return maior(altura(raiz->esq), altura(raiz->dir))+1;
}
int maior(int a, int b) {
    return a > b ? a : b;
}

No *buscar(No *raiz, int valor) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->valor == valor) {
        return raiz;
    }
    if(valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }
    else if(valor > raiz->valor) {
        return buscar(raiz->dir, valor);
    }

    return raiz;
}
