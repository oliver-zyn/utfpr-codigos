#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemListaEnc.h"

struct jogo {
  int chave;
  char nome[100];
  char descricao[400];
  int faixaEtaria;
  char linkAcesso[100];
};

struct celula {
  Jogo jogo;
  Celula *prox;
};

struct lista {
  Celula *primeira;
};

Lista* criaListaVazia() {
  Lista *lst = malloc(sizeof(Lista));
  lst->primeira = NULL;
  return lst;
}

int verificaListaVazia(Lista *lst) {
  return lst->primeira == NULL;
}

Celula* buscaPorChave(Lista * lst, int chave) {
  Celula *aux = lst->primeira;
  while (aux != NULL && aux->jogo.chave != chave) {
    aux = aux->prox;
  }

  return aux;
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("\nChave: %d\n", aux->jogo.chave);
    printf("Nome: %s\n", aux->jogo.nome);
    printf("Descricao: %s\n", aux->jogo.descricao);
    printf("Faixa etaria: %d\n", aux->jogo.faixaEtaria);
    printf("Link de acesso: %s\n", aux->jogo.linkAcesso);
  }
}

void insereInicioLista(Lista *lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]) {
  Jogo novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.descricao, descricao);
  novo.faixaEtaria = faixaEtaria;
  strcpy(novo.linkAcesso, linkAcesso);
  Celula *nova = malloc(sizeof(Celula));
  nova->jogo = novo;
  nova->prox = lst->primeira;
  lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]) {
  Jogo novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.descricao, descricao);
  novo.faixaEtaria = faixaEtaria;
  strcpy(novo.linkAcesso, linkAcesso);
  Celula *nova = malloc(sizeof(Celula));
  nova->jogo = novo;
  nova->prox = NULL;
  if (verificaListaVazia(lst)) {
    lst->primeira = nova;
  } else {
    Celula *ultima;
    ultima = lst->primeira;
    while (ultima->prox != NULL) {
      ultima = ultima->prox;
    }

    ultima->prox = nova;
    
  }
}

void insereMeioLista(Lista *lst, int chave, int x, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]) {
  Celula *aux = buscaPorChave(lst, x);

  if (aux != NULL) {
    Jogo novo;
    novo.chave = chave;
    strcpy(novo.nome, nome);
    strcpy(novo.descricao, descricao);
    novo.faixaEtaria = faixaEtaria;
    strcpy(novo.linkAcesso, linkAcesso);
    Celula *nova = malloc(sizeof(Celula));
    nova->jogo = novo;
    nova->prox = aux->prox;
    aux->prox = nova;
  } else {
    printf("O item informado nao existe. \n");
  }
}

void removeItem(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  while (aux != NULL && aux->jogo.chave != x) {
    anterior = aux;
    aux = aux->prox;
  }

  if (aux == NULL) {
    printf("Item nao encontrado;");
    return;
  }

  if (aux == lst->primeira) {
    lst->primeira = aux->prox;
  } else {
    anterior->prox = aux->prox;
  }

  free(aux);
}

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

// FUNCOES EXERCICIO

void insere(Lista * lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]) {
  Celula *atual = lst->primeira;
  Celula *anterior = NULL;

  if (verificaListaVazia(lst)) {
    insereInicioLista(lst, chave, nome, descricao, faixaEtaria, linkAcesso);
    return;
  }

  while (atual != NULL && atual->jogo.faixaEtaria < faixaEtaria) {
    anterior = atual;
    atual = atual->prox;
  }

  if (anterior == NULL) {
    insereInicioLista(lst, chave, nome, descricao, faixaEtaria, linkAcesso);
  } else {
    insereMeioLista(lst, chave, anterior->jogo.chave, nome, descricao, faixaEtaria, linkAcesso);
  }
}

void removePorNome(Lista *lst, char nome[]) {
  Celula *aux = lst->primeira;

  while (aux != NULL) {
    if (strcmp(aux->jogo.nome, nome) == 0) {
      removeItem(lst, aux->jogo.chave);
      return;
    }
    aux = aux->prox;
  }

  printf("\nNenhum item foi encontrado!\n");
}

void imprime_jogo(Lista *lst, char nome[]) {
  Celula *aux = lst->primeira;
  int encontrou = 0;

  while (aux != NULL) {
    if (strstr(aux->jogo.nome, nome) != NULL) {
      printf("\nNome: %s\n", aux->jogo.nome);
      printf("Descricao: %s\n", aux->jogo.descricao);
      printf("Faixa Etaria: %d\n", aux->jogo.faixaEtaria);
      printf("Link de Acesso: %s\n", aux->jogo.linkAcesso);
      encontrou = 1;
    }
    aux = aux->prox;
  }

  if (!encontrou) {
    printf("\nNenhum jogo foi encontrado!\n");
  }
}