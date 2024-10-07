#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemListaEnc.h"

struct pedro {
  int chave;
  char dataRegistro[20];
  int id_atleta;
  float quilometragem;
  int rota;
};

struct celula {
  Pedro item;
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

// retorna o indice do item com a chave buscada ou -1 se não encontrar
Celula* buscaPorChave(Lista * lst, int chave) {
  Celula *aux = lst->primeira;
  while (aux != NULL && aux->item.chave != chave) {
    aux = aux->prox;
  }
  return aux;
}

// imprime a lista
void imprimeLista(Lista *lst) {
  Celula *aux;
  for (aux = lst->primeira; aux != NULL; aux = aux->prox) {
    printf("\nChave: %d\n", aux->item.chave);
    printf("Data Registro: %s\n", aux->item.dataRegistro);
    printf("ID do atleta: %d\n", aux->item.id_atleta);
    printf("Quilometragem percorrida: %.2fKM\n", aux->item.quilometragem);
    printf("Rota: %d\n", aux->item.rota);
  }
}

void insereInicioLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota) {
  Pedro novo;
  novo.chave = chave;
  strcpy(novo.dataRegistro, dataReg);
  novo.id_atleta = idatl;
  novo.quilometragem = quil;
  novo.rota = rota;

  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo;
  nova->prox = lst->primeira;
  lst->primeira = nova;
}

// adiciona um elemento no fim da lista
void insereFimLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota) {
  // Cria novo item que vai ser guardado na lista
  Pedro novo;
  novo.chave = chave;
  strcpy(novo.dataRegistro, dataReg);
  novo.id_atleta = idatl;
  novo.quilometragem = quil;
  novo.rota = rota;
  // Cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo; // atribui ao campo item da nova célula o novo item
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
void insereMeioLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota, int x) {
  Celula *aux = buscaPorChave(lst, x); // prcura pela chave x

  if (aux != NULL) {
    // Cria novo item que vai ser guardado na lista
    Pedro novo;
    novo.chave = chave;
    strcpy(novo.dataRegistro, dataReg);
    novo.id_atleta = idatl;
    novo.quilometragem = quil;
    novo.rota = rota;
    // Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo; // atribui ao campo item da nova célula o novo item
    // Inserção no meio da lista
    nova->prox = aux->prox;
    aux->prox = nova;
    printf("Registro concluido!\n");
  } else {
    printf("O registro informado nao existe. \n");
  }
}

// remove um item qualquer da lista
void removeRegistro(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  // encontra o item com a chave que deve ser removida
  while (aux != NULL && aux->item.chave != x) {
    anterior = aux; // guarda quem é a célula anterior
    aux = aux->prox;
  }

  if (aux == NULL) {
    printf("Registro nao encontrado;");
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

// LETRA E) 

float totalQtdQuikporRota(Lista *ls, int rota) {
    float totalQuik = 0;
    Celula *aux = ls->primeira;

    while(aux != NULL) {
      if(aux->item.rota == rota) {
        totalQuik += aux->item.quilometragem;
      } 
      aux = aux->prox;
    }
    if (totalQuik == 0) {
      printf("Rota nao existe, ou nao foi percorrida ainda.\n");
    } else {
      printf("\nRota %d quilometragem percorrida: %.2fKM\n", rota, totalQuik);
    }
}