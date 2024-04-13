#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemFilaEnc.h"

struct data {
  int dia;
  int mes;
  int ano;
};

struct oliver {
  int idAtleta;
  Data dataRegistro;
  float kmPercorridos;
  char rota[100];
};

struct celula {
  Oliver corrida;
  Celula *prox;
};

struct fila {
  Celula *ini;
  Celula *fim;
};


Fila * criaFilaVazia() {
  Fila *f = malloc(sizeof(Fila));
  f->ini = NULL;
  f->fim = NULL;
  return f;
}

int verificaFilaVazia(Fila *f) {
  return f->ini == NULL;
}

void enfileira(Fila *f, int idAtleta, int dia, int mes, int ano, float kmPercorridos, char rota[]) {
  Oliver novoItem;
  novoItem.idAtleta = idAtleta;
  novoItem.dataRegistro.dia = dia;
  novoItem.dataRegistro.mes = mes;
  novoItem.dataRegistro.ano = ano;
  novoItem.kmPercorridos = kmPercorridos;
  strcpy(novoItem.rota, rota);
  Celula *nova = malloc(sizeof(Celula));
  nova->corrida = novoItem;
  nova->prox = NULL;
  if (verificaFilaVazia(f)) {
    f->ini = nova;
  } else {
    f->fim->prox = nova;
  }
  f->fim = nova;
}

void desenfileira(Fila *f) {
  if (verificaFilaVazia(f)) {
    printf("Erro: a fila esta vazia.\n");
    return;
  }
  Celula *remover = f->ini;
  f->ini = remover->prox;
  free(remover);
  if (verificaFilaVazia(f)) {
    f->fim = NULL;
  }
}

void liberaFila(Fila *f) {
  Celula *aux = f->ini;
  Celula *liberar;
  while(aux != NULL) {
    liberar = aux;
    aux = aux->prox;
    free(liberar);
  }
  free(f);
}

void imprimeFila(Fila *f) {
  Celula *aux = f->ini;

  while (aux != NULL) {
    Data dataRegistro = aux->corrida.dataRegistro;

    printf("\nIdentificacao do atleta: %d\n", aux->corrida.idAtleta);
    printf("Data do registro: %d/%d/%d\n", dataRegistro.dia, dataRegistro.mes, dataRegistro.ano);
    printf("Quilometros percorridos: %.2f\n", aux->corrida.kmPercorridos);
    printf("Rota: %s\n", aux->corrida.rota);
    aux = aux->prox;
  }
}

// FUNCOES PROVA

float calculaTotalKmPercorridosMes(Fila * f, int mes) {  
  Celula *aux = f->ini;
  float kmTotal = 0;

  if (verificaFilaVazia(f)) {
    printf("Erro: a fila esta vazia.\n");
    return -1;
  }

  while (aux != NULL) {
    Data dataRegistro = aux->corrida.dataRegistro;

    if (dataRegistro.mes == mes || mes == 0) {
      kmTotal += aux->corrida.kmPercorridos;
    }

    aux = aux->prox;
  }

  return kmTotal;
}