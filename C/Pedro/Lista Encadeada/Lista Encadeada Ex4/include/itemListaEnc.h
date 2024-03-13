typedef struct Pedro Pedro;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaListaVazia();
int verificaListaVazia(Lista *lst);
Celula* buscaPorChave(Lista * lst, int chave);
void imprimeLista(Lista *lst);
void insereInicioLista(Lista *lst, int chave, char nome[], char telefone[], char email[]);
void insereFimLista(Lista *lst, int chave, char nome[], char telefone[], char email[]);
void insereMeioLista(Lista *lst, int chave, char nome[], char telefone[], char email[], int x);
void removePessoa(Lista *lst, int x);
void liberaLista(Lista *lst);
