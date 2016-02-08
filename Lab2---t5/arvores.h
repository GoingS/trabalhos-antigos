struct arvore{
    int codigo;
    char nome[20];
    float media;
    struct arvore* esq;
    struct arvore* dir;
};
typedef struct arvore Arvore;

Arvore* addA(Arvore* a, Arvore* sae, Arvore* sad, int codigoX, char nomeX[], float mediaX);

Arvore* rmvA(Arvore* a);

void printArvore(Arvore* a);

Arvore* adicionarArvoreDeCodigo(Arvore* l, int codigoX, char nomeX[], float mediaX);

Arvore* adicionarArvoreDeNome(Arvore* l, int codigoX, char nomeX[], float mediaX);

Arvore* adicionarArvoreDeMedia(Arvore* l, int codigoX, char nomeX[], float mediaX);
