#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"
#include "obtencaoProcessos.h"
#include "escalonamento.h"

int main(){
    Fila* f = NULL;
    int tp = -1;

    f = obterDados(&tp);
    f = escalonarTodosProcessos(f, tp);

    return 0;
}
