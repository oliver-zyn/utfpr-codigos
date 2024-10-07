typedef struct pedro Pedro;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaVazia(Lista *lst);
Celula* buscaPorChave(Lista *lst, int chave);
void imprimeLista(Lista *lst);
void insereInicioLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota);
void insereFimLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota);
void insereMeioLista(Lista *lst, int chave, char dataReg[], int idatl, float quil, int rota, int x);
void removeRegistro(Lista *lst, int x);
void liberaLista(Lista *lst);
float totalQtdQuikporRota(Lista *ls, int rota);