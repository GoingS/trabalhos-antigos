#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "listas.h"
#include "alteracoes.h"
#include "operacoes.h"
#include "relatorios.h"
#include "menu.h"


int main(){
    ListaC* clientesG = NULL;
    ListaA* agencias = NULL;
    int fim = 0, op;
    srand(time(NULL));

    /** Só coloquei isso aqui para não ter que preencher dados toda hora que o programa inicia **/
    clientesG = ins_clt(clientesG, "Fulano", "888", "55");
    clientesG = ins_clt(clientesG, "Victor", "999", "55");
    agencias = ins_agc(agencias, 1, "agencia1", "Endereco1", "Gerente1");
    agencias->contas = ins_con(agencias->contas, 123, "999", "29/09/2015", 1200, 2000, clientesG);
    agencias->contas = ins_con(agencias->contas, 456, "888", "29/09/2015", 1400, 2000, clientesG);
    agencias->trans = ins_trn(agencias->trans, 5, 123, "Saque", "30/09/2015");
    agencias->trans = ins_trn(agencias->trans, 8, 456, "Saque", "01/10/2015");



    while(!fim){
        system("cls");
        printf("*** MENU INICIAL ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - Clientes\n");
        printf("2 - Agencias\n");
        printf("3 - Contas\n");
        printf("4 - Transacoes\n");
        printf("5 - Relatorios\n");
        printf("0 - Sair\n");
        op = getch();

        switch(op){
            case '1':
                clientesG = alterarClientes(clientesG, &agencias);
            break;

            case '2':
                agencias = alterarAgencias(agencias);
            break;

            case '3':
                agencias = alterarContas(clientesG, agencias);
            break;

            case '4':
                agencias = alterarTransacoes(clientesG, agencias);
            break;

            case '5':
                relatorios(clientesG, agencias);
            break;

            case '0':
                printf("\n\nPressione 0 mais uma vez para sair...");
                op = getch();
                if(op == '0')
                    fim = 1;
            break;
        }
    }
}

