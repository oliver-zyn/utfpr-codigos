#include <stdio.h>
#include <stdlib.h>
#include "../include/PilhaEnc.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct pilha {
    Celula *topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilha(Pilha *p, int chave) {
    Item novo;
    novo.chave = chave;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = p->topo;
    p->topo = nova;
}

void imprimePilha(Pilha *p) {
    Celula *aux;
    for (aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("Chave: %d\n", aux->item.chave);
    }
}

int verificaPilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: pilha vazia!");
    }
    Celula *remover = p->topo;
    p->topo = remover->prox;
    free(remover);
}

void liberaPilha(Pilha *p) {
    Celula *aux = p->topo;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(p);
}

void parImpar(Pilha *p1, Pilha *pP, Pilha *pI) {
    Celula *aux1;

    for (aux1 = p1->topo; aux1 != NULL; aux1 = aux1->prox) {
        if(aux1->item.chave % 2 == 0) {
            empilha(pP, aux1->item.chave);
        } else {
            empilha(pI, aux1->item.chave);
        }
    }
}

void semDuplicadas(Pilha *p1, Pilha *p2) {
    Celula *aux;
    Celula *aux1;
    
    for (aux = p1->topo; aux != NULL; aux = aux->prox) {
        int chaveAtual = aux->item.chave, duplicata = 0;

        if (verificaPilhaVazia(p1)) {
            printf("Erro!");
        }

        if (verificaPilhaVazia(p2)) {
            empilha(p2, chaveAtual);
        }

        for (aux1 = p2->topo; aux1 != NULL; aux1 = aux1->prox) {
            if(aux1->item.chave == chaveAtual) {
                duplicata = 1;
                break;      
            }
        }

        if (duplicata != 1) {
            empilha(p2, chaveAtual);
        }
    }
}

