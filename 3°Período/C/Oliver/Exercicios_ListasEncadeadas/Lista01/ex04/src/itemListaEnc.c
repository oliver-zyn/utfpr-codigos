#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemListaEnc.h"


// 4. Utilize uma estrutura TAD de lista encadeada para representar um sistema para
// controlar a agenda telefônica de uma pessoa. (Peso 4,0)
//    a) Considere que a struct a ser criada para armazenar os dados deve ser
//    nomeada com o oliver e deve ter campos referentes ao nome do
//    contato, telefone e e-mail.
//    b) Crie um programa que simula a criação, inclusão, exclusão e impressão dos
//    c) dados sugeridos, sendo cadastrados pelo menos quatro registros de
//    contatos.

struct oliver {
  int chave;
  char nome[100];
  char contato[100];
  char telefone[100];
  char email[100];
};

struct celula {
  Oliver oliver;
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
  while (aux != NULL && aux->oliver.chave != chave) {
    aux = aux->prox;
  }

  return aux;
}

void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("\nItem:\n");
    printf("- Chave: %d\n", aux->oliver.chave);
    printf("- Nome: %s\n", aux->oliver.nome);
    printf("- Contato: %s\n", aux->oliver.contato);
    printf("- Telefone: %s\n", aux->oliver.telefone);
    printf("- Email: %s\n", aux->oliver.email);
  }
}

void insereInicioLista(Lista *lst, int chave, char nome[], char contato[], char telefone[], char email[]) {
  Oliver novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.contato, contato);
  strcpy(novo.telefone, telefone);
  strcpy(novo.email, email);
  Celula *nova = malloc(sizeof(Celula));
  nova->oliver = novo;
  nova->prox = lst->primeira;
  lst->primeira = nova;

  printf("aaaaa");
}

void insereFimLista(Lista *lst, int chave, char nome[], char contato[], char telefone[], char email[]) {
  Oliver novo;
  novo.chave = chave;
  strcpy(novo.nome, nome);
  strcpy(novo.contato, contato);
  strcpy(novo.telefone, telefone);
  strcpy(novo.email, email);
  Celula *nova = malloc(sizeof(Celula));
  nova->oliver = novo; 
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

void insereMeioLista(Lista *lst, int chave, char nome[], char contato[], char telefone[], char email[], int x) {
  Celula *aux = buscaPorChave(lst, x); 

  if (aux != NULL) {
    Oliver novo;
    novo.chave = chave;
    strcpy(novo.nome, nome);
    strcpy(novo.contato, contato);
    strcpy(novo.telefone, telefone);
    strcpy(novo.email, email);
    Celula *nova = malloc(sizeof(Celula));
    nova->oliver = novo;
    nova->prox = aux->prox;
    aux->prox = nova;
  } else {
    printf("O item informado nao existe. \n");
  }
}

void removeItem(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  while (aux != NULL && aux->oliver.chave != x) {
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


