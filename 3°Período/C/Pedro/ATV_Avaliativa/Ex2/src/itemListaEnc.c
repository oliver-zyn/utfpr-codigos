#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemListaEnc.h"

struct jogo {
  int chave;
  int idadeMinima;
  char nome[100];
  char descricao[200];
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

void buscaPorNome(Lista * lst, char nome[]) {
  Celula *aux = lst->primeira;
  while (aux != NULL && strcmp(aux->jogo.nome, nome) != 0)  {
    aux = aux->prox;
  }

  if(aux == NULL) {
    printf("\nJogo nao encontrado!\n");
    return;
  }

  printf("\nChave: %d\n", aux->jogo.chave);
  printf("Idade Minima: %d\n", aux->jogo.idadeMinima);
  printf("Nome do jogo: %s\n", aux->jogo.nome);
  printf("Descricao: %s\n", aux->jogo.descricao);
  printf("Link de Acesso: %s\n", aux->jogo.linkAcesso);
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
    printf("Chave: %d\n", aux->jogo.chave);
    printf("Idade Minima: %d\n", aux->jogo.idadeMinima);
    printf("Nome do jogo: %s\n", aux->jogo.nome);
    printf("Descricao: %s\n", aux->jogo.descricao);
    printf("Link de Acesso: %s\n", aux->jogo.linkAcesso);
  }
}

void insereInicioLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]) {
  // Cria novo item que vai ser guardado na lista
  Jogo novo;
  novo.chave = chave;
  novo.idadeMinima = idadeMinima;
  strcpy(novo.nome, nome);
  strcpy(novo.descricao, descricao);
  strcpy(novo.linkAcesso, linkAcesso);

  Celula *nova = malloc(sizeof(Celula));
  nova->jogo = novo; // atribui ao campo item da nova célula o novo item
  // inserção no início: a próxima célula é aquela que era a primeira
  nova->prox = lst->primeira;
  //a primeira agora é a nova célula
  lst->primeira = nova;
}

// adiciona um elemento no fim da lista
void insereFimLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]) {
  // Cria novo item que vai ser guardado na lista
  Jogo novo;
  novo.chave = chave;
  novo.idadeMinima = idadeMinima;
  strcpy(novo.nome, nome);
  strcpy(novo.descricao, descricao);
  strcpy(novo.linkAcesso, linkAcesso);
  // Cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->jogo = novo; // atribui ao campo item da nova célula o novo item
  // inserção no fim da lista
  nova->prox = NULL; // a nova célula vai ser a última, aponta para NULL
  if (verificaListaVazia(lst)) { // se a lista está vazia, quem vai apontar para a nova célula é a primeira
    lst->primeira = nova;
  } else { // se não está vazia, quem vai apontar para a nova é a que era a última
    Celula *ultima;
    ultima = lst->primeira; // partindo da primeira célula percorre
    while (ultima->prox != NULL) {
      ultima = ultima->prox;
    }

    ultima->prox = nova; // após a última, inserir a nova célula
    
  }
}

// adiciona um elemento no meio da lista
void insereMeioLista(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[], int x) {
  Celula *aux = buscaPorChave(lst, x); // prcura pela chave x

  if (aux != NULL) {
    // Cria novo item que vai ser guardado na lista
    Jogo novo;
    novo.chave = chave;
    novo.idadeMinima = idadeMinima;
    strcpy(novo.nome, nome);
    strcpy(novo.descricao, descricao);
    strcpy(novo.linkAcesso, linkAcesso);
    // Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->jogo = novo; // atribui ao campo item da nova célula o novo item
    // Inserção no meio da lista
    nova->prox = aux->prox;
    aux->prox = nova;
  } else {
    printf("O item informado nao existe. \n");
  }
}

void removeItemPorNome(Lista *lst, char nome[]) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  // encontra o item com a chave que deve ser removida
  while (aux != NULL && strcpy(aux->jogo.nome, nome) == 0) {
    anterior = aux; // guarda quem é a célula anterior
    aux = aux->prox;
  }

  if (aux == NULL) {
    printf("Item nao encontrado;");
    return;
  }

  if (aux == lst->primeira) { // remover do começo
    lst->primeira = aux->prox;
  } else { // meio ou fim
    anterior->prox = aux->prox;
  }

  free(aux);
}

void removeItem(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  // encontra o item com a chave que deve ser removida
  while (aux != NULL && aux->jogo.chave != x) {
    anterior = aux; // guarda quem é a célula anterior
    aux = aux->prox;
  }

  if (aux == NULL) {
    printf("Item nao encontrado;");
    return;
  }

  if (aux == lst->primeira) { // remover do começo
    lst->primeira = aux->prox;
  } else { // meio ou fim
    anterior->prox = aux->prox;
  }

  free(aux);
}

// libera da memória
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

void insereOrdenado(Lista *lst, int chave, int idadeMinima, char nome[], char descricao[], char linkAcesso[]) {
    if (verificaListaVazia(lst) || lst->primeira->jogo.idadeMinima > idadeMinima) {
        insereInicioLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
        return;
    }
    
    Celula *atual = lst->primeira;
    Celula *anterior = NULL;
    
    while (atual != NULL && atual->jogo.idadeMinima < idadeMinima) {
        anterior = atual;
        atual = atual->prox;
    }
    
    Celula *nova = malloc(sizeof(Celula));
    nova->jogo.chave = chave;
    nova->jogo.idadeMinima = idadeMinima;
    strcpy(nova->jogo.nome, nome);
    strcpy(nova->jogo.descricao, descricao);
    strcpy(nova->jogo.linkAcesso, linkAcesso);
    
    nova->prox = atual;
    
    if (anterior != NULL) {
        anterior->prox = nova;
    } else {
        lst->primeira = nova;
    }
    
    if (atual == NULL) {
        insereFimLista(lst, chave, idadeMinima, nome, descricao, linkAcesso);
    }
}


