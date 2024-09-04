#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ArvoreB.h"

/*
Jogo de mineração

A arvore irá armazenar o inventario de minérios do jogador
Terá uma opção de minerar, onde o jogador irá ter a chance de minerar itens raros (a mineração pode ter um custo base para realizar)
Ao encontrar um item raro, ele sera armazenado no inventario
O usuario podera vender seus itens, o saldo será somado na conta dele
O jogo pode finalizar caso o usuario chegue a um valor especifico na conta ou esteja sem saldo na conta

 */

struct item {
    int id;
    char nome[50];
    char tipo[30];
    int valor;
    int quantidade;
};

struct minerio {
    int id;
    char nome[50];
    char tipo[30];
    int valor;
    int chance;
};

struct node {
	int n;			   /* n < M No. de itens no n� sempre � menor que a ordem da �rvore B*/
	Item itens[M - 1]; /*array de itens*/
	struct node *p[M]; /* array de ponteiros */
};

enum statusChave {
	Duplicado,
	NaoEncontrado,
	Sucesso,
	Inseriu,
	Poucasitens,
};

Node *inserirNo(Node *raiz, Item novoItem) {
    Node *novoNo;
    Item itemPromovido;
    StatusChave status;
    status = ins(raiz, novoItem, &itemPromovido, &novoNo);
    if (status == Duplicado) {
        printf("Item já inserido no inventário.\n");
        return raiz;
    }
    if (status == Inseriu) {
        Node *raizAntiga = raiz;
        raiz = (Node *)malloc(sizeof(Node));
        raiz->n = 1;
        raiz->itens[0] = itemPromovido;
        raiz->p[0] = raizAntiga;
        raiz->p[1] = novoNo;
    }
    return raiz;
}

StatusChave ins(Node *ptr, Item novoItem, Item *itemPromovido, Node **novoNo) {
    Node *novoPtr, *ultPtr;
    int pos, i, n, splitPos;
    Item ultimoItem;
    StatusChave status;

    if (ptr == NULL) {
        *novoNo = NULL;
        *itemPromovido = novoItem;
        return Inseriu;
    }

    n = ptr->n;
    pos = buscaChave(ptr, novoItem.nome, ptr->itens, n);
    if (pos < n && strcmp(novoItem.nome, ptr->itens[pos].nome) == 0) {
        ptr->itens[pos].quantidade += novoItem.quantidade;
        return Duplicado;
    }

    status = ins(ptr->p[pos], novoItem, &ultimoItem, &novoPtr);
    if (status != Inseriu) return status;

    if (n < M - 1) {
        pos = buscaChave(ptr, ultimoItem.nome, ptr->itens, n);
        for (i = n; i > pos; i--) {
            ptr->itens[i] = ptr->itens[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->itens[pos] = ultimoItem;
        ptr->p[pos + 1] = novoPtr;
        ptr->n++;
        return Sucesso;
    }

    if (pos == M - 1) {
        ultimoItem = novoItem;
        ultPtr = novoPtr;
    } else {
        ultimoItem = ptr->itens[M - 2];
        ultPtr = ptr->p[M - 1];
        for (i = M - 2; i > pos; i--) {
            ptr->itens[i] = ptr->itens[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->itens[pos] = novoItem;
        ptr->p[pos + 1] = novoPtr;
    }

    splitPos = (M - 1) / 2;
    *itemPromovido = ptr->itens[splitPos];

    *novoNo = (Node *)malloc(sizeof(Node));
    ptr->n = splitPos;
    (*novoNo)->n = M - 1 - splitPos;
    for (i = 0; i < (*novoNo)->n; i++) {
        (*novoNo)->p[i] = ptr->p[i + splitPos + 1];
        if (i < (*novoNo)->n) {
            (*novoNo)->itens[i] = ptr->itens[i + splitPos + 1];
        }
    }
    (*novoNo)->p[(*novoNo)->n] = ultPtr;

    return Inseriu;
}

int buscaChave(Node *ptr, char nome[50], Item *itens, int n) {
    int pos = 0;
    while (pos < n && strcmp(nome, itens[pos].nome) > 0) {
        pos++;
    }
    return pos;
}

Item* buscaItem(Node *raiz, char nome[50]) {
    Node *ptr = raiz;
    while (ptr) {
        int pos = buscaChave(ptr, nome, ptr->itens, ptr->n);
        if (pos < ptr->n && strcmp(nome, ptr->itens[pos].nome) == 0) {
            return &ptr->itens[pos];
        }
        ptr = ptr->p[pos];
    }
    return NULL;
}

void venderItem(Node *raiz, char nome[50], int quantidade, int *saldo) {
    Item *item = buscaItem(raiz, nome);
    if (item) {
        if (item->quantidade >= quantidade) {
            *saldo += quantidade * item->valor;
            item->quantidade -= quantidade;
            if (item->quantidade == 0) {
                excluirNo(raiz, nome); // Função excluir adaptada para remover o item
            }
            printf("Você vendeu %d unidades de %s.\n", quantidade, nome);
        } else {
            printf("Quantidade insuficiente de %s no inventário.\n", nome);
        }
    } else {
        printf("Item %s não encontrado no inventário.\n", nome);
    }
}

void excluirNo(Node *raiz, char nome[100]) {
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
	}
}

StatusChave del(Node *raiz, Node *ptr, char nome[100]) {
	int pos, i, pivot, n, min;
	Item *itens_arr;
	StatusChave status;
	Node **p, *esq_ptr, *dir_ptr;

	if (ptr == NULL)
		return NaoEncontrado;
	n = ptr->n;
	itens_arr = ptr->itens;
	p = ptr->p;
	min = (M - 1) / 2;

	pos = buscaChave(raiz, nome, itens_arr, n);
	if (p[0] == NULL)
	{
		if (pos == n || strcmp(nome, itens_arr[pos].nome) < 0)
			return NaoEncontrado;
		for (i = pos + 1; i < n; i++)
		{
			itens_arr[i - 1] = itens_arr[i];
			p[i] = p[i + 1];
		}
		return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : Poucasitens;
	}

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
		}
		itens_arr[pos] = qp->itens[nkey - 1];
		strcpy(qp->itens[nkey - 1].nome, nome);
	}
	status = del(raiz, p[pos], nome);
	if (status != Poucasitens)
		return status;

	if (pos > 0 && p[pos - 1]->n > min)
	{
		pivot = pos - 1;
		esq_ptr = p[pivot];
		dir_ptr = p[pos];
		dir_ptr->p[dir_ptr->n + 1] = dir_ptr->p[dir_ptr->n];
		for (i = dir_ptr->n; i > 0; i--)
		{
			dir_ptr->itens[i] = dir_ptr->itens[i - 1];
			dir_ptr->p[i] = dir_ptr->p[i - 1];
		}
		dir_ptr->n++;
		dir_ptr->itens[0] = itens_arr[pivot];
		dir_ptr->p[0] = esq_ptr->p[esq_ptr->n];
		itens_arr[pivot] = esq_ptr->itens[--esq_ptr->n];
		return Sucesso;
	}
	if (pos < n && p[pos + 1]->n > min)
	{
		pivot = pos;
		esq_ptr = p[pivot];
		dir_ptr = p[pivot + 1];
		esq_ptr->itens[esq_ptr->n] = itens_arr[pivot];
		esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
		itens_arr[pivot] = dir_ptr->itens[0];
		esq_ptr->n++;
		dir_ptr->n--;
		for (i = 0; i < dir_ptr->n; i++)
		{
			dir_ptr->itens[i] = dir_ptr->itens[i + 1];
			dir_ptr->p[i] = dir_ptr->p[i + 1];
		}
		dir_ptr->p[dir_ptr->n] = dir_ptr->p[dir_ptr->n + 1];
		return Sucesso;
	}

	if (pos == n)
		pivot = pos - 1;
	else
		pivot = pos;

	esq_ptr = p[pivot];
	dir_ptr = p[pivot + 1];
	esq_ptr->itens[esq_ptr->n] = itens_arr[pivot];
	esq_ptr->p[esq_ptr->n + 1] = dir_ptr->p[0];
	for (i = 0; i < dir_ptr->n; i++)
	{
		esq_ptr->itens[esq_ptr->n + 1 + i] = dir_ptr->itens[i];
		esq_ptr->p[esq_ptr->n + 2 + i] = dir_ptr->p[i + 1];
	}
	esq_ptr->n = esq_ptr->n + dir_ptr->n + 1;
	free(dir_ptr);
	for (i = pos + 1; i < n; i++)
	{
		itens_arr[i - 1] = itens_arr[i];
		p[i] = p[i + 1];
	}
	return --ptr->n >= (ptr == raiz ? 1 : min) ? Sucesso : Poucasitens;
}

Minerio selecionarMinerio(Minerio *minerios, int numMinerios) {
    int chance = rand() % 100;
    int acumulado = 0;
    for (int i = 0; i < numMinerios; i++) {
        acumulado += minerios[i].chance;
        if (chance < acumulado) {
            return minerios[i];
        }
    }
    return minerios[numMinerios - 1]; // Fallback, should never happen
}

void minerar(Node **inventario, int *saldo) {
    if (*saldo < CUSTO_MINERACAO) {
        printf("Saldo insuficiente para minerar.\n");
        return;
    }

    *saldo -= CUSTO_MINERACAO;

    Minerio minerios[] = {
        {1, "Diamante", "Raro", 500, 5},
        {2, "Ouro", "Raro", 200, 10},
        {3, "Prata", "Raro", 150, 10},
        {4, "Platina", "Raro", 300, 10},
        {5, "Esmeralda", "Raro", 400, 10},
        {6, "Rubi", "Raro", 350, 10},
        {7, "Safira", "Raro", 250, 10},
        {8, "Ferro", "Comum", 50, 10},
        {9, "Cobre", "Comum", 30, 10},
        {10, "Carvao", "Comum", 20, 15},
    };
    int numMinerios = sizeof(minerios) / sizeof(minerios[0]);

    Minerio minerioSelecionado = selecionarMinerio(minerios, numMinerios);

    Item minerio = {minerioSelecionado.id, "", "", minerioSelecionado.valor, 1};
    strcpy(minerio.nome, minerioSelecionado.nome);
    strcpy(minerio.tipo, minerioSelecionado.tipo);

    printf("Voce encontrou %s!\n", minerio.nome);

    *inventario = inserirNo(*inventario, minerio);
}

int verificarFimJogo(int saldo) {
    if (saldo >= SALDO_VITORIA) {
        printf("Parabens! Voce atingiu o saldo de %d e venceu o jogo!\n", saldo);
        return 1;
    }
    if (saldo < CUSTO_MINERACAO) {
        printf("Saldo insuficiente para continuar minerando. Voce perdeu o jogo.\n");
        return 1;
    }
    return 0;
}

void imprimeInventario(Node *ptr, int nivel) {
    if (ptr != NULL) {
        for (int i = 0; i < ptr->n; i++) {
            imprimeInventario(ptr->p[i], nivel + 1);
            printf("%*s%s (Quantidade: %d, Valor: %d)\n", nivel * 4, "", ptr->itens[i].nome, ptr->itens[i].quantidade, ptr->itens[i].valor);
        }
        imprimeInventario(ptr->p[ptr->n], nivel + 1);
    }
}