#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

struct playlist
{
	char musica_Pedro[100];
};

struct node
{
	int n;			   /* n < M No. de chaves no n� sempre � menor que a ordem da �rvore B*/
	Playlist nomes[M - 1]; /*array de chaves*/
	struct node *p[M]; /* array de ponteiros */
};

enum statusChave
{
	Duplicado,
	NaoEncontrado,
	Sucesso,
	Inseriu,
	PoucasChaves,
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
		strcpy(raiz->nomes[0].musica_Pedro, nomeInicial);
		raiz->p[0] = raizIni;
		raiz->p[1] = novoNo;
	} /*Fim if */
	return raiz;
} /*Fim inserir()*/

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
	pos = buscaChave(ptr, nome, ptr->nomes, n);
	if (pos < n && strcmp(nome, ptr->nomes[pos].musica_Pedro) == 0)
		return Duplicado;
	status = ins(ptr->p[pos], nome, novoNome, &novoPtr);
	if (status != Inseriu)
		return status;
	/*If chaves in node is less than M-1 where M is order of B tree*/
	if (n < M - 1)
	{
		pos = buscaChave(ptr, novoNome, ptr->nomes, n);
		/*Shiftinqg the chave and pointer right for inserting the new chave*/
		for (i = n; i > pos; i--)
		{
			ptr->nomes[i] = ptr->nomes[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		/*chave is inserted at exact location*/
		strcpy(ptr->nomes[pos].musica_Pedro, novoNome);
		ptr->p[pos + 1] = novoPtr;
		++ptr->n; /*incrementing the number of chaves in node*/
		return Sucesso;
	} /*Fim if */
	/*If chaves in nodes are maximum and position of node to be inserted is last*/
	if (pos == M - 1)
	{
		strcpy(ultNome, novoNome);
		ultPtr = novoPtr;
	}
	else
	{ /*If chaves in node are maximum and position of node to be inserted is not last*/
		strcpy(ultNome, ptr->nomes[M - 2].musica_Pedro);
		ultPtr = ptr->p[M - 1];
		for (i = M - 2; i > pos; i--)
		{
			ptr->nomes[i] = ptr->nomes[i - 1];
			ptr->p[i + 1] = ptr->p[i];
		}
		strcpy(ptr->nomes[pos].musica_Pedro, novoNome);
		ptr->p[pos + 1] = novoPtr;
	}
	splitPos = (M - 1) / 2;
	strcpy(nomeInicial, ptr->nomes[splitPos].musica_Pedro);

	(*novoNo) = (Node *)malloc(sizeof(Node)); /*Right node after split*/
	ptr->n = splitPos;						  /*No. of chaves for left splitted node*/
	(*novoNo)->n = M - 1 - splitPos;		  /*No. of chaves for right splitted node*/
	for (i = 0; i < (*novoNo)->n; i++)
	{
		(*novoNo)->p[i] = ptr->p[i + splitPos + 1];
		if (i < (*novoNo)->n - 1)
			(*novoNo)->nomes[i] = ptr->nomes[i + splitPos + 1];
		else
			strcpy((*novoNo)->nomes[i].musica_Pedro, ultNome);
			
	}
	(*novoNo)->p[(*novoNo)->n] = ultPtr;
	return Inseriu;
} /*Fim ins()*/

void busca(Node *raiz, char nome[100])
{
	int pos, i, n;
	Node *ptr = raiz;
	printf("Caminho de busca:\n");
	while (ptr)
	{
		n = ptr->n;
		for (i = 0; i < ptr->n; i++)
			printf(" %s", ptr->nomes[i].musica_Pedro);
		printf("\n");
		pos = buscaChave(raiz, nome, ptr->nomes, n);
		if (pos < n && strcmp(nome, ptr->nomes[pos].musica_Pedro) == 0)
		{
			printf("Nome %s encontrado na posicao %d do ultimo no apresentado.\n", nome, pos);
			return;
		}
		ptr = ptr->p[pos];
	}
	printf("Nome %s nao encontrado.\n", nome);
} /*Fim busca()*/

int buscaChave(Node *raiz, char nome[100], Playlist *chaves_arr, int n)
{
	int pos = 0;
	while (pos < n && strcmp(nome, chaves_arr[pos].musica_Pedro) > 0)
		pos++;
	return pos;
} /*Fim buscaChave()*/

void excluirNo(Node *raiz, char nome[100])
{
	Node *raizIni;
	StatusChave status;
	status = del(raiz, raiz, nome);
	switch (status)
	{
	case NaoEncontrado:
		printf("nome %s nao encontrado.\n", nome);
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

StatusChave del(Node *raiz, Node *ptr, char nome[100])
{
	int pos, i, pivot, n, min;
	Playlist *chaves_arr;
	StatusChave status;
	Node **p, *esq_ptr, *dir_ptr;

	if (ptr == NULL)
		return NaoEncontrado;
	/*Atribui status do no*/
	n = ptr->n;
	chaves_arr = ptr->nomes;
	p = ptr->p;
	min = (M - 1) / 2; /*Numero minimode chaves*/

	// Busca pela chave a ser removida
	pos = buscaChave(raiz, nome, chaves_arr, n);
	// p � uma folha
	if (p[0] == NULL)
	{
		if (pos == n || strcmp(nome, chaves_arr[pos].musica_Pedro) < 0)
			return NaoEncontrado;
		/*Desloca chaves e ponteiros para a esquerda*/
		for (i = pos + 1; i < n; i++)
		{
			chaves_arr[i - 1] = chaves_arr[i];
			p[i] = p[i + 1];
		}
		return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
	} /*Fim if */

	// Se chave encontrada mas p nao � folha
	if (pos < n && strcmp(nome, chaves_arr[pos].musica_Pedro) == 0)
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
		chaves_arr[pos] = qp->nomes[nkey - 1];
		strcpy(qp->nomes[nkey - 1].musica_Pedro, nome);
	} /*Fim if */
	status = del(raiz, p[pos], nome);
	if (status != PoucasChaves)
		return status;

	if (pos > 0 && p[pos - 1]->n > min)
	{
		pivot = pos - 1; /*pivo para n�s esquerdo e direito*/
		esq_ptr = p[pivot];
		dir_ptr = p[pos];
		/*Atribui status para n� da direita*/
		dir_ptr->p[dir_ptr->n + 1] = dir_ptr->p[dir_ptr->n];
		for (i = dir_ptr->n; i > 0; i--)
		{
			dir_ptr->nomes[i] = dir_ptr->nomes[i - 1];
			dir_ptr->p[i] = dir_ptr->p[i - 1];
		}
		dir_ptr->n++;
		dir_ptr->nomes[0] = chaves_arr[pivot];
		dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
		chaves_arr[pivot] = esq_ptr->nomes[--esq_ptr->n];
		return Sucesso;
	} /*Fim if */
	if (pos < n && p[pos + 1]->n > min)
	{
		pivot = pos; /*pivo para n�s esquerdo e direito*/
		esq_ptr = p[pivot];
		dir_ptr = p[pivot + 1];
		/*Atribui status para n�s da esquerda*/
		esq_ptr->nomes[esq_ptr->n] = chaves_arr[pivot];
		esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
		chaves_arr[pivot] = dir_ptr->nomes[0];
		esq_ptr->n++;
		dir_ptr->n--;
		for (i = 0; i < dir_ptr->n; i++)
		{
			dir_ptr->nomes[i] = dir_ptr->nomes[i + 1];
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
	/*realiza fus�o (merge) dos n�s da direita e esquerda*/
	esq_ptr->nomes[esq_ptr->n] = chaves_arr[pivot];
	esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
	for (i = 0; i < dir_ptr->n; i++)
	{
		esq_ptr->nomes[esq_ptr->n + 1 + i] = dir_ptr->nomes[i];
		esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
	}
	esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
	free(dir_ptr); /*Remove n� da direita*/
	for (i = pos + 1; i < n; i++)
	{
		chaves_arr[i - 1] = chaves_arr[i];
		p[i] = p[i + 1];
	}
	return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : PoucasChaves;
} /*Fim del()*/

/*
 * A impressao da �rvore � feita como se ela estivesse na vertical ao inv�s da horizontal, portanto cada n� � impresso na vertical,
 * com a menor chave do n� na parte inferior do n�
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
			printf("%s\n", ptr->nomes[i - 1].musica_Pedro);
		}
		imprime_arvore(ptr->p[0], nivel + 1);
	}
}

void imprime_playlist(Node *ptr, int nivel)
{
	if (ptr != NULL)
	{
		char indent[10] = "";
		for (int i = 0; i < nivel; i++)
		{
			strcat(indent, "\n");
		}

		for (int i = ptr->n; i > 0; i--)
		{
			imprime_playlist(ptr->p[i], nivel + 1);
			printf("Musica %s\n", ptr->nomes[i - 1].musica_Pedro);
		}
		imprime_playlist(ptr->p[0], nivel + 1);
	}
}

void imprime_no(Node *ptr)
{
	if (ptr != NULL)
	{
		for (int i = 0; i < ptr->n; i++)
		{
			printf("%s", ptr->nomes[i].musica_Pedro);
		}
		printf("\n");
	}
}
