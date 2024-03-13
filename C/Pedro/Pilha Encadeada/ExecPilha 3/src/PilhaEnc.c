#include <stdio.h>
#include <stdlib.h>
#include "../include/PilhaEnc.h"
#include <string.h>

struct pedro {
    int chave;
    char nome_emp[50];
    char atuacao[50];
    float desconto;
};

struct celula {
    Pedro Pedro;
    Celula *prox;
};

struct pilha {
    Celula *topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilha(Pilha *p, int chave, char nome_emp[], char atuacao[], float desconto) {
    Pedro novo;
    novo.chave = chave;
    strcpy(novo.nome_emp, nome_emp);
    strcpy(novo.atuacao, atuacao);
    novo.desconto = desconto;

    Celula *nova = malloc(sizeof(Celula));
    nova->Pedro = novo;
    nova->prox = p->topo;
    p->topo = nova;
}

void imprimePilha(Pilha *p) {
    Celula *aux;
    for (aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("\nChave: %d\n", aux->Pedro.chave);
        printf("Nome da empresa: %s\n", aux->Pedro.nome_emp);
        printf("Atuacao: %s\n", aux->Pedro.atuacao);
        printf("Desconto para associados: %.0f%%\n", aux->Pedro.desconto * 100);
    }
}

int verificaPilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Erro: pilha vazia!");
    }
    Celula *remover = p->topo;
    p->topo = remover->prox;
    free(remover);
}

void liberaPilha(Pilha *p) {
    Celula *aux = p->topo;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(p);
}

