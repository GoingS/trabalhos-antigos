#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "obtencaoProcessos.h"

void filtrarString(char string[]){
    int i = 0;
    int j;

    while(i < strlen(string)){
        if((string[i] == ',') ||                       // se é virgula
           (string[i] == ':')  ||                       // se é dois pontos
           (string[i] >= '0' && string[i] <= '9') ||  // se esta entre '0' a '9'
           (string[i] >= 'A' && string[i] <= 'Z') ||  // entre 'A' e 'Z'
           (string[i] >= 'a' && string[i] <= 'z')){ // entre 'a' e 'z'
            string[i] = tolower(string[i]);
            i++;
        }
        else
            for(j=i; string[j] != '\0';j++)
                string[j] = string[j+1];
    }
}

int entradaProcessoValida(char string[]){
    int possuiCampoVazio = 0;
    int numeroVirgulas = 0;
    int i;

    if(string[0] == ',')
        possuiCampoVazio = 1;
    else{
        for(i=0; i<strlen(string);i++){
            if(string[i] == ','){
                numeroVirgulas++;
                if(string[i+1] == ',')
                    possuiCampoVazio = 1;
            }
        }
    }

    if(numeroVirgulas != 3 || possuiCampoVazio)
        return 0;

    for(i=0;string[i] != ','; i++){     //passa pelo id
    }
    i++;

    while(string[i] != ','){
        if(string[i] < '0' || string[i] > '9') // verifica se o tempo de chegada é um número
            return 0;
        i++;
    }
    i++;

    while(string[i] != ','){
        if(string[i] < '0' || string[i] > '9') // verifica se o tempo de execução é um número
            return 0;
        i++;
    }
    i++;

    if(strcmp(string+i, "sistema") != 0 && strcmp(string+i, "usuario") != 0 && strcmp(string+i, "usuário") != 0)
        return 0;
    return 1;
}

int entradaTpValida(char string[]){
    int i;
    int ehValida = 1;

    if(string[0] == 't' && string[1] == 'p' && string[2] == ':' && string[3] != '\0' && string[3] != '-'){
        for(i = 3; i<strlen(string)-1; i++)
            if(string[i] > '9' || string[i] < '0')
                ehValida = 0;
    }
    else
        ehValida = 0;

    return ehValida;
}

Fila* adicionarProcessoFila(Fila* l, char string[]){
    int tempoChegada, tempoExecucao, tipo;
    int i, j;
    char id[10],stringAux[10];


    for(i = 0; string[i] != ','; i++)
        id[i] = string[i];
    id[i] = '\0';
    i++;

    j = 0;
    while(string[i] != ','){
        stringAux[j] = string[i];
        i++;
        j++;
    }
    stringAux[j+1] = '\0';
    tempoChegada = atoi(stringAux);
    i++;

    j = 0;
    while(string[i] != ','){
        stringAux[j] = string[i];
        i++;
        j++;
    }
    stringAux[j+1] = '\0';
    tempoExecucao = atoi(stringAux);
    i++;
    if(strcmp(string+i,"sistema") == 0)
        tipo = 0;
    else tipo = 1;


    l = addF(l, id, tempoChegada, tempoExecucao, tipo);
    return l;
}

int obterTp(char string[]){
    int tp = atoi(string+3);
    if(tp < 0)
        tp = 0;

    return tp;
}

Fila* obterDados(int* tp){
    char entrada[30] = "";
    Fila* filaProcessos = NULL;

    printf("Digite processos no formato: id, tempo de chegada, tempo de execucao, tipo.\n");
    printf("Digite tp no formato: tp: *numero*\n");
    printf("Digite fim para escalonar os processos\n\n");

    while(strcmp(entrada, "fim") != 0 || *tp <= 0){
        fgets(entrada, 30, stdin);
        filtrarString(entrada);

        if(entradaProcessoValida(entrada)){
            filaProcessos = adicionarProcessoFila(filaProcessos, entrada);
            printf("Processo adicionado\n\n");
        }
        else if(entradaTpValida(entrada)){
            *tp = obterTp(entrada);
            if(*tp == 0)
                printf("TP invalido\n\n");
            else printf("TP alterado\n\n");
            }
        else if(strcmp(entrada,"fim") == 0 && *tp <= 0)
            printf("Digite um TP valido\n\n");
        else
            printf("Comando invalido\n\n");
    }
    system("cls");
    return filaProcessos;
}
