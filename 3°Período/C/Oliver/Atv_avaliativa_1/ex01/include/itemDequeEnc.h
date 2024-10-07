typedef struct noticia Noticia;
typedef struct celula Celula;
typedef struct deque Deque;
typedef enum classificacao Classificacoes;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int verificaDequeVazia(Deque* dq);
void insereFinal_Deque(Deque* dq, int chave, int anoPublicacao, char manchete[], char corpo[], char autor[], char classificacao[]);
void insereInicio_Deque(Deque* dq, int chave, int anoPublicacao, char manchete[], char corpo[], char autor[], char classificacao[]);
void removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);

int numeroNoticiasClassificacao(Deque * dq, char classificacao[]);
void imprimePorcentagemClassificacaoMaior(Deque * dq);
int numeroTotalNoticias(Deque * dq);
void imprimeNumeroNoticiasClassificacao(Deque *dq);