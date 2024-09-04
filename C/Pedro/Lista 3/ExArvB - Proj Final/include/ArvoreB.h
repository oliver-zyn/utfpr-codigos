#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define M 3 //M refere-se � ordem da �rvore, ou seja, quantos filhos cada n� pode ter
            //M-1 � o n�mero m�ximo de chaves que um n� pode ter

typedef struct node Node;
typedef enum statusChave StatusChave;

Node* inserirNo(Node *raiz, int chave);
StatusChave ins(Node *ptr, int chave, int *chaveIni, Node **novoNo);
void busca(Node *raiz, int chave);
int buscaChave(Node *raiz, int chave, int *chaves_arr, int n);
Node* excluirNo(Node *raiz, int chave);
StatusChave del(Node *raiz, Node *ptr, int chave);
void imprime_arvore(Node *ptr, int nivel);
void imprime_no(Node *ptr);

// Funções do jogo

const char* getName(int nome);
void imprime_inventario(Node *ptr, int nivel);
int roda_roleta(int saldo, int preco);
int buscaValor(Node *raiz, int chave);

#endif // ARVOREB_H_INCLUDED