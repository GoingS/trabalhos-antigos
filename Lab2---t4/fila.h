#ifndef a
#define a

struct fila{
    char id[10];
    int tempoChegada;
    int tempoExec;
    int tipo;
    struct fila* prox;
};
typedef struct fila Fila;

Fila* addF(Fila* l, char* idX, int tempoCX, int tempoEX, int tipoX);

Fila* rmvF(Fila* l);

int filaVazia(Fila* l);

void printProcF(Fila* l);

void prtF(Fila* l);

void prtFSimples(Fila* l);

#endif
