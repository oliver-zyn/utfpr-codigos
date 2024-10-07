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

// 1. Escreva uma função que recebe 3 pilhas encadeadas, sendo que a primeira
// guarda n números inteiros e a segunda e a terceira estão vazias. A função deve
// preencher a segunda pilha com todos os números pares encontrados na
// primeira pilha, e deve preencher a terceira pilha com todos os números ímpares
// encontrados na primeira pilha.

void preenchePilhasParesImpares(Pilha *p1, Pilha *p2, Pilha *p3) {
  Celula *aux1;

  for(aux1 = p1->topo; aux1 != NULL; aux1 = aux1->prox) {
    if (aux1->item.chave % 2 == 0) {
      empilha(p2, aux1->item.chave);
    } else {
      empilha(p3, aux1->item.chave);
    }
  }
}