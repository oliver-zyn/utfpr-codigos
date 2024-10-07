
typedef struct no_arvore* NoArvAVL;

NoArvAVL* cria_ArvAVL();
void libera_ArvAVL(NoArvAVL *raiz);
void libera_NO(struct no_arvore* no);
int altura_NO(struct no_arvore* no);
int fatorBalanceamento_NO(struct no_arvore* no);
int maior(int x, int y);
int estaVazia_ArvAVL(NoArvAVL *raiz);
void preOrdem_ArvAVL(NoArvAVL *raiz);
void emOrdem_ArvAVL(NoArvAVL *raiz);
void posOrdem_ArvAVL(NoArvAVL *raiz);
void RotacaoLL(NoArvAVL *A);
void RotacaoRR(NoArvAVL *A);
void RotacaoLR(NoArvAVL *A);
void RotacaoRL(NoArvAVL *A);
int insere_ArvAVL(NoArvAVL *raiz, char *nome, int idade, int pontuacao);
void alteraPontuacaoParticipante(NoArvAVL *raiz, char *nome, char resultado);