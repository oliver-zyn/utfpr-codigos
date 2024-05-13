
typedef struct no_arvore* NoArvAVL;

NoArvAVL* cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
int insere_ArvAVL(NoArvAVL *raiz, char nome[100], int idade, float pontuacao);
int remove_ArvAVL(NoArvAVL *raiz, char nome[100]);
int estaVazia_ArvAVL(NoArvAVL *raiz);
int altura_ArvAVL(NoArvAVL *raiz);
int totalNO_ArvAVL(NoArvAVL *raiz);
int consulta_ArvAVL(NoArvAVL *raiz, char nome[100]);
void preOrdem_ArvAVL(NoArvAVL *raiz, char nome[100]);
void emOrdem_ArvAVL(NoArvAVL *raiz, char nome[100]);
void posOrdem_ArvAVL(NoArvAVL *raiz, char nome[100]);
struct no_arvore* procuraMenorNome(struct no_arvore* atual);
void resultadoPontuacao(NoArvAVL *raiz, char nome1[100], int resultado1, char nome2[100], int resultado2);
void alteraPontuacao_Participante(NoArvAVL *raiz, char nome[100], int resultado);
