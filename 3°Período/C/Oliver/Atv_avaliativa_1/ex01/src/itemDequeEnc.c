#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/itemDequeEnc.h"

struct noticia {
    int chave;
    int anoPublicacao;
    char manchete[100];
    char corpo[200];
    char autor[100];
    char classificacao[50];
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

void insereFinal_Deque(Deque* dq, int chave, int anoPublicacao, char manchete[], char corpo[], char autor[], char classificacao[]) {
    Noticia novo;
    novo.chave = chave;
    novo.anoPublicacao = anoPublicacao;
    strcpy(novo.manchete, manchete);
    strcpy(novo.corpo, corpo);
    strcpy(novo.autor, autor);
    strcpy(novo.classificacao, classificacao);

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

void insereInicio_Deque(Deque* dq, int chave, int anoPublicacao, char manchete[], char corpo[], char autor[], char classificacao[]) {
    Noticia novo;
    novo.chave = chave;
    novo.anoPublicacao = anoPublicacao;
    strcpy(novo.manchete, manchete);
    strcpy(novo.corpo, corpo);
    strcpy(novo.autor, autor);
    strcpy(novo.classificacao, classificacao);

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

void imprime_Deque(Deque* dq) {
    Celula *aux = dq->ini;
    while (aux != NULL) {
        printf("\nCodigo: %d\n", aux->noticia.chave);
        printf("Ano de publicacao: %d\n", aux->noticia.anoPublicacao);
        printf("Manchete: %s\n", aux->noticia.manchete);
        printf("Corpo: %s\n", aux->noticia.corpo);
        printf("Autor: %s\n", aux->noticia.autor);
        printf("Classificacao: %s\n", aux->noticia.classificacao);
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

int numeroNoticiasClassificacao(Deque * dq, char classificacao[]) {
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

        aux = aux->prox;
    }

    return count;
}

void imprimePorcentagemClassificacaoMaior(Deque * dq) {
    float qtdTotalNoticias = numeroTotalNoticias(dq);
    int qtdCinema = numeroNoticiasClassificacao(dq, "Cinema");
    int qtdCiencia = numeroNoticiasClassificacao(dq, "Ciencia");
    int qtdPolitica = numeroNoticiasClassificacao(dq, "Politica");

    float classificacaoMaiorQtd = qtdCinema;

    if (qtdCiencia > classificacaoMaiorQtd) {
        classificacaoMaiorQtd = qtdCiencia;
    }
    if (qtdPolitica > classificacaoMaiorQtd) {
        classificacaoMaiorQtd = qtdPolitica;
    }

    printf("\nPorcentagem referente a classificacao com maior numero de noticias\n");
    if (qtdCinema == classificacaoMaiorQtd) {
        float percentualCinema = ((qtdCinema / qtdTotalNoticias) * 100);
        printf("Cinema: %.2f%%\n", percentualCinema);
        return;
    }
    if (qtdCiencia == classificacaoMaiorQtd) {
        float percentualCiencia = ((qtdCiencia / qtdTotalNoticias) * 100);
        printf("Ciencia: %.2f%%\n", percentualCiencia);
        return;
    }
    if (qtdPolitica == classificacaoMaiorQtd) {
        float percentualPolitica = ((qtdPolitica / qtdTotalNoticias) * 100);
        printf("Politica: %.2f%%\n", percentualPolitica);
        return;
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

        aux = aux->prox;
    }

    return count;
}

void imprimeNumeroNoticiasClassificacao(Deque *dq) {
    printf("\nQuantidade de noticias por classsificacao: \n");
    printf("\nCinema: %d", numeroNoticiasClassificacao(dq, "Cinema"));
    printf("\nCiencia: %d", numeroNoticiasClassificacao(dq, "Ciencia"));
    printf("\nPolitica: %d\n", numeroNoticiasClassificacao(dq, "Politica"));
}