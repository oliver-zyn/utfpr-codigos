#include <stdio.h>
#include <stdlib.h>
#include "../include/itemDequeEnc.h" //inclui os Protótipos

struct item
{
    int cod_especie;
    int qtd;
};

struct celula
{
    Item item;
    Celula *prox;
};

struct deque
{
    Celula *ini;
    Celula *fim;
};

Deque* cria_Deque()
{
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL)
    {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    return dq;
}

int verificaDequeVazia(Deque* dq)
{
    return (dq->ini == NULL);
}

void insereFinal_Deque(Deque* dq, int cod_especie, int qtd)
{
    //cria novo item que vai ser guardado na Deque
    Item novo;
    novo.cod_especie = cod_especie;
    novo.qtd = qtd;
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    if (verificaDequeVazia(dq)) //se está vazia adiciona no início
    {
        //no->ant = NULL;
        nova->prox = dq->ini;
        dq->ini = nova;
    }
    else
    {
        //senão aciciona no final
        //no->ant = dq->final;
        //inserção no final, a nova célula aponta para NULL
        nova->prox = NULL;
        dq->fim->prox = nova;
    }
    dq->fim = nova;
}

void insereInicio_Deque(Deque* dq, int cod_especie, int qtd)
{
    //cria novo item que vai ser guardado na Deque
    Item novo;
    novo.cod_especie = cod_especie;
    novo.qtd = qtd;
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = dq->ini;
    if (verificaDequeVazia(dq)) //se está vazia fim será igual a ini
    {
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
    while (aux != NULL)
    {
        printf("Codigo especie: %d\n", aux->item.cod_especie);
        printf("Qtd especie: %d\n", aux->item.qtd);
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

// 2. Você está trabalhando em uma grande companhia que atua na área de recursos
// naturais. Usando imagens de satélite, a companhia deseja fazer um inventário
// de todas as árvores em uma determinada região, utilizando um deque para
// armazenar os dados das árvores. Com essa estrutura faça:
// a) Use como entrada para o problema o número de árvores na região mapeada
// e o código da espécie de cada árvore detectada.
// b) Calcule e apresente a porcentagem em que cada espécie de árvore aparece
// na região.
// c) Mostre qual é o código da espécie mais frequente.
// Dica: ao percorrer os códigos de entrada, quando encontrar o código de uma
// espécie que já está armazenada na estrutura, em vez de armazená-la
// novamente, incremente um campo de quantidade no item.

void atualizaDequeArvores(Deque *dq, int cod_especie) {
    Celula *aux = dq->ini;

    if (verificaDequeVazia(dq)) {
        insereFinal_Deque(dq, cod_especie, 1);
        return;
    }

    while (aux != NULL) {
        if (aux->item.cod_especie == cod_especie) {
            aux->item.qtd += 1;
            return;
        }

        aux = aux->prox;
    }

    insereFinal_Deque(dq, cod_especie, 1);
}

void imprimePorcentagemEspecie(Deque *dq) {
    Celula *aux = dq->ini;

    if (verificaDequeVazia(dq)) {
        printf("O deque esta vazio!");
        return;
    }

    float qtdTotal = qtdTotalArvores(dq);

    printf("Porcentagem de cada especie na regiao: \n");
    while (aux != NULL) {
        printf("Especie %d: %.2f%%\n", aux->item.cod_especie, ((aux->item.qtd / qtdTotal) * 100));
        aux = aux->prox;
    }
    
}

int qtdTotalArvores(Deque *dq) {
    Celula *aux = dq->ini;
    int qtd = 0;

    while (aux != NULL) {
        qtd += aux->item.qtd;
        aux = aux->prox;
    }

    return qtd;
}

int codEspecieMaisFrequente(Deque *dq) {
    Celula *aux = dq->ini;

    if (verificaDequeVazia(dq)) {
        printf("O deque esta vazio!");
        return -1;
    }

    Celula *itemMaiorQtd = aux;
    aux = aux->prox;

    while (aux != NULL) {
        if (itemMaiorQtd->item.qtd < aux->item.qtd) {
            itemMaiorQtd = aux;
        }
        aux = aux->prox;  
    }

    return itemMaiorQtd->item.cod_especie;
}
