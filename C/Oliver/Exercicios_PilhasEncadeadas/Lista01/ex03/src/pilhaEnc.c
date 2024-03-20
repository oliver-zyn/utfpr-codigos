#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pilhaEnc.h"

struct oliver {
  int chave;
  char nomeEmpresa[100];
  char areaAtuacao[100];
  float descontoAssociados;
};

struct celula {
  Oliver oliver;
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

void empilha(Pilha *p, int chave, char nomeEmpresa[], char areaAtuacao[], float descontoAssociados) {
  Oliver novo;
  novo.chave = chave;
  strcpy(novo.nomeEmpresa, nomeEmpresa);
  strcpy(novo.areaAtuacao, areaAtuacao);
  novo.descontoAssociados = descontoAssociados;
  Celula *nova = malloc(sizeof(Celula));
  nova->oliver = novo;
  nova->prox = p->topo;
  p->topo = nova;
}

void imprimePilha(Pilha *p) {
  Celula *aux;
  for(aux = p->topo; aux != NULL; aux = aux->prox) {
    printf("Chave = %d\n", aux->oliver.chave);
    printf("Nome da empresa = %s\n", aux->oliver.nomeEmpresa);
    printf("Area de atuacao = %s\n", aux->oliver.areaAtuacao);
    printf("Desconto para associados = %.0f%%\n", (aux->oliver.descontoAssociados * 100));
    printf("\n=============================\n\n");
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