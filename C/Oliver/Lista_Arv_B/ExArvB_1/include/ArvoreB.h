#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#define M 3 //M refere-se � ordem da �rvore, ou seja, quantos filhos cada n� pode ter
            //M-1 � o n�mero m�ximo de chaves que um n� pode ter

typedef struct node Node;
typedef struct pessoa Pessoas;
typedef enum statusChave StatusChave;

Node *inserirNo(Node *raiz, char nome[100]);
StatusChave ins(Node *ptr, char nome[100], char nomeInicial[100], Node **novoNo);
void busca(Node *raiz, char nome[100]);
int buscaChave(Node *raiz, char nome[100], Pessoas *chaves_arr, int n);
void excluirNo(Node *raiz, char nome[100]);
StatusChave del(Node *raiz, Node *ptr, char nome[100]);
void imprime_arvore(Node *ptr, int nivel);
void imprime_no(Node *ptr);

#endif // ARVOREB_H_INCLUDED
