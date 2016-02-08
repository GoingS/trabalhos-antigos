#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "fila.h"

Fila* addF(Fila* l, char* idX, int tempoCX, int tempoEX, int tipoX){

    Fila* p = l;
    Fila* novo = (Fila*) malloc(sizeof(Fila));
    strcpy(novo->id, idX);
    novo->tempoChegada = tempoCX;
    novo->tempoExec = tempoEX;
    novo->tipo = tipoX;
    novo->prox = NULL;

    if(p){
        while(p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }
    else
        l = novo;

    return l;
}

Fila* rmvF(Fila* l){
    if(l){
        Fila* p;
        p = l->prox;
        free(l);
        return p;
    }
    else return NULL;
}

int filaVazia(Fila* l){
    if(l == NULL)
        return 1;
    else return 0;
}

void printProcF(Fila* l){
    printf("Id: %s\nTempo de chegada: %d\nTempo de execucao: %d\nTipo: ",l->id,l->tempoChegada,l->tempoExec);
        if(l->tipo == 1)
            puts("Usuario\n");
        else
            puts("Sistema\n");
}

void prtF(Fila* l){
    Fila* p = l;
    while(p != NULL){
        printProcF(p);
        p = p->prox;
    }
}

void prtFSimples(Fila* l){
    Fila* p = l;

    while(p != NULL){
        printf("%s ",p->id);
        p = p->prox;
    }
}
