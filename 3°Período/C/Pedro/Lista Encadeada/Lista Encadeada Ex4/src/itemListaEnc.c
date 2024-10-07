#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemListaEnc.h"

struct Pedro {
  int chave;
  char nome[50];
  char telefone[20];
  char email[30];
};

struct celula {
  Pedro pessoa;
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
  while (aux != NULL && aux->pessoa.chave != chave) {
    aux = aux->prox;
  }

  return aux;
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("Chave: %d\n", aux->pessoa.chave);
    printf("Nome: %s\n", aux->pessoa.nome);
    printf("Telefone: %s\n", aux->pessoa.telefone);
    printf("Email: %s\n", aux->pessoa.email);
  }
}

void insereInicioLista(Lista *lst, int chave, char nome[], char telefone[], char email[]) {
  
  Pedro novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.telefone, telefone);
  strcpy(novo.email, email);
  
  Celula *nova = malloc(sizeof(Celula));

  nova->pessoa = novo; 
  nova->prox = lst->primeira;
  
  lst->primeira = nova;
}


void insereFimLista(Lista *lst, int chave, char nome[], char telefone[], char email[]) {
  
  Pedro novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.telefone, telefone);
  strcpy(novo.email, email);
  
  Celula *nova = malloc(sizeof(Celula));

  nova->pessoa = novo;
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

void insereMeioLista(Lista *lst, int chave, char nome[], char telefone[], char email[], int x) {
  Celula *aux = buscaPorChave(lst, x); 

  if (aux != NULL) {
    
    Pedro novo;
    novo.chave = chave;
    strcpy(novo.nome, nome);
    strcpy(novo.telefone, telefone);
    strcpy(novo.email, email);
    
    Celula *nova = malloc(sizeof(Celula));

    nova->pessoa = novo; 
    nova->prox = aux->prox;
    aux->prox = nova;
  } else {
    printf("O cadastro informado nao existe. \n");
  }
}

void removePessoa(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  
  while (aux != NULL && aux->pessoa.chave != x) {
    anterior = aux; 
    aux = aux->prox;
  }

  if (aux == NULL) {
    printf("Pessoa nao encontrada;");
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
