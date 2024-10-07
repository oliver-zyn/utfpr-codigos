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

// 2. Escreva uma função para remoção de nós duplicados (com mesma chave) em
// uma pilha encadeada, manipulando apenas o topo. Uma pilha auxiliar pode ser
// utilizada. Exemplo:
// - Pilha inicial: 0, 1, 2, 2, 3, 4, 8, 9, 9
// - Pilha sem duplicados: 0, 1, 2, 3, 4, 8, 9

void insereItensNaoDuplicados(Pilha *p1, Pilha *p2) {
  Celula *aux1;
  Celula *aux2;

  for(aux1 = p1->topo; aux1 != NULL; aux1 = aux1->prox) {
    int chaveAtual = aux1->item.chave, duplicado = 0;

    if (verificaPilhaVazia(p2)) {
      empilha(p2, chaveAtual);
      continue;
    }

    for(aux2 = p2->topo; aux2 != NULL; aux2 = aux2->prox) {
      if (aux2->item.chave == chaveAtual) {
        duplicado = 1;
        break;
      }
    }

    if (duplicado != 1) {
      empilha(p2, chaveAtual);
    }
  }
}