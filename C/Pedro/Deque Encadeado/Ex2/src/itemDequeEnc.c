#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h" //inclui os Protótipos

struct item {
    int chaveArvore;
    int qtd;
};

struct celula {
    Item item;
    Celula *prox;
};

struct deque {
    Celula *ini;
    Celula *fim;
};

Deque* cria_Deque() {
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL) {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    return dq;
}

int verificaDequeVazia(Deque *dq) {
    return (dq->ini == NULL);
}

void insereFinal_Deque(Deque* dq, int chave, int qtd) {
    
    Item novo;
    novo.chaveArvore = chave;
    novo.qtd = qtd;
    
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    if (verificaDequeVazia(dq)) {
        nova->prox = dq->ini;
        dq->ini = nova;
    }
    else {
        nova->prox = NULL;
        dq->fim->prox = nova;
    }
    dq->fim = nova;
}

void insereInicio_Deque(Deque* dq, int chave, int qtd)
{
    //cria novo item que vai ser guardado na Deque
    Item novo;
    novo.chaveArvore = chave;
    novo.qtd = qtd;
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = dq->ini;
    if (verificaDequeVazia(dq)) {
        printf("Pau 2");
        dq->fim = nova;
    }
    dq->ini = nova;
}


void removeInicio_Deque(Deque* dq)
{
    if (verificaDequeVazia(dq))
    {
        printf("Erro: Deque vazia!\n");
        return;
    }

    Celula *remover = dq->ini;
    dq->ini = remover->prox;
    free(remover);
    if (verificaDequeVazia(dq)) //se ficou vazia, fim aponta para NULL
        dq->fim = NULL;
}

int removeFinal_Deque(Deque* dq)
{
    if (verificaDequeVazia(dq))
    {
        printf("Erro: Deque vazia!\n");
        return -1;
    }
    Celula *remover = dq->fim;

    if (remover == dq->ini) //remover o primeiro e unico elemento?
    {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    else
    {
        Celula *ultimo = dq->ini;
        while (ultimo->prox != dq->fim)
        {
            ultimo = ultimo->prox;
        }

        ultimo->prox = NULL;
        dq->fim = ultimo;
    }
    free(remover);
}


void imprime_Deque(Deque* dq)
{
    Celula *aux = dq->ini;
    while (aux != NULL) {
        printf("Chave: %d\n", aux->item.chaveArvore);
        printf("Quantidade da arvore: %d\n", aux->item.qtd);
        aux = aux->prox;
    }
}

void libera_Deque(Deque* dq)
{
    Celula *aux = dq->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}

// Ex 2

// void implementaQtdArvore(Deque *dq, int chaveArvore) {
//     Celula *aux = dq->ini;

//     if(verificaDequeVazia(dq)) {
//         insereFinal_Deque(dq, chaveArvore, 1);
//         return;
//     }

//     while(aux != NULL) {
//         if(aux->item.chaveArvore == chaveArvore) {
//             aux->item.qtd = aux->item.qtd + 1;
//             return;
//         }
//         aux = aux->prox;
//     }

//     insereFinal_Deque(dq, chaveArvore, 1);
// }

void imprimePorcentagemPorEspecie(Deque *dq) {
    Celula *aux = dq->ini;

     if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return;
    }

    int totalQtd = totalQtdArvore(dq);

    printf("Porcentagem das arvores\n");
    while (aux != NULL) {
        printf("Especie: %d Porcentagem: %.0f%%\n", aux->item.chaveArvore, ((aux->item.qtd/totalQtd) * 100));
        aux = aux->prox;
    }
}

int totalQtdArvore(Deque *dq) {
    int totalArvore = 0;
    Celula *aux = dq->ini;

    while(aux != NULL) {
        totalArvore += aux->item.qtd;
        aux = aux->prox;
    }
    return totalArvore;
}

int codMaisFrequente(Deque *dq) {
    Celula *aux = dq->ini;

    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return -1;
    }

    Celula *qtdMaisFreq = aux;
    aux = aux->prox;

    while(aux != NULL) {
        if(qtdMaisFreq->item.qtd < aux->item.qtd) {
            qtdMaisFreq = aux;
        }
        aux = aux->prox;
    }

    return qtdMaisFreq->item.chaveArvore;
}
