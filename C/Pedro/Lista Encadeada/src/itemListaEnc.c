#include <stdio.h>
#include <stdlib.h>
#include "itemListaEnc.h"

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista *criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista));
    lst->primeira = NULL;
    return lst;
}

int verificaListaVazia(Lista *lst) {
    return lst->primeira == NULL;
}

Celula* buscaPorChave(Lista *lst, int chave) {
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave) {
        aux = aux->prox;
    }
    return aux;
}

void imprimeLista(Lista *lst) {
    Celula *aux;
    for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
        printf("Chave: %d\n", aux->item.chave);
    }
}

// adiciona um elemento no inicio da lista
void insereInicioLista(Lista *lst, int chave) {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = lst->primeira;
    lst->primeira = nova;
}

// adiciona um elemento no fim da lista
void insereFimLista(Lista *lst, int chave) {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    if (verificaListaVazia(lst)) {
        lst->primeira = nova;
    } else {
        Celula *ultima;
        ultima = lst->primeira; // partindo da primeira celula percorre 
        while (ultima->prox != NULL) {
            ultima = ultima->prox;
        }
        ultima->prox = nova; // apos a ultima inserir a nova celula
    }
}

// adiciona um elemento no meio da lista
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x); // procura pela chave x
    if (aux != NULL) {
        Item novo;
        novo.chave = chave;
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = aux->prox;
        aux->prox = nova;
    } else {
        printf("O item informado nao existe!");
    }
}

void removeItem(Lista *lst, int x) {
    Celula *aux = lst->primeira;
    Celula *anterior;

    while (aux != NULL && aux->item.chave != x) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Item nao encontrado!");
        return;
    }

    if (aux == lst->primeira) {
        lst->primeira = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
}

//libera a memoria

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(lst);
}