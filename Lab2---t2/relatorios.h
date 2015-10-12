void R1(ListaC* C, ListaA* A){
    ListaA* auxA;
    ListaC* auxC;
    ListaCO* auxCO;

    system("cls");
    printf("Nome dos clientes e o nome da agencia em que estes possuem conta:\n");
    for(auxC = C; auxC != NULL; auxC = auxC->prox){
        printf("\n\nCliente ");
        puts(auxC->nome);
        printf("Contas nas agencias:");
        for(auxA = A; auxA != NULL; auxA = auxA->prox){
            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                if(strcmp(auxCO->cliente->nome, auxC->nome) == 0)
                    printf(" %d", auxA->codigo);
        }
    }
    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R2(ListaA* A){
    ListaA* auxA;

    system("cls");
    printf("Agencias que ainda nao possuem nenhuma conta aberta:\n");
    for(auxA = A; auxA != NULL; auxA = auxA->prox){
        if(auxA->contas == NULL)
            printf("\nAgencia: %d", auxA->codigo);
    }
    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R3(ListaA* A){
    ListaA* auxA;
    ListaT* auxT;
    char mes[2];

    system("cls");
    printf("Saques efetuados em um mes:\n\nDigite o mes (MM): ");
    fflush(stdin);
    gets(mes);
    fflush(stdin);

    for(auxA = A; auxA != NULL; auxA = auxA->prox)
        for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox)
            if(auxT->data[3] == mes[0] && auxT->data[4] == mes[1] && strcmp(auxT->tipo, "Saque") == 0)
                printf("\nCodigo da transacao: %d", auxT->codigo);


    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R4(ListaA* A){
    ListaA* auxA;
    ListaCO* auxCO;
    char mes[2];

    system("cls");
    printf("Contas que nao estao no negativo:\n");

    for(auxA = A; auxA != NULL; auxA = auxA->prox)
        for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
            if(auxCO->saldo > 0)
                printf("\nConta numero: %d, agencia %d", auxCO->numero, auxA->codigo);

    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R5(ListaA* A, ListaC* C){
    ListaA* auxA;
    ListaC* auxC;
    ListaCO* auxCO;
    char cliente[15];
    int encontrou = 0;

    system("cls");
    printf("Todas as contas de algum cliente\n\nCliente: ");
    fflush(stdin);
    gets(cliente);
    fflush(stdin);
    for(auxC = C; auxC != NULL; auxC = auxC->prox)
        if(strcmp(auxC->nome, cliente) == 0)
            encontrou = 1;

    if(!encontrou)
        printf("\nCliente nao encontrado\n");
    else
        for(auxA = A; auxA != NULL; auxA = auxA->prox)
            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                if(strcmp(auxCO->cliente->nome, cliente) == 0)
                    printf("\nConta numero: %d", auxCO->numero);

    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R6(ListaA* A, ListaC* C){
    ListaA* auxA;
    ListaT* auxT;
    int agencia;
    int encontrou = 0;

    system("cls");
    printf("Todas as transferencias bancarias efetuadas em uma agencia\n\nAgencia: ");
    fflush(stdin);
    scanf("%d", &agencia);
    fflush(stdin);
    for(auxA = A; auxA != NULL; auxA = auxA->prox)
        if(auxA->codigo == agencia)
            encontrou = 1;

    if(!encontrou)
        printf("\nAgencia nao encontrada\n");
    else{
        auxA = bsc_agc(A, agencia);

        for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox)
            if(strcmp(auxT->tipo, "Trans.") == 0)
                printf("\nTransacao codigo: %d", auxT->codigo);
    }

    printf("\n\n\nPressione qualquer tecla...");
    getch();
}

void R7(ListaA* A, ListaC* C){
    ListaA* auxA;
    ListaC* auxC;
    ListaT* auxT;
    ListaCO* auxCO;
    int encontrou = 0, conta;
    char cliente[15];

    system("cls");
    printf("Transaçoes bancarias realizadas por cliente\n\nCliente: ");
    fflush(stdin);
    gets(cliente);
    fflush(stdin);


    for(auxC = C; auxC != NULL; auxC = auxC->prox)
        if(strcmp(auxC->nome, cliente) == 0)
            encontrou = 1;
    if(!encontrou)
        printf("Cliente nao encontrado");
    else{
        for(auxA = A; auxA != NULL; auxA = auxA->prox){
            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                if(strcmp(auxCO->cliente->nome, cliente) == 0)
                    conta = auxCO->numero;
            printf("\nAgencia: %d\n", auxA->codigo);
            for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox)
                if(auxT->conta == conta)
                    printf("\nTransacao codigo %d.", auxT->codigo);
        }
    }
    printf("\n\n\nPressione qualquer tecla...");
    getch();
}

void R8(ListaA* A){
    ListaA* auxA;
    ListaT* auxT;

    system("cls");
    printf("Todos os pagamentos realizados:\n\n");

    for(auxA = A; auxA != NULL; auxA = auxA->prox){
        for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox)
            if(strcmp(auxT->tipo, "Pagamento") == 0)
                printf("Transacao codigo %d.\n", auxT->codigo);
    }
    printf("\n\n\nPressione qualquer tecla...");
    getch();
}

void R9(ListaA* A, ListaC* C){
    ListaA* auxA;
    ListaCO* auxCO;
    ListaT* auxT;
    ListaC* auxC;
    int conta, realizouTransferencia;


    system("cls");
    printf("Nome dos clientes que nao realizaram nenhuma transacao bancaria:\n\n");

    for(auxC = C; auxC != NULL; auxC = auxC->prox){
        realizouTransferencia = 0;
        for(auxA = A; auxA != NULL; auxA = auxA->prox){
            conta = 0;
            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                if(strcmp(auxCO->cliente->nome, auxC->nome) == 0)
                    conta = auxCO->numero;
            if(conta != 0){
                for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox){
                    if(auxT->conta == conta)
                        realizouTransferencia = 1;
                }

            }
        }
        if(!realizouTransferencia)
            puts(auxC->nome);
    }

    printf("\n\n\nPressione qualquer tecla...");
    getch();

}

void R10(ListaA* A){
    int maior;
    ListaA* auxA;
    ListaCO* auxCO;
    char nome[15];

    system("cls");
    printf("Nome dos clientes que tem o maior saldo em conta em cada agencia:\n\n");

    for(auxA = A; auxA != NULL; auxA = auxA->prox){
        if(auxA->contas){
            maior = auxA->contas->saldo;
            strcpy(nome, auxA->contas->cliente->nome);
            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                if(auxCO->saldo > maior){
                    maior = auxCO->saldo;
                    strcpy(nome, auxCO->cliente->nome);
                }
            printf("\nAgencia %d:\n\n%d -> ", auxA->codigo,maior);
            puts(nome);
        }
    }

    printf("\n\n\nPressione qualquer tecla...");
    getch();
}
