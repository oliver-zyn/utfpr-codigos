#include <stdio.h>
#include <stdlib.h>
#include "../include/itemFilaEnc.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct fila {
    Celula *ini;
    Celula *fim;
};

Fila *criaFilaVazia() {
    Fila *f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int verificaFilaVazia(Fila *f) {
    return f->ini == NULL;
}

void enfileira(Fila *f, int chave) {
    Item novo_item;
    novo_item.chave = chave;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo_item;
    nova->prox = NULL;

    if(verificaFilaVazia(f)) {
        f->ini = nova;
    } else {
        f->fim->prox = nova;
    }
    f->fim = nova;
}

void imprimeFila(Fila *f) {
    Celula *aux = f->ini;

    while(aux != NULL) {
        printf("Chave: %d\n", aux->item.chave);
        aux = aux->prox;
    }
}

void desenfleira(Fila *f) {
    if(verificaFilaVazia(f)) {
        printf("Erro, fila vazia!");
        return;
    }
    Celula *remover = f->ini;
    f->ini = remover->prox;
    free(remover);
    if(verificaFilaVazia(f)) {
        f->fim = NULL;
    }
}

void liberaFila(Fila *f) {
    Celula *aux = f->ini;
    Celula *liberar;

    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(f);
}

// Ex1

 int verificaFilaOrdenada(Fila *f) {
  int ordenada = 1, anterior = 0, primeiroNum = 1;
  Celula *aux = f->ini;

  if (verificaFilaVazia(f)) {
    printf("A fila esta vazia!");
    return -1;
  }

  while(aux != NULL) {
    if (primeiroNum == 1) {
      anterior = aux->item.chave;
      primeiroNum = 0;
      continue;
    }

    if (aux->item.chave < anterior) {
      ordenada = 0;
      break;
    }
    
    anterior = aux->item.chave;
    aux = aux->prox;
  }

  return ordenada;
} 