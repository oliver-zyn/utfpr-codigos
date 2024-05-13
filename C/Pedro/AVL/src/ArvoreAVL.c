#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreAVL.h" //inclui os Prot�tipos

struct no_arvore {
    char nome[100];
    int idade;
    float pontuacao;
    struct no_arvore *esq;
    struct no_arvore *dir;
    int altura; // campo altura adicionado aqui
};

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
    libera_NO(*raiz);//libera cada n�
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

int totalNO_ArvAVL(NoArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(NoArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(NoArvAVL *raiz, char pai[100]){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("Nome: %s - Idade: %d - Pontuacao: %.1f - Altura: %d - Pai: %s - fb(%d)\n", 
               (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, (*raiz)->altura, pai, fatorBalanceamento_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->nome);
        preOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->nome);
    }
}

void emOrdem_ArvAVL(NoArvAVL *raiz, char pai[100]){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->nome);
        printf("Nome: %s - Idade: %d - Pontuacao: %.1f - Altura: %d - Pai: %s - fb(%d)\n", 
               (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, altura_NO(*raiz), pai, fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->nome);
    }
}

void posOrdem_ArvAVL(NoArvAVL *raiz, char pai[100]){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq), (*raiz)->nome);
        posOrdem_ArvAVL(&((*raiz)->dir), (*raiz)->nome);
        printf("Nome: %s - Idade: %d - Pontuacao: %.1f - Altura: %d - Pai: %s - fb(%d)\n", 
               (*raiz)->nome, (*raiz)->idade, (*raiz)->pontuacao, altura_NO(*raiz), pai, fatorBalanceamento_NO(*raiz));
    }
}

int consulta_ArvAVL(NoArvAVL *raiz, char nome[100]){
    if(raiz == NULL)
        return 0;
    struct no_arvore* atual = *raiz;
    while(atual != NULL){
        int cmp = strcmp(nome, atual->nome);
        if(cmp == 0){
            return 1;
        }
        if(cmp > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//=================================
void RotacaoLL(NoArvAVL *A){//LL
    printf(".RotacaoLL\n");
    struct no_arvore *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(NoArvAVL *A){//RR
    printf(".RotacaoRR\n");
    struct no_arvore *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(NoArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(NoArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(NoArvAVL *raiz, char nome[100], int idade, float pontuacao){
    int res;
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
    int cmp = nome[0] - atual->nome[0];
    if(cmp < 0){
        if((res = insere_ArvAVL(&(atual->esq), nome, idade, pontuacao)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(nome[0] < (*raiz)->esq->nome[0]){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else if(cmp > 0){
        if((res = insere_ArvAVL(&(atual->dir), nome, idade, pontuacao)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if((*raiz)->dir->nome[0] < nome[0]){
                    RotacaoRR(raiz);
                }else{
                    RotacaoRL(raiz);
                }
            }
        }
    }else{
        printf("Nome duplicado!!\n");
        return 0;
    }

    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;

    return res;
}

void alteraPontuacao_Participante(NoArvAVL *raiz, char nome[100], int resultado){
    if(*raiz == NULL) {
        printf("O participante \"%s\" nao existe na arvore!\n", nome);
        return;
    }

    float altRes = 0.5;

    if(resultado == 1) {
        altRes = 1;
    } 
    if(resultado == -1) {
        altRes = 0;    
    }

    struct no_arvore *atual = *raiz;
    int cmp = strcmp(nome, atual->nome);
    if(cmp < 0) {
        alteraPontuacao_Participante(&((*raiz)->esq), nome, resultado);
    } else if(cmp > 0) {
        alteraPontuacao_Participante(&((*raiz)->dir), nome, resultado);
    } else {
        atual->pontuacao += altRes;
        printf("\nPontuacao do participante \"%s\" atualizada para %.1f\n", nome, atual->pontuacao);
    }
}

void resultadoPontuacao(NoArvAVL *raiz, char nome1[100], int resultado1, char nome2[100], int resultado2) {
    int resultado = 0;
    if (resultado1 > resultado2) {
        resultado = 1;
        alteraPontuacao_Participante(&(*raiz), nome1, resultado);
    }
    if (resultado1 < resultado2) {
        resultado = 1;
        alteraPontuacao_Participante(&(*raiz), nome2, resultado);
    }
    if (resultado1 == resultado2) {
        resultado = 0;
        alteraPontuacao_Participante(&(*raiz), nome1, resultado);
        alteraPontuacao_Participante(&(*raiz), nome2, resultado);
    }
}

struct no_arvore* procuraMenorNome(struct no_arvore* atual) {
    struct no_arvore *no1 = atual;
    struct no_arvore *no2 = atual->esq;
    while (no2 != NULL) {
        if (no2->nome[0] < no1->nome[0]) {
            no1 = no2;
        }
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(NoArvAVL *raiz, char nome[100]){
    if(*raiz == NULL){// Árvore vazia
        printf("A arvore esta vazia!\n");
        return 0;
    }

    int res;
    struct no_arvore *atual = *raiz;
    int cmp = strcmp(nome, atual->nome);
    if(cmp < 0){
        printf("Indo para o no esquerdo de %s\n", (*raiz)->nome);
        if((res = remove_ArvAVL(&(*raiz)->esq, nome)) == 1){
            printf("Realizando rotacao de balanceamento na raiz %s\n", (*raiz)->nome);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }else if(cmp > 0){
        printf("Indo para o no direito de %s\n", (*raiz)->nome);
        if((res = remove_ArvAVL(&(*raiz)->dir, nome)) == 1){
            printf("Realizando rotacao de balanceamento na raiz %s\n", (*raiz)->nome);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }else{
        printf("Encontrado o participante %s para remocao\n", nome);
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){// Nó tem 1 filho ou nenhum
            printf("Removendo o no com 1 filho ou nenhum\n");
            struct no_arvore *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }else {
            printf("Encontrado o participante %s com dois filhos para remocao\n", nome);
            struct no_arvore* temp = procuraMenorNome((*raiz)->dir);
            strcpy((*raiz)->nome, temp->nome);
            printf("Substituindo o participante %s pelo menor filho %s da subarvore direita\n", nome, temp->nome);
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->nome);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                printf("Realizando rotacao de balanceamento na raiz %s\n", (*raiz)->nome);
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
        return 1;
    }

    (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;

    return res;
}