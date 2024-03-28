#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemDequeEnc.h"

enum Classificacoes {Cinema = 1, Ciencia = 2, Politica = 3};

struct noticia {
    int chave;
    int ano_publicacao;
    char manchete[100];
    char corpo[200];
    char autor[100];
    enum Classificacoes classificacao;
};

struct celula {
    Noticia noticia;
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

int verificaDequeVazia(Deque* dq) {
    return (dq->ini == NULL);
}

void insereFinal_Deque(Deque* dq, int chave, int ano_publicacao, char manchete[], char corpo[], char autor[], enum Classificacoes classificacao) {
    Noticia novo;
    novo.chave = chave;
    novo.ano_publicacao = ano_publicacao;
    strcpy(novo.manchete, manchete);
    strcpy(novo.corpo, corpo);
    strcpy(novo.autor, autor);
    novo.classificacao = classificacao;

    Celula *nova = malloc(sizeof(Celula));
    nova->noticia = novo;
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

void insereInicio_Deque(Deque* dq, int chave, int ano_publicacao, char manchete[], char corpo[], char autor[], enum Classificacoes classificacao) {
    Noticia novo;
    novo.chave = chave;
    novo.ano_publicacao = ano_publicacao;
    strcpy(novo.manchete, manchete);
    strcpy(novo.corpo, corpo);
    strcpy(novo.autor, autor);
    novo.classificacao = classificacao;

    Celula *nova = malloc(sizeof(Celula));
    nova->noticia = novo;
    nova->prox = dq->ini;
    if (verificaDequeVazia(dq)) {
        dq->fim = nova;
    }
    dq->ini = nova;
}


void removeInicio_Deque(Deque* dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return;
    }

    Celula *remover = dq->ini;
    dq->ini = remover->prox;
    free(remover);
    if (verificaDequeVazia(dq))
        dq->fim = NULL;
}

int removeFinal_Deque(Deque* dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return -1;
    }
    Celula *remover = dq->fim;

    if (remover == dq->ini) {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    else {
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

char retNomeClassificacao(enum Classificacoes classificacao) {
    if (classificacao == Cinema) {
        return "Futebol";
    } else if (classificacao = Ciencia) {
        return "Ciencia";
    } else {
        return "Politica";
    }
}

void imprime_Deque(Deque* dq) {
    Celula *aux = dq->ini;
    while (aux != NULL) {
        printf("Chave: %d\n", aux->noticia.chave);
        printf("Ano de publicacao: %d\n", aux->noticia.ano_publicacao);
        printf("Manchete: %s\n", aux->noticia.manchete);
        printf("Corpo: %s\n", aux->noticia.corpo);
        printf("Autor: %s\n", aux->noticia.autor);
        printf("Classificacao: %s\n", retNomeClassificacao(aux->noticia.classificacao));
        aux = aux->prox;
    }
}

void libera_Deque(Deque* dq) {
    Celula *aux = dq->ini;
    Celula *liberar;
    while(aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}

int numeroNoticiasClassificacao(Deque * dq, enum Classificacoes classificacao) {
    Celula *aux = dq->ini;
    int count = 0;

    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return -1;
    }

    while (aux != NULL) {
        if (strcmp(aux->noticia.classificacao, classificacao) == 0) {
            count++;
        }
    }

    return count;
}

void imprimePorcentagemClassificacaoMaior(Deque * dq) {
    float totalNoticias = numeroTotalNoticias(dq);
    int countCinema = numeroNoticiasClassificacao(dq, Cinema);
    int countCiencia = numeroNoticiasClassificacao(dq, Ciencia);
    int countPolitica = numeroNoticiasClassificacao(dq, Politica);
    float percentualCinema = ((countCinema / totalNoticias) * 100);
    float percentualCiencia = ((countCiencia / totalNoticias) * 100);
    float percentualPolitica = ((countPolitica / totalNoticias) * 100);

    float maiorPercentual = percentualCinema;

    if (percentualCiencia > maiorPercentual) {
        maiorPercentual = percentualCiencia;
    }
    if (percentualPolitica > maiorPercentual) {
        maiorPercentual = percentualPolitica;
    }

    if (percentualCinema == maiorPercentual) {
        printf("Cinema: %.2f%%\n", percentualCinema);
    }
    if (percentualCiencia == maiorPercentual) {
        printf("Ciência: %.2f%%\n", percentualCiencia);
    }
    if (percentualPolitica == maiorPercentual) {
        printf("Política: %.2f%%\n", percentualPolitica);
    }
   
}

int numeroTotalNoticias(Deque * dq) {
    Celula *aux = dq->ini;
    int count = 0;

    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return -1;
    }

    while (aux != NULL) {
        count++;
    }

    return count;
}