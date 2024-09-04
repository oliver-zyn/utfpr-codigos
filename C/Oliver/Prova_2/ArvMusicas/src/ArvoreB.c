#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

struct musica {
	char musica[100];
};

struct node
{
	int n;			   /* n < M No. de chaves no n� sempre � menor que a ordem da �rvore B*/
	Musica musica[M - 1]; /*array de chaves*/
	struct node *p[M]; /* array de ponteiros */
};

enum statusChave {
	Duplicado,
	NaoEncontrado,
	Sucesso,
	Inseriu,
	PoucasChaves,
};

Node *inserirNo(Node *raiz, char musica[100])
{
	Node *novoNo;
	char musicaInicial[100];
	StatusChave status;
	status = ins(raiz, musica, musicaInicial, &novoNo);
	if (status == Duplicado)
		printf("Musica ja inserida.\n");
	if (status == Inseriu)
	{
		Node *raizIni = raiz;
		raiz = (Node *)malloc(sizeof(Node));
		raiz->n = 1;
		strcpy(raiz->musica[0].musica, musicaInicial);
		raiz->p[0] = raizIni;
		raiz->p[1] = novoNo;
	}
	return raiz;
}

StatusChave ins(Node *ptr, char musica[100], char musicaInicial[100], Node **novoNo)
{
	Node *novoPtr, *ultPtr;
	int pos, i, n, splitPos;
	char novomusica[100], ultmusica[100];
	StatusChave status;
	if (ptr == NULL)
	{
		*novoNo = NULL;
		strcpy(musicaInicial, musica);
		return Inseriu;
	}
	n = ptr->n;
	pos = buscaChave(ptr, musica, ptr->musica, n);
	if (pos < n && strcmp(musica, ptr->musica[pos].musica) == 0)
		return Duplicado;
	status = ins(ptr->p[pos], musica, novomusica, &novoPtr);
	if (status != Inseriu)
		return status;
	/*If chaves in node is less than M-1 where M is order of B tree*/
	if (n < M - 1)
	{
		pos = buscaChave(ptr, novomusica, ptr->musica, n);
		/*Shifting the chave and pointer right for inserting the new chave*/
		for (i = n; i > pos; i--)
		{
			ptr->musica[i] = ptr->musica[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		/*chave is inserted at exact location*/
		strcpy(ptr->musica[pos].musica, novomusica);
		ptr->p[pos + 1] = novoPtr;
		++ptr->n; /*incrementing the number of chaves in node*/
		return Sucesso;
	} /*Fim if */
	/*If chaves in nodes are maximum and position of node to be inserted is last*/
	if (pos == M - 1)
	{
		strcpy(ultmusica, novomusica);
		ultPtr = novoPtr;
	}
	else
	{ /*If chaves in node are maximum and position of node to be inserted is not last*/
		strcpy(ultmusica, ptr->musica[M - 2].musica);
		ultPtr = ptr->p[M - 1];
		for (i = M - 2; i > pos; i--)
		{
			ptr->musica[i] = ptr->musica[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		strcpy(ptr->musica[pos].musica, novomusica);
		ptr->p[pos + 1] = novoPtr;
	}
	splitPos = (M - 1) / 2;
	strcpy(musicaInicial, ptr->musica[splitPos].musica);

	(*novoNo) = (Node *)malloc(sizeof(Node)); /*Right node after split*/
	ptr->n = splitPos;						  /*No. of chaves for left splitted node*/
	(*novoNo)->n = M - 1 - splitPos;		  /*No. of chaves for right splitted node*/
	for (i = 0; i < (*novoNo)->n; i++)
	{
		(*novoNo)->p[i] = ptr->p[i + splitPos + 1];
		if (i < (*novoNo)->n - 1)
			(*novoNo)->musica[i] = ptr->musica[i + splitPos + 1];
		else
			strcpy((*novoNo)->musica[i].musica, ultmusica);
	}
	(*novoNo)->p[(*novoNo)->n] = ultPtr;
	return Inseriu;
} /*Fim ins()*/

void busca(Node *raiz, char musica[100]) {
    int pos, i, n;
    Node *ptr = raiz;
    printf("Caminho de busca:\n");
    while (ptr) {
        n = ptr->n;
        for (i = 0; i < n; i++)
            printf(" %s", ptr->musica[i].musica);
        printf("\n");

        pos = buscaChave(ptr, musica, ptr->musica, n);
        
        // Verifica se o musica foi encontrado na posição correta
        if (pos < n && strcmp(musica, ptr->musica[pos].musica) == 0) {
            printf("musica %s encontrado na posicao %d do ultimo no apresentado.\n", musica, pos);
            return;
        }
        
        // Continua a busca no próximo nó
        ptr = ptr->p[pos];
    }
    printf("musica %s nao encontrado.\n", musica);
}

int buscaChave(Node *raiz, char musica[100], Musica *chaves_arr, int n) {
    int pos = 0;
    while (pos < n && strcmp(musica, chaves_arr[pos].musica) > 0) {
        pos++;
    }
    return pos;
}

void excluirNo(Node *raiz, char musica[100])
{
	Node *raizIni;
	StatusChave status;
	status = del(raiz, raiz, musica);
	switch (status)
	{
	case NaoEncontrado:
		printf("musica %s nao encontrado.\n", musica);
		break;
	case PoucasChaves:
		raizIni = raiz;
		raiz = raiz->p[0];
		free(raizIni);
		break;
	default:
		return;
	} /*Fim switch*/
} /*Fim excluirNo()*/

StatusChave del(Node *raiz, Node *ptr, char musica[100])
{
	int pos, i, pivot, n, min;
	Musica *chaves_arr;
	StatusChave status;
	Node **p, *esq_ptr, *dir_ptr;

	if (ptr == NULL)
		return NaoEncontrado;
	/*Atribui status do nó*/
	n = ptr->n;
	chaves_arr = ptr->musica;
	p = ptr->p;
	min = (M - 1) / 2; /*Numero mínimo de chaves*/

	// Busca pela chave a ser removida
	pos = buscaChave(raiz, musica, chaves_arr, n);
	// p é uma folha
	if (p[0] == NULL)
	{
		if (pos == n || strcmp(musica, chaves_arr[pos].musica) < 0)
			return NaoEncontrado;
		/*Desloca chaves e ponteiros para a esquerda*/
		for (i = pos + 1; i < n; i++)
		{
			chaves_arr[i - 1] = chaves_arr[i];
			p[i] = p[i + 1];
		}
		return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
	} /*Fim if */

	// Se chave encontrada mas p não é folha
	if (pos < n && strcmp(musica, chaves_arr[pos].musica) == 0)
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
		chaves_arr[pos] = qp->musica[nkey - 1];
		strcpy(qp->musica[nkey - 1].musica, musica);
	} /*Fim if */
	status = del(raiz, p[pos], musica);
	if (status != PoucasChaves)
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
			dir_ptr->musica[i] = dir_ptr->musica[i - 1];
			dir_ptr->p[i] = dir_ptr->p[i - 1];
		}
		dir_ptr->n++;
		dir_ptr->musica[0] = chaves_arr[pivot];
		dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
		chaves_arr[pivot] = esq_ptr->musica[--esq_ptr->n];
		return Sucesso;
	} /*Fim if */
	if (pos < n && p[pos + 1]->n > min)
	{
		pivot = pos; /*pivo para nós esquerdo e direito*/
		esq_ptr = p[pivot];
		dir_ptr = p[pivot + 1];
		/*Atribui status para nós da esquerda*/
		esq_ptr->musica[esq_ptr->n] = chaves_arr[pivot];
		esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
		chaves_arr[pivot] = dir_ptr->musica[0];
		esq_ptr->n++;
		dir_ptr->n--;
		for (i = 0; i < dir_ptr->n; i++)
		{
			dir_ptr->musica[i] = dir_ptr->musica[i + 1];
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
	esq_ptr->musica[esq_ptr->n] = chaves_arr[pivot];
	esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
	for (i = 0; i < dir_ptr->n; i++)
	{
		esq_ptr->musica[esq_ptr->n + 1 + i] = dir_ptr->musica[i];
		esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
	}
	esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
	free(dir_ptr); /*Remove nó da direita*/
	for (i = pos + 1; i < n; i++)
	{
		chaves_arr[i - 1] = chaves_arr[i];
		p[i] = p[i + 1];
	}
	return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
} /*Fim del()*/

/*
 * A impressão da árvore é feita como se ela estivesse na vertical ao invés da horizontal, portanto cada nó é impresso na vertical,
 * com a menor chave do nó na parte inferior do nó
 */
void imprime_arvore(Node *ptr, int nivel)
{
	if (ptr != NULL)
	{
		char indent[10] = "Musica ";

		for (int i = ptr->n; i > 0; i--)
		{
			imprime_arvore(ptr->p[i], nivel + 1);
			printf("%s", indent);
			printf("%s\n", ptr->musica[i - 1].musica);
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
			printf("%s ", ptr->musica[i].musica);
		}
		printf("\n");
	}
}