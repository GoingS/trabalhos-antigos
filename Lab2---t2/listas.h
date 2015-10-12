/*
ListaC = lista de clientes
ListaT = lista de transferências
ListaCO = lista de contas
ListaA = lista de agências
*/
struct listaC{
    char nome[30];
    char cpf[12];
    char fone[11];

    struct listaC* prox;
};
typedef struct listaC ListaC;

struct listaT {
    int codigo;
    int conta;
    char tipo[10];
    char data[11];

    struct listaT* prox;
};
typedef struct listaT ListaT;

struct listaCO{
    int numero;
    struct listaC* cliente;
    char data[11];
    int saldo;
    int limite;

    struct listaCO* prox;
};
typedef struct listaCO ListaCO;

struct listaA{
    int codigo;
    char nome[15];
    char endereco[30];
    char gerente[30];
    ListaCO* contas;
    ListaT* trans;

    struct listaA* prox;
};
typedef struct listaA ListaA;
///****************************************************************************************///
ListaC* bsc_clt(ListaC* l, char* cpfX){
    ListaC* p;
    for(p=l; p!=NULL; p=p->prox)
        if(strcmp(p->cpf, cpfX) == 0)
            return p;
    return NULL;
}

ListaT* bsc_trn(ListaT* l, int codigoX){
    ListaT* p;
    for(p=l; p!=NULL; p=p->prox)
        if(p->codigo == codigoX)
            return p;
    return NULL;
}

ListaCO* bsc_con(ListaCO* l, int numeroX){
    ListaCO* p;
    for(p=l; p!=NULL; p=p->prox)
        if(p->numero == numeroX)
            return p;
    return NULL;
}

ListaA* bsc_agc(ListaA* l, int codigoX){
    ListaA* p;
    for(p=l; p!=NULL; p=p->prox)
        if(p->codigo == codigoX)
            return p;
    return NULL;
}
///****************************************************************************************///
ListaC* ins_clt(ListaC* l, char* nomeX, char* cpfX, char* foneX){
    ListaC* novo = (ListaC*) malloc(sizeof(ListaC));
    strcpy(novo->nome, nomeX);
    strcpy(novo->cpf, cpfX);
    strcpy(novo->fone, foneX);
    novo->prox = l;
    return novo;
}

ListaT* ins_trn(ListaT* l, int codigoX, int contaX, char* tipoX, char* dataX){
    ListaT* novo = (ListaT*) malloc(sizeof(ListaT));
    novo->codigo = codigoX;
    novo->conta = contaX;
    strcpy(novo->tipo, tipoX);
    strcpy(novo->data, dataX);
    novo->prox = l;
    return novo;
}

ListaCO* ins_con(ListaCO* l, int numeroX, char* cpfX, char* dataX, int saldoX, int limiteX, ListaC* clientesG){

    ListaCO* novo = (ListaCO*) malloc(sizeof(ListaCO));
    novo->cliente = bsc_clt(clientesG, cpfX);
    if(novo->cliente){
        //novo->cliente->prox = NULL;
        novo->numero = numeroX;
        strcpy(novo->data, dataX);
        novo->saldo = saldoX;
        novo->limite = limiteX;
        novo->prox = l;
    }
    else return l;
    return novo;
}

ListaA* ins_agc(ListaA* l, int codigoX, char* nomeX, char* enderecoX, char* gerenteX){
    ListaA* novo = (ListaA*) malloc(sizeof(ListaA));
    novo->codigo = codigoX;
    strcpy(novo->nome, nomeX);
    strcpy(novo->endereco, enderecoX);
    strcpy(novo->gerente, gerenteX);
    novo->contas = NULL;
    novo->trans = NULL;
    novo->prox = l;
    return novo;
}
///****************************************************************************************///
ListaC* rmv_clt(ListaC* l, char* cpfX){
    ListaC* ant = NULL;
    ListaC* p = l;

    while(p != NULL && strcmp(p->cpf, cpfX) != 0){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL)
        return l->prox;
    if(p == NULL)
        return l;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}

ListaT* rmv_trn(ListaT* l, int codigoX){
    ListaT* ant = NULL;
    ListaT* p = l;

    while(p != NULL && p->codigo != codigoX){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL)
        return l->prox;
    if(p == NULL)
        return l;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}

ListaCO* rmv_con(ListaCO* l, int numeroX){
    ListaCO* ant = NULL;
    ListaCO* p = l;

    while(p != NULL && p->numero != numeroX){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL)
        return l->prox;
    if(p == NULL)
        return l;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}

ListaA* rmv_agc(ListaA* l, int codigoX){
    ListaA* ant = NULL;
    ListaA* p = l;

    while(p != NULL && p->codigo != codigoX){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL)
        return l->prox;
    if(p == NULL)
        return l;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}
///****************************************************************************************///
void imp_clt(ListaC* l){
    ListaC* p;
    for(p = l; p != NULL; p = p->prox){
        printf("Nome: ");
        puts(p->nome);
        printf("CPF: %s\nTelefone: %s\n\n", p->cpf, p->fone);
    }
}

void imp_trn(ListaT* l){
    ListaT* p;
    for(p = l; p != NULL; p = p->prox){
        printf("Codigo: %d\nNumero da conta: %d\nTipo: %s\nData: %s\n\n",
            p->codigo, p->conta, p->tipo, p->data);
    }
}

void imp_con(ListaCO* l){
    ListaCO* p;
    for(p = l; p != NULL; p = p->prox){
        printf("\nNumero: %d\nData: %s\nSaldo: %d\nLimite: %d\nCliente: ",
            p->numero, p->data, p->saldo, p->limite);
        puts(p->cliente->nome);
    }
}

void imp_agc(ListaA* l){
    ListaA* p;
    for(p = l; p != NULL; p = p->prox){
        printf("Codigo: %d\n", p->codigo);
        printf("Nome: ");
        puts(p->nome);
        printf("Endereco: ");
        puts(p->endereco);
        printf("Gerente: ");
        puts(p->gerente);
        printf("\n");
    }
}
