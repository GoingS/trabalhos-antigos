struct lista{
    int codigo;
    char nome[20];
    float media;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* addL(Lista* l, int codigoX, char nomeX[], float mediaX);

Lista* rmvL(Lista* l, int codigoX);

void printLista(Lista* l);
