#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"


Fila* adicionarPilhaAFila(Fila* f, Pilha* p){
    while(!pilhaVazia(p)){
        f = addF(f, p->id, p->tempoChegada, p->tempoExec, p->tipo);
        p = rmvP(p);
    }

    return f;
}

Fila* escalonarPrimeiroProcesso(Fila* f, int tp){
    int tempoProcessado;
    int tempoRestante;

    if(f->tempoExec > tp)
        tempoProcessado = tp;
    else
        tempoProcessado = f->tempoExec;
    tempoRestante = f->tempoExec - tempoProcessado;

    printf("\n\nProcessando o primeiro da fila %s (%d)\n\n", f->id, tempoProcessado);


    if(tempoRestante > 0){
        printf("Ainda fica faltando processar mais %d, insere %s no final da fila\n\n", tempoRestante, f->id);
        f = addF(f, f->id, f->tempoChegada, tempoRestante, f->tipo);
    }
    f = rmvF(f);

    return f;
}

Fila* escalonarTodosProcessos(Fila* f, int tp){
    Pilha* pilhaAux;
    Fila* filaAux = f;
    Fila processoSistema;
    int encontrouProcessoSistema;

    while(!filaVazia(filaAux)){
        pilhaAux = NULL;
        encontrouProcessoSistema = 0;

        printf("Procurando por processo de sistema:\n\n");
        while(!filaVazia(filaAux)){
            if(filaAux->tipo == 0 && !encontrouProcessoSistema){
                encontrouProcessoSistema = 1;
                processoSistema = *filaAux;
            }
            else
                pilhaAux = addP(pilhaAux, filaAux->id, filaAux->tempoChegada, filaAux->tempoExec, filaAux->tipo);
            filaAux = rmvF(filaAux);
        }
        filaAux = NULL;

        printf("Conteudo da pilha: (topo) ");
        prtPSimples(pilhaAux);

        if(encontrouProcessoSistema){
            printf("\n\nEncontrou %s que e processo de sistema, coloca no inicio da fila.\n\n",processoSistema.id);
            filaAux = addF(filaAux, processoSistema.id, processoSistema.tempoChegada,
                        processoSistema.tempoExec,processoSistema.tipo);
        }
        else printf("\n\nNao encontrou processo de sistema, coloca todos na fila de volta.\n\n");

        pilhaAux = invP(pilhaAux);
        filaAux = adicionarPilhaAFila(filaAux,pilhaAux);
        printf("Fila passa a ter: ");
        prtFSimples(filaAux);
        filaAux = escalonarPrimeiroProcesso(filaAux, tp);

        puts("\n\n");
        system("pause");
        system("cls");
    }

    return filaAux;
}
