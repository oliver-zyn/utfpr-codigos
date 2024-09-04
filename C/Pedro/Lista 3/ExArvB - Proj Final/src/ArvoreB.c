#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

struct node {
        int    n; /* n < M No. de chaves no n� sempre � menor que a ordem da �rvore B*/
        int    chaves[M - 1]; /*array de chaves*/
        struct node *p[M]; /* array de ponteiros */
};

enum statusChave {
        Duplicado,
        NaoEncontrado,
        Sucesso,
        Inseriu,
        PoucasChaves,
};

Node * inserirNo(Node *raiz, int chave) {
        Node *novoNo;
        int chaveIni;
        StatusChave status;
        status = ins(raiz, chave, &chaveIni, &novoNo);
        if (status == Duplicado)
                printf("Chave ja inserida.\n");
        if (status == Inseriu) {
                Node *raizIni = raiz;
                raiz = (Node*)malloc(sizeof(Node));
                raiz->n = 1;
                raiz->chaves[0] = chaveIni;
                raiz->p[0] = raizIni;
                raiz->p[1] = novoNo;
        }/*Fim if */
        return raiz;
}/*Fim inserir()*/

StatusChave ins(Node *ptr, int chave, int *chaveIni, Node **novoNo) {
        Node *novoPtr, *ultPtr;
        int pos, i, n, splitPos;
        int novaChave, ultChave;
        StatusChave status;
        if (ptr == NULL) {
                *novoNo = NULL;
                *chaveIni = chave;
                return Inseriu;
        }
        n = ptr->n;
        pos = buscaChave(ptr, chave, ptr->chaves, n);
        if (pos < n && chave == ptr->chaves[pos])
                return Duplicado;
        status = ins(ptr->p[pos], chave, &novaChave, &novoPtr);
        if (status != Inseriu)
                return status;
        /*If chaves in node is less than M-1 where M is order of B tree*/
        if (n < M - 1) {
                pos = buscaChave(ptr, novaChave, ptr->chaves, n);
                /*Shifting the chave and pointer right for inserting the new chave*/
                for (i = n; i>pos; i--) {
                        ptr->chaves[i] = ptr->chaves[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                /*chave is inserted at exact location*/
                ptr->chaves[pos] = novaChave;
                ptr->p[pos + 1] = novoPtr;
                ++ptr->n; /*incrementing the number of chaves in node*/
                return Sucesso;
        }/*Fim if */
         /*If chaves in nodes are maximum and position of node to be inserted is last*/
        if (pos == M - 1) {
                ultChave = novaChave;
                ultPtr = novoPtr;
        }
        else { /*If chaves in node are maximum and position of node to be inserted is not last*/
                ultChave = ptr->chaves[M - 2];
                ultPtr = ptr->p[M - 1];
                for (i = M - 2; i>pos; i--) {
                        ptr->chaves[i] = ptr->chaves[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                ptr->chaves[pos] = novaChave;
                ptr->p[pos + 1] = novoPtr;
        }
        splitPos = (M - 1) / 2;
        (*chaveIni) = ptr->chaves[splitPos];

        (*novoNo) = (Node*)malloc(sizeof(Node));/*Right node after split*/
        ptr->n = splitPos; /*No. of chaves for left splitted node*/
        (*novoNo)->n = M - 1 - splitPos;/*No. of chaves for right splitted node*/
        for (i = 0; i < (*novoNo)->n; i++) {
                (*novoNo)->p[i] = ptr->p[i + splitPos + 1];
                if (i < (*novoNo)->n - 1)
                        (*novoNo)->chaves[i] = ptr->chaves[i + splitPos + 1];
                else
                        (*novoNo)->chaves[i] = ultChave;
        }
        (*novoNo)->p[(*novoNo)->n] = ultPtr;
        return Inseriu;
}/*Fim ins()*/

void busca(Node *raiz, int chave) {
        int pos, i, n;
        Node *ptr = raiz;
        printf("Caminho de busca:\n");
        while (ptr) {
                n = ptr->n;
                for (i = 0; i < ptr->n; i++)
                        printf(" %d", ptr->chaves[i]);
                printf("\n");
                pos = buscaChave(raiz, chave, ptr->chaves, n);
                if (pos < n && chave == ptr->chaves[pos]) {
                        printf("Chave %d encontrada na posicao %d do ultimo no apresentado.\n", chave, pos);
                        return;
                }
                ptr = ptr->p[pos];
        }
        printf("Chave %d nao encontrada.\n", chave);
}/*Fim busca()*/

int buscaChave(Node *raiz, int chave, int *chaves_arr, int n) {
        int pos = 0;
        while (pos < n && chave > chaves_arr[pos])
                pos++;
        return pos;
}/*Fim buscaChave()*/

Node* excluirNo(Node *raiz, int chave) {
        Node *raizIni;
        StatusChave status;
        status = del(raiz, raiz, chave);
        switch (status) {
        case NaoEncontrado:
                printf("Chave %d nao encontrada.\n", chave);
                break;
        case PoucasChaves:
                raizIni = raiz;
                raiz = raiz->p[0];
                free(raizIni);
                break;
        default:
                return raiz;
        }/*Fim switch*/
        return raiz;
}/*Fim excluirNo()*/

StatusChave del(Node *raiz, Node *ptr, int chave) {
        int pos, i, pivot, n, min;
        int *chaves_arr;
        StatusChave status;
        Node **p, *esq_ptr, *dir_ptr;

        if (ptr == NULL)
                return NaoEncontrado;
        /*Atribui status do no*/
        n = ptr->n;
        chaves_arr = ptr->chaves;
        p = ptr->p;
        min = (M - 1) / 2;/*Numero minimode chaves*/

        //Busca pela chave a ser removida
        pos = buscaChave(raiz, chave, chaves_arr, n);
        // p � uma folha
        if (p[0] == NULL) {
                if (pos == n || chave < chaves_arr[pos])
                        return NaoEncontrado;
                /*Desloca chaves e ponteiros para a esquerda*/
                for (i = pos + 1; i < n; i++)
                {
                        chaves_arr[i - 1] = chaves_arr[i];
                        p[i] = p[i + 1];
                }
                return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
        }/*Fim if */

         //Se chave encontrada mas p nao � folha
        if (pos < n && chave == chaves_arr[pos]) {
                Node *qp = p[pos], *qp1;
                int nkey;
                while (1) {
                        nkey = qp->n;
                        qp1 = qp->p[nkey];
                        if (qp1 == NULL)
                                break;
                        qp = qp1;
                }/*Fim while*/
                chaves_arr[pos] = qp->chaves[nkey - 1];
                qp->chaves[nkey - 1] = chave;
        }/*Fim if */
        status = del(raiz, p[pos], chave);
        if (status != PoucasChaves)
                return status;

        if (pos > 0 && p[pos - 1]->n > min) {
                pivot = pos - 1; /*pivo para n�s esquerdo e direito*/
                esq_ptr = p[pivot];
                dir_ptr = p[pos];
                /*Atribui status para n� da direita*/
                dir_ptr->p[dir_ptr->n + 1] = dir_ptr->p[dir_ptr->n];
                for (i = dir_ptr->n; i>0; i--) {
                        dir_ptr->chaves[i] = dir_ptr->chaves[i - 1];
                        dir_ptr->p[i] = dir_ptr->p[i - 1];
                }
                dir_ptr->n++;
                dir_ptr->chaves[0] = chaves_arr[pivot];
                dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
                chaves_arr[pivot] = esq_ptr->chaves[--esq_ptr->n];
                return Sucesso;
        }/*Fim if */
        if (pos < n && p[pos + 1]->n > min) {
                pivot = pos; /*pivo para n�s esquerdo e direito*/
                esq_ptr = p[pivot];
                dir_ptr = p[pivot + 1];
                /*Atribui status para n�s da esquerda*/
                esq_ptr->chaves[esq_ptr->n] = chaves_arr[pivot];
                esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
                chaves_arr[pivot] = dir_ptr->chaves[0];
                esq_ptr->n++;
                dir_ptr->n--;
                for (i = 0; i < dir_ptr->n; i++) {
                        dir_ptr->chaves[i] = dir_ptr->chaves[i + 1];
                        dir_ptr->p[i] = dir_ptr->p[i + 1];
                }/*Fim for*/
                dir_ptr->p[dir_ptr->n] = dir_ptr->p[dir_ptr->n + 1];
                return Sucesso;
        }/*Fim if */

        if (pos == n)
                pivot = pos - 1;
        else
                pivot = pos;

        esq_ptr = p[pivot];
        dir_ptr = p[pivot + 1];
        /*realiza fus�o (merge) dos n�s da direita e esquerda*/
        esq_ptr->chaves[esq_ptr->n] = chaves_arr[pivot];
        esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
        for (i = 0; i < dir_ptr->n; i++) {
                esq_ptr->chaves[esq_ptr->n + 1 + i] = dir_ptr->chaves[i];
                esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
        }
        esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
        free(dir_ptr); /*Remove n� da direita*/
        for (i = pos + 1; i < n; i++) {
                chaves_arr[i - 1] = chaves_arr[i];
                p[i] = p[i + 1];
        }
        return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
}/*Fim del()*/

/*
 * A impressao da �rvore � feita como se ela estivesse na vertical ao inv�s da horizontal, portanto cada n� � impresso na vertical,
 * com a menor chave do n� na parte inferior do n�
 */
void imprime_arvore(Node *ptr, int nivel) {
    if (ptr != NULL) {
        char indent[10] = "";
        for (int i = 0; i < nivel; i++) {
            strcat(indent, "\t");
        }

        for (int i = ptr->n; i > 0; i--) {
            imprime_arvore(ptr->p[i], nivel + 1);
            printf("%s", indent);
            printf("%5d\n", ptr->chaves[i - 1]);
        }
        imprime_arvore(ptr->p[0], nivel + 1);
    }
}

void imprime_no(Node *ptr) {
    if (ptr != NULL) {
        for (int i = 0; i < ptr->n; i++) {
            printf("%5d", ptr->chaves[i]);
        }
        printf("\n");
    }
}

// Funcoes do jogo:

const char* getName(int nome) {
    switch (nome) {
        case 1250: return "Anel de Diamante | 0.9lab";
        case 1000: return "Ticket PREMIUM | League Futball";
        case 975: return "Bolsa de couro GUCCI";
        case 800: return "Tenis Jordan 2001";
        case 625: return "Smart Watch Apple";
        case 550: return "Mouse Deathadder Razer";
        case 375: return "Teclado Mecanico Logitech";
        case 200: return "Fone Bluetooth Xiaomi";
        case 105: return "Garrafa Termica Woolf";
        case 50: return "Garrafa Red Label";
        default: return "Item desconhecido";
    }
}

void imprime_inventario(Node *ptr, int nivel)
{
	if (ptr != NULL)
	{
		for (int i = ptr->n; i > 0; i--)
		{
			imprime_inventario(ptr->p[i], nivel + 1);
			printf("%s: R$ %d\n", getName(ptr->chaves[i - 1]), ptr->chaves[i - 1]);
		}
		imprime_inventario(ptr->p[0], nivel + 1);
	}
}

int roda_roleta(int saldo, int preco) {
    // 5 itens diferentes na roleta
    int roleta[7] = {1, 2, 3, 4, 5, 6, 7};

    // Simula as 3 casas da roleta
    int casa1 = roleta[rand() % 7];
    int casa2 = roleta[rand() % 7];
    int casa3 = roleta[rand() % 7];

    printf("\nResultado da roleta: %d | %d | %d\n", casa1, casa2, casa3);

    // Verifica os resultados
    if (casa1 == casa2 && casa2 == casa3) {
        printf("Parabens! Voce ganhou 5X o valor apostado! :() \n");
        saldo += preco * 5;
        printf("\nGANHOU: R$ %d", preco * 5);
    } else if (casa1 == casa2 || casa2 == casa3 || casa1 == casa3) {
        printf("Dois itens iguais! Dobrou o seu dinheiro. :) \n");
        saldo += preco * 2;
        printf("\nGanhou: R$ %d", preco * 2);
    } else {
        printf("Itens diferentes! Voce perdeu o valor apostado. \nQue azar! :( \n");
        saldo -= preco;
        printf("\nPerdeu: R$ %d", preco);
    }

    return saldo;
}

int buscaValor(Node *raiz, int chave) {
    int pos, i, n;
    Node *ptr = raiz;
    while (ptr) {
        n = ptr->n;
        pos = buscaChave(raiz, chave, ptr->chaves, n);
        if (pos < n && chave == ptr->chaves[pos]) {
                return 1;
        }
        ptr = ptr->p[pos];
    }
    return 0;
}/*Fim busca()*/