typedef struct jogo Jogo;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaListaVazia();
int verificaListaVazia(Lista *lst);
Celula* buscaPorChave(Lista * lst, int chave);
void imprimeLista(Lista *lst);
void insereInicioLista(Lista *lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]);
void insereFimLista(Lista *lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]);
void insereMeioLista(Lista *lst, int chave, int x, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);

void insere(Lista * lst, int chave, char nome[], char descricao[], int faixaEtaria, char linkAcesso[]);
void removePorNome(Lista *lst, char nome[]);
void imprime_jogo(Lista *lst, char nome[]);