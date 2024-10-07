#include <stdio.h>
#include <stdlib.h>
#include "../include/pilhaEnc.h"

struct item {
  int chave;
  // demais campos
};

struct celula {
  Item item;
  Celula *prox;
};

struct pilha {
  Celula *topo;
};

Pilha * criaPilhaVazia() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

int verificaPilhaVazia(Pilha *p) {
  return p->topo == NULL;
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
  for(aux = p->topo; aux != NULL; aux = aux->prox) {
    printf("chave = %d\n", aux->item.chave);
  }
}

void desempilha(Pilha *p) {
  if (verificaPilhaVazia(p)) {
    printf("Erro: pilha vazia!\n");
    return;
  }
  Celula *remover = p->topo;
  p->topo = remover->prox;
  free(remover);
}

void liberaPilha(Pilha *p) {
  Celula *aux = p->topo;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(p);
}

