#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define M 4
#define CUSTO_MINERACAO 10
#define SALDO_VITORIA 1000

typedef struct node Node;
typedef struct item Item;
typedef struct minerio Minerio;
typedef enum statusChave StatusChave;

Node *inserirNo(Node *raiz, Item novoItem);
StatusChave ins(Node *ptr, Item novoItem, Item *itemPromovido, Node **novoNo);
StatusChave del(Node *raiz, Node *ptr, char nome[100]);
void excluirNo(Node *raiz, char nome[100]);
int buscaChave(Node *ptr, char nome[50], Item *itens, int n);
Item* buscaItem(Node *raiz, char nome[50]);
void venderItem(Node *raiz, char nome[50], int quantidade, int *saldo);
void imprimeInventario(Node *ptr, int nivel);
Minerio selecionarMinerio(Minerio *minerios, int numMinerios);
void minerar(Node **inventario, int *saldo);
int verificarFimJogo(int saldo);

#endif // ARVOREB_H_INCLUDED
