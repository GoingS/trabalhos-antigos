#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pilha.h"

Pilha* addP(Pilha* l, char* idX, int tempoCX, int tempoEX, int tipoX){
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));
    strcpy(novo->id, idX);
    novo->tempoChegada = tempoCX;
    novo->tempoExec = tempoEX;
    novo->tipo = tipoX;
    novo->prox = l;

    return novo;
}

Pilha* rmvP(Pilha* l){
    if(l){
        Pilha *p = l->prox;
        free(l);
        return p;
    }
    else
        return NULL;
}

Pilha* invP(Pilha* l){
    Pilha* pilhaInvertida = NULL;
    Pilha* nodeAuxiliar;

    while(l != NULL){
        nodeAuxiliar = l;
        pilhaInvertida = addP(pilhaInvertida, l->id, l->tempoChegada, l->tempoExec, l->tipo);

        free(nodeAuxiliar);
        l = rmvP(l);
    }

    return pilhaInvertida;
}

int pilhaVazia(Pilha* l){
    if (l == NULL)
        return 1;
    else return 0;
}

void printProcP(Pilha* p){
    printf("Id: %s\nTempo de chegada: %d\nTempo de execucao: %d\nTipo: ",p->id,p->tempoChegada,p->tempoExec);
        if(p->tipo == 1)
            puts("Usuario\n");
        else
            puts("Sistema\n");
}

void prtP(Pilha* p){
    while(p != NULL){
        printProcP(p);
        p = p->prox;
    }
}

void prtPSimples(Pilha* l){
    Pilha* p = l;

    while(p != NULL){
        printf("%s ",p->id);
        p = p->prox;
    }
}
