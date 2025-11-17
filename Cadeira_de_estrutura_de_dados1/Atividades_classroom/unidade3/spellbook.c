#include "spellbook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Spellbook* create_spellbook() {
    Spellbook* lista = (Spellbook *)malloc(sizeof(Spellbook));
    lista->inicio = NULL;
    return lista;
}

void add_spell(Spellbook * book, int id, const char* name, int mana_cost) {
    No *novo = (No *)malloc(sizeof(No));
    novo->dado.id = id;
    strcpy(novo->dado.name, name);
    novo->dado.mana_const = mana_cost;
    novo->prox = NULL;
    if(book->inicio == NULL) {
        book->inicio = novo;
    }else {
        No * temp;
        for(temp = book->inicio; temp->prox != NULL; temp = temp->prox);
        temp->prox = novo;
    }
}
void display_spellbook(Spellbook* book) {
    if(book->inicio == NULL) {
        printf("O livro esta vazio!\n");
    }else {
        No * temp;
        for(temp = book->inicio; temp != NULL; temp = temp->prox) {
            printf("ID: %d, Feitico: %s, Custo de Mana: %d\n", temp->dado.id, temp->dado.name, temp->dado.mana_const);
        }
    }
}
void destroy_spellbook(Spellbook* book) {
    if(book->inicio == NULL) {
        printf("A lista esta vazia!\n");
    }else {
        No * temp;
        while(book->inicio != NULL) {
            temp = book->inicio;
            book->inicio = temp->prox;
            free(temp);
        }
        
    }
}