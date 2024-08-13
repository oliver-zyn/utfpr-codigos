#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no_arvore {
    char nome[100];
    int idade;
    float pontuacao;
    int altura;
    struct no_arvore *esq;
    struct no_arvore *dir;
};

typedef struct no_arvore* NoArvAVL;

NoArvAVL* cria_ArvAVL(){
    NoArvAVL* raiz = (NoArvAVL*) malloc(sizeof(NoArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct no_arvore* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(NoArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct no_arvore* no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

int fatorBalanceamento_NO(struct no_arvore* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(NoArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

void preOrdem_ArvAVL(NoArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("Nome: %s - Idade: %d - Pontuacao: %.2f - Altura(%d)\n", (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(NoArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("Nome: %s - Idade: %d - Pontuacao: %.2f - Altura(%d)\n", (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, altura_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(NoArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("Nome: %s - Idade: %d - Pontuacao: %.2f - Altura(%d)\n", (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, altura_NO(*raiz));
    }
}

//=================================
void RotacaoLL(NoArvAVL *A){//LL
    printf("Realizando rotacao LL\n");
    struct no_arvore *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq), (*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(NoArvAVL *A){//RR
    printf("Realizando rotacao RR\n");
    struct no_arvore *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq), altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir), (*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(NoArvAVL *A){//LR
    printf("Realizando rotacao LR\n");
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(NoArvAVL *A){//RL
    printf("Realizando rotacao RL\n");
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(NoArvAVL *raiz, char *nome, int idade, int pontuacao){
    if(*raiz == NULL){
        struct no_arvore *novo;
        novo = (struct no_arvore*)malloc(sizeof(struct no_arvore));
        if(novo == NULL)
            return 0;

        strcpy(novo->nome, nome);
        novo->idade = idade;
        novo->pontuacao = pontuacao;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct no_arvore *atual = *raiz;
    if(strcmp(nome, atual->nome) < 0){
        if(insere_ArvAVL(&(atual->esq), nome, idade, pontuacao) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(strcmp(nome, (*raiz)->esq->nome) < 0){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(strcmp(nome, atual->nome) > 0){
            if(insere_ArvAVL(&(atual->dir), nome, idade, pontuacao) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(strcmp((*raiz)->dir->nome, nome) < 0){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("\nNome duplicado!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return 1;
}

void alteraPontuacaoParticipante(NoArvAVL *raiz, char *nome, char resultado){
    if(*raiz == NULL){
        printf("\nParticipante nao encontrado\n");
        return;
    }

    struct no_arvore *atual = *raiz;
    while(atual != NULL){
        if(strcmp(nome, atual->nome) == 0){
            if(resultado == 'v')
                atual->pontuacao += 1;
            else if(resultado == 'e')
                atual->pontuacao += 0.5;
            else if(resultado == 'p')
                atual->pontuacao -= 1;
            return;
        }
        if(strcmp(nome, atual->nome) < 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    printf("\nParticipante nao encontrado\n");
}