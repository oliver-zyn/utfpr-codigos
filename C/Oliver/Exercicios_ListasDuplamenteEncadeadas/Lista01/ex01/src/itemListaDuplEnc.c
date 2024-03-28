#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/itemListaDuplEnc.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *ant; //A c�lula tamb�m guarda quem � a sua anterior
    Celula *prox;
};

struct listaDupl {
    Celula *primeira;
};

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia() {
    ListaDupl *ld = malloc(sizeof(ListaDupl));
    ld->primeira = NULL;
    return ld;
}

//adiciona um elment no in�cio da lista
void inserirInicio(ListaDupl *ld, int chave)
{
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chave;
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = NULL;
    nova->prox = ld->primeira;
    //se a lista n�o est� vazia, a anterior da que era a primeira ser� a nova
    if (!verificaListaDuplVazia(ld)) //se est� vazia adiciona no in�cio
    {
        ld->primeira->ant = nova;
    }
    ld->primeira = nova;
}

//adiciona um elemento no meio da listaDupl
void inserirMeio(ListaDupl *ld, int chaveB, int chaveI)
{
    Celula *anterior = buscaChave(ld, chaveB);
    if (anterior == NULL)
    {
        printf("Chave nao encontrada ou lista vazia.\n");
        return;
    }
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chaveI;
    Celula *proxima = anterior->prox;
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = anterior;
    nova->prox = proxima;
    anterior->prox = nova;
    if (proxima != NULL) //somente caso pr�xima n�o seja NULL, pois a NULL n�o tem anterior
    {
        proxima->ant = nova;
    }
}

//adiciona um elemento no final da lista
void inserirFinal(ListaDupl *ld, int chave)
{
    if (verificaListaDuplVazia(ld))
    {
        inserirInicio(ld, chave);
    }
    else
    {
        //criar noov item que vai ser guardado na fila
        Item novo;
        novo.chave = chave;
        //cria nova c�lula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = NULL;
        Celula *ultima = ld->primeira;
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        nova->ant = ultima;
        ultima->prox = nova;
    }
}

//Busca por chave na lista
Celula *buscaChave(ListaDupl *ld, int chave)
{
    Celula *aux = ld->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//imprime a Lista Duplamente Encadeada da equerda para direita
void imprimeEsqDir(ListaDupl *ld)
{
    Celula *aux = ld->primeira;
    while (aux != NULL)
    {
        printf("\nChave: %d ", aux->item.chave);
        aux = aux->prox;
    }
}

//imprime a Lista Duplamente Encadeada da direita para esquerda
void imprimeDirEsq(ListaDupl *ld)
{
    //ir at� a �ltima c�lula
    Celula *aux = ld->primeira;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    while (aux != NULL)
    {
         printf("\nChave: %d ", aux->item.chave);
         aux = aux->ant;
    }
}

//remove um item da lista duplamente encadeada
void removePorChave(ListaDupl *ld, int chave)
{
    Celula *remover = buscaChave(ld, chave);
    if (remover == NULL)
    {
        printf("Item nao encontrado ou lista vazia.\n");
        return;
    }
    if (remover->ant == NULL && remover->prox == NULL) //� a �nica, ou seja, a primeira
    {
        ld->primeira = NULL;
    }
    else if (remover == ld->primeira) //remover do in�cio
    {
        ld->primeira = remover->prox;
        ld->primeira->ant = NULL;
    }
    else //remover do meio
    {
        Celula *proxima = remover->prox;
        Celula *anterior = remover->ant;
        anterior->prox = proxima;
        if (proxima != NULL)
        {
            proxima->ant = anterior;
        }
    }
    free(remover);
}

//retorna 1 se a lista est� vazia ou 0 se n�o est� vazia
int verificaListaDuplVazia(ListaDupl *ld)
{
    return ld->primeira == NULL;
}

//libera da mem�ria
void liberaListaDupl(ListaDupl *ld)
{
    Celula *aux = ld->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(ld);
}

