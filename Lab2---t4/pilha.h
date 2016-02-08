struct pilha{
    char id[10];
    int tempoChegada;
    int tempoExec;
    int tipo;
    struct pilha* prox;
};
typedef struct pilha Pilha;

Pilha* addP(Pilha* l,char* idX, int tempoCX, int tempoEX, int tipoX);

Pilha* rmvP(Pilha* l);

Pilha* invP(Pilha* l);

int pilhaVazia(Pilha* l);

void printProcP(Pilha* p);

void prtP(Pilha* p);

void prtPSimples(Pilha* l);

