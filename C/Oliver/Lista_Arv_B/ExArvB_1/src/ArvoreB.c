#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

struct pessoa {
	char nome[100];
};

struct node
{
	int n;			   /* n < M No. de itens no n� sempre � menor que a ordem da �rvore B*/
	Pessoas pessoa[M - 1]; /*array de itens*/
	struct node *p[M]; /* array de ponteiros */
};

enum statusChave {
	Duplicado,
	NaoEncontrado,
	Sucesso,
	Inseriu,
	Poucasitens,
};

Node *inserirNo(Node *raiz, char nome[100])
{
	Node *novoNo;
	char nomeInicial[100];
	StatusChave status;
	status = ins(raiz, nome, nomeInicial, &novoNo);
	if (status == Duplicado)
		printf("Nome ja inserido.\n");
	if (status == Inseriu)
	{
		Node *raizIni = raiz;
		raiz = (Node *)malloc(sizeof(Node));
		raiz->n = 1;
		strcpy(raiz->pessoa[0].nome, nomeInicial);
		raiz->p[0] = raizIni;
		raiz->p[1] = novoNo;
	}
	return raiz;
}

StatusChave ins(Node *ptr, char nome[100], char nomeInicial[100], Node **novoNo)
{
	Node *novoPtr, *ultPtr;
	int pos, i, n, splitPos;
	char novoNome[100], ultNome[100];
	StatusChave status;
	if (ptr == NULL)
	{
		*novoNo = NULL;
		strcpy(nomeInicial, nome);
		return Inseriu;
	}
	n = ptr->n;
	pos = buscaChave(ptr, nome, ptr->pessoa, n);
	if (pos < n && strcmp(nome, ptr->pessoa[pos].nome) == 0)
		return Duplicado;
	status = ins(ptr->p[pos], nome, novoNome, &novoPtr);
	if (status != Inseriu)
		return status;
	/*If itens in node is less than M-1 where M is order of B tree*/
	if (n < M - 1)
	{
		pos = buscaChave(ptr, novoNome, ptr->pessoa, n);
		/*Shifting the chave and pointer right for inserting the new chave*/
		for (i = n; i > pos; i--)
		{
			ptr->pessoa[i] = ptr->pessoa[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		/*chave is inserted at exact location*/
		strcpy(ptr->pessoa[pos].nome, novoNome);
		ptr->p[pos + 1] = novoPtr;
		++ptr->n; /*incrementing the number of itens in node*/
		return Sucesso;
	} /*Fim if */
	/*If itens in nodes are maximum and position of node to be inserted is last*/
	if (pos == M - 1)
	{
		strcpy(ultNome, novoNome);
		ultPtr = novoPtr;
	}
	else
	{ /*If itens in node are maximum and position of node to be inserted is not last*/
		strcpy(ultNome, ptr->pessoa[M - 2].nome);
		ultPtr = ptr->p[M - 1];
		for (i = M - 2; i > pos; i--)
		{
			ptr->pessoa[i] = ptr->pessoa[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		strcpy(ptr->pessoa[pos].nome, novoNome);
		ptr->p[pos + 1] = novoPtr;
	}
	splitPos = (M - 1) / 2;
	strcpy(nomeInicial, ptr->pessoa[splitPos].nome);

	(*novoNo) = (Node *)malloc(sizeof(Node)); /*Right node after split*/
	ptr->n = splitPos;						  /*No. of itens for left splitted node*/
	(*novoNo)->n = M - 1 - splitPos;		  /*No. of itens for right splitted node*/
	for (i = 0; i < (*novoNo)->n; i++)
	{
		(*novoNo)->p[i] = ptr->p[i + splitPos + 1];
		if (i < (*novoNo)->n - 1)
			(*novoNo)->pessoa[i] = ptr->pessoa[i + splitPos + 1];
		else
			strcpy((*novoNo)->pessoa[i].nome, ultNome);
	}
	(*novoNo)->p[(*novoNo)->n] = ultPtr;
	return Inseriu;
} /*Fim ins()*/

void busca(Node *raiz, char nome[100]) {
    int pos, i, n;
    Node *ptr = raiz;
    printf("Caminho de busca:\n");
    while (ptr) {
        n = ptr->n;
        for (i = 0; i < n; i++)
            printf(" %s", ptr->pessoa[i].nome);
        printf("\n");

        pos = buscaChave(ptr, nome, ptr->pessoa, n);
        
        // Verifica se o nome foi encontrado na posição correta
        if (pos < n && strcmp(nome, ptr->pessoa[pos].nome) == 0) {
            printf("Nome %s encontrado na posicao %d do ultimo no apresentado.\n", nome, pos);
            return;
        }
        
        // Continua a busca no próximo nó
        ptr = ptr->p[pos];
    }
    printf("Nome %s nao encontrado.\n", nome);
}

int buscaChave(Node *raiz, char nome[100], Pessoas *itens_arr, int n) {
    int pos = 0;
    while (pos < n && strcmp(nome, itens_arr[pos].nome) > 0) {
        pos++;
    }
    return pos;
}

void excluirNo(Node *raiz, char nome[100])
{
	Node *raizIni;
	StatusChave status;
	status = del(raiz, raiz, nome);
	switch (status)
	{
	case NaoEncontrado:
		printf("Nome %s nao encontrado.\n", nome);
		break;
	case Poucasitens:
		raizIni = raiz;
		raiz = raiz->p[0];
		free(raizIni);
		break;
	default:
		return;
	} /*Fim switch*/
} /*Fim excluirNo()*/

StatusChave del(Node *raiz, Node *ptr, char nome[100])
{
	int pos, i, pivot, n, min;
	Pessoas *itens_arr;
	StatusChave status;
	Node **p, *esq_ptr, *dir_ptr;

	if (ptr == NULL)
		return NaoEncontrado;
	/*Atribui status do nó*/
	n = ptr->n;
	itens_arr = ptr->pessoa;
	p = ptr->p;
	min = (M - 1) / 2; /*Numero mínimo de itens*/

	// Busca pela chave a ser removida
	pos = buscaChave(raiz, nome, itens_arr, n);
	// p é uma folha
	if (p[0] == NULL)
	{
		if (pos == n || strcmp(nome, itens_arr[pos].nome) < 0)
			return NaoEncontrado;
		/*Desloca itens e ponteiros para a esquerda*/
		for (i = pos + 1; i < n; i++)
		{
			itens_arr[i - 1] = itens_arr[i];
			p[i] = p[i + 1];
		}
		return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : Poucasitens;
	} /*Fim if */

	// Se chave encontrada mas p não é folha
	if (pos < n && strcmp(nome, itens_arr[pos].nome) == 0)
	{
		Node *qp = p[pos], *qp1;
		int nkey;
		while (1)
		{
			nkey = qp->n;
			qp1 = qp->p[nkey];
			if (qp1 == NULL)
				break;
			qp = qp1;
		} /*Fim while*/
		itens_arr[pos] = qp->pessoa[nkey - 1];
		strcpy(qp->pessoa[nkey - 1].nome, nome);
	} /*Fim if */
	status = del(raiz, p[pos], nome);
	if (status != Poucasitens)
		return status;

	if (pos > 0 && p[pos - 1]->n > min)
	{
		pivot = pos - 1; /*pivo para nós esquerdo e direito*/
		esq_ptr = p[pivot];
		dir_ptr = p[pos];
		/*Atribui status para nó da direita*/
		dir_ptr->p[dir_ptr->n + 1] = dir_ptr->p[dir_ptr->n];
		for (i = dir_ptr->n; i > 0; i--)
		{
			dir_ptr->pessoa[i] = dir_ptr->pessoa[i - 1];
			dir_ptr->p[i] = dir_ptr->p[i - 1];
		}
		dir_ptr->n++;
		dir_ptr->pessoa[0] = itens_arr[pivot];
		dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
		itens_arr[pivot] = esq_ptr->pessoa[--esq_ptr->n];
		return Sucesso;
	} /*Fim if */
	if (pos < n && p[pos + 1]->n > min)
	{
		pivot = pos; /*pivo para nós esquerdo e direito*/
		esq_ptr = p[pivot];
		dir_ptr = p[pivot + 1];
		/*Atribui status para nós da esquerda*/
		esq_ptr->pessoa[esq_ptr->n] = itens_arr[pivot];
		esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
		itens_arr[pivot] = dir_ptr->pessoa[0];
		esq_ptr->n++;
		dir_ptr->n--;
		for (i = 0; i < dir_ptr->n; i++)
		{
			dir_ptr->pessoa[i] = dir_ptr->pessoa[i + 1];
			dir_ptr->p[i] = dir_ptr->p[i + 1];
		} /*Fim for*/
		dir_ptr->p[dir_ptr->n] = dir_ptr->p[dir_ptr->n + 1];
		return Sucesso;
	} /*Fim if */

	if (pos == n)
		pivot = pos - 1;
	else
		pivot = pos;

	esq_ptr = p[pivot];
	dir_ptr = p[pivot + 1];
	/*realiza fusão (merge) dos nós da direita e esquerda*/
	esq_ptr->pessoa[esq_ptr->n] = itens_arr[pivot];
	esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
	for (i = 0; i < dir_ptr->n; i++)
	{
		esq_ptr->pessoa[esq_ptr->n + 1 + i] = dir_ptr->pessoa[i];
		esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
	}
	esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
	free(dir_ptr); /*Remove nó da direita*/
	for (i = pos + 1; i < n; i++)
	{
		itens_arr[i - 1] = itens_arr[i];
		p[i] = p[i + 1];
	}
	return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : Poucasitens;
} /*Fim del()*/

/*
 * A impressão da árvore é feita como se ela estivesse na vertical ao invés da horizontal, portanto cada nó é impresso na vertical,
 * com a menor chave do nó na parte inferior do nó
 */
void imprime_arvore(Node *ptr, int nivel)
{
	if (ptr != NULL)
	{
		char indent[10] = "";
		for (int i = 0; i < nivel; i++)
		{
			strcat(indent, "\t");
		}

		for (int i = ptr->n; i > 0; i--)
		{
			imprime_arvore(ptr->p[i], nivel + 1);
			printf("%s", indent);
			printf("%s\n", ptr->pessoa[i - 1].nome);
		}
		imprime_arvore(ptr->p[0], nivel + 1);
	}
}

void imprime_no(Node *ptr)
{
	if (ptr != NULL)
	{
		for (int i = 0; i < ptr->n; i++)
		{
			printf("%s ", ptr->pessoa[i].nome);
		}
		printf("\n");
	}
}