#include <stdio.h>
#include <stdlib.h>
#include "../include/itemListaEnc.h"

struct item {
  int chave;
  //outros campos
};

struct celula {
  Item item;
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
    printf("Chave: %d\n", aux->item.chave);
  }
}

// adiciona um elemento no inicio da lista
void insereInicioLista(Lista *lst, int chave) {
  // Cria novo item que vai ser guardado na lista
  Item novo;
  novo.chave = chave;
  // Cria nova célula que vai guardar o item
  Celula *nova = malloc(sizeof(Celula));
  nova->item = novo; // atribui ao campo item da nova célula o novo item
  // inserção no início: a próxima célula é aquela que era a primeira
  nova->prox = lst->primeira;
  //a primeira agora é a nova célula
  lst->primeira = nova;
}

// adiciona um elemento no fim da lista
void insereFimLista(Lista *lst, int chave) {
  // Cria novo item que vai ser guardado na lista
  Item novo;
  novo.chave = chave;
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
void insereMeioLista(Lista *lst, int chave, int x) {
  Celula *aux = buscaPorChave(lst, x); // prcura pela chave x

  if (aux != NULL) {
    // Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    // Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo; // atribui ao campo item da nova célula o novo item
    // Inserção no meio da lista
    nova->prox = aux->prox;
    aux->prox = nova;
  } else {
    printf("O item informado nao existe. \n");
  }
}

// remove um item qualquer da lista
void removeItem(Lista *lst, int x) {
  Celula *aux = lst->primeira;
  Celula *anterior;
  // encontra o item com a chave que deve ser removida
  while (aux != NULL && aux->item.chave != x) {
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

//FUNCOES EXERCÍCIOS

//2. Escreva uma função que recebe duas listas encadeadas e concatena as duas (liga a segunda lista no final da primeira lista).

Lista *concatenarListas(Lista *lst1, Lista *lst2) {
  Lista *lstConcat = criaListaVazia();
  Celula *aux;
  for (aux = lst1->primeira; aux != NULL; aux = aux->prox) {
    insereFimLista(lstConcat, aux->item.chave);
  }

  for (aux = lst2->primeira; aux != NULL; aux = aux->prox) {
    insereFimLista(lstConcat, aux->item.chave);
  }

  return lstConcat;
}

//3. Escreva uma função que recebe duas listas. A primeira guarda n números inteiros e a segunda está vazia. A função deve inserir os elementos da primeira lista na segunda lista, de maneira ordenada

// void insereOrdenadosOutraLista(Lista *lst1, Lista *lst2) {
//   Celula *aux1 = lst1->primeira;
  
//   // Percorre a Lista 1
//   while (aux1 != NULL) {
//     int chaveAtual = aux1->item.chave;

//     // Insere ordenado na Lista 2
//     Celula *aux2 = lst2->primeira;
//     Celula *anterior = NULL;

//     while (aux2 != NULL && aux2->item.chave < chaveAtual) {
//       anterior = aux2;
//       aux2 = aux2->prox;
//     }

//     // Cria uma nova célula para o elemento atual da Lista 1
//     Celula *nova = malloc(sizeof(Celula));
//     nova->item.chave = chaveAtual;

//     // Insere a nova célula na Lista 2
//     if (anterior == NULL) {
//       // Inserção no início da Lista 2
//       nova->prox = lst2->primeira;
//       lst2->primeira = nova;
//     } else {
//       // Inserção no meio ou fim da Lista 2
//       nova->prox = aux2;
//       anterior->prox = nova;
//     }

//     aux1 = aux1->prox;  // Avança para o próximo elemento da Lista 1
//   }

//   printf("\nLISTA 1:\n");
//   imprimeLista(lst1);
//   printf("\nLISTA 2:\n");
//   imprimeLista(lst2);
// }


void insereOrdenadosOutraLista(Lista *lst1, Lista *lst2) {
  Celula *aux1;
  
  for (aux1 = lst1->primeira; aux1 != NULL; aux1 = aux1->prox) {
    int chaveAtual = aux1->item.chave;

    Celula *aux2 = lst2->primeira;
    Celula *anterior = NULL;

    while (aux2 != NULL && aux2->item.chave < chaveAtual) {
      anterior = aux2;
      aux2 = aux2->prox;
    }

    if (anterior == NULL) {
      insereInicioLista(lst2, chaveAtual);
    } else {
      insereMeioLista(lst2, chaveAtual, anterior->item.chave);
    }
  }

  printf("\nLISTA 1:\n");
  imprimeLista(lst1);
  printf("\nLISTA 2:\n");
  imprimeLista(lst2);
}
