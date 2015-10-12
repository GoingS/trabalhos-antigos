ListaC* alterarClientes(ListaC* C, ListaA** A){
    int fim = 0;
    char op;

    while(!fim){
        system("cls");
        printf("*** MENU CLIENTES ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Remover cliente\n");
        printf("3 - Listar todos os clientes\n");
        printf("0 - Retornar\n");
        op = getch();

        switch(op){
            case '1':
                C = adicionarCliente(C);
            break;

            case '2':
                C = removerCliente(C, A);
            break;

            case '3':
                system("cls");
                printf("Clientes cadastrados: \n\n");
                imp_clt(C);
                printf("\n\n\nPressione qualquer tecla...");
                getch();
            break;

            case '0':
                fim = 1;
            break;
        }
    }

    return C;
}

ListaA* alterarAgencias(ListaA* A){
    int fim = 0;
    char op;

    while(!fim){
        system("cls");
        printf("*** MENU AGENCIAS ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - Adicionar agencia\n");
        printf("2 - Remover agencia\n");
        printf("3 - Listar todas as agencias\n");
        printf("0 - Retornar\n");
        op = getch();

        switch(op){
            case '1':
                A = adicionarAgencia(A);
            break;

            case '2':
                A = removerAgencia(A);
            break;

            case '3':
                system("cls");
                printf("Agencias cadastradas: \n\n");
                imp_agc(A);
                printf("\n\n\nPressione qualquer tecla...");
                getch();
            break;

            case '0':
                fim = 1;
            break;
        }
    }
    return A;
}

ListaA* alterarContas(ListaC* C, ListaA* A){
    int fim = 0, codigo;
    ListaA* auxA;
    char op;

    while(!fim){
        system("cls");
        printf("*** MENU CONTAS ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - Adicionar conta\n");
        printf("2 - Remover conta\n");
        printf("3 - Listar contas de uma agencia\n");
        printf("4 - Listar todas as contas\n");
        printf("0 - Retornar\n");
        op = getch();

        switch(op){
            case '1':
                A = adicionarConta(A, C);
            break;

            case '2':
                A = removerConta(A);
            break;

            case '3':
                system("cls");
                printf("Codigo da agencia: ");
                fflush(stdin);
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                printf("\n");
                if(auxA == NULL)
                    printf("Agencia nao encontrada.");
                else
                    imp_con(auxA->contas);
                printf("\n\n\n\nPressione qualquer tecla...");
                getch();
            break;

            case '4':
                system("cls");
                printf("Contas cadastradas:\n\n");
                for(auxA = A; auxA != NULL; auxA = auxA->prox){
                    printf("Agencia: %d\n", auxA->codigo);
                    imp_con(auxA->contas);
                }
                printf("\n\n\n\nPressione qualquer tecla...");
                getch();
            break;

            case '0':
                fim = 1;
            break;
        }
    }
    return A;
}

ListaA* alterarTransacoes(ListaC* C, ListaA* A){
    int fim = 0, fim2, op, codigo;
    ListaA* auxA;

    while(!fim){
        system("cls");
        printf("*** MENU TRANSACOES ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - Realizar uma transacao\n");
        printf("2 - Remover uma transacao\n");
        printf("3 - Listar transferencias de uma agencia\n");
        printf("4 - Listar todas as transferencias\n");
        printf("0 - Retornar\n");
        op = getch();

        switch(op){
            case '1':
                fim2 = 0;
                while(!fim2){
                    system("cls");
                    printf("Realizando uma transacao:\n\n\nPressione:\n");
                    printf("1 - Verificar saldo\n");
                    printf("2 - Efetuar saque\n");
                    printf("3 - Efetuar transferencia\n");
                    printf("4 - Efetuar pagamento\n");
                    printf("0 - Retornar\n");
                    op = getch();

                    switch(op){
                        case '1':
                            saldo(A);
                        break;
                        case '2':
                            A = saque(A);
                        break;
                        case '3':
                            A = transferencia(A);
                        break;
                        case '4':
                            A = pagamento(A);
                        break;
                        case '0':
                            fim2 = 1;
                        break;
                    }
                }
            break;

            case '2':
                A = removerTransacao(A);
            break;

            case '3':
                system("cls");
                printf("Codigo da agencia: ");
                fflush(stdin);
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                printf("\n");
                if(auxA == NULL)
                    printf("Agencia nao encontrada.");
                else
                    imp_trn(auxA->trans);

                printf("\n\n\n\nPressione qualquer tecla...\n");
                getch();
            break;

            case '4':
                system("cls");
                for(auxA = A; auxA != NULL; auxA = auxA->prox){
                    printf("Agencia: %d\n\n", auxA->codigo);
                    imp_trn(auxA->trans);
                }

                printf("\n\n\n\nPressione qualquer tecla...\n");
                getch();
            break;

            case '0':
                fim = 1;
            break;
            }
    }
    return A;

}

void relatorios(ListaC* C, ListaA* A){
    int fim = 0, op;

    while(!fim){
        system("cls");
        printf("*** MENU RELATORIOS ***\n\n\n");
        printf("Pressione:\n");
        printf("1 - R1\n");
        printf("2 - R2\n");
        printf("3 - R3\n");
        printf("4 - R4\n");
        printf("5 - R5\n");
        printf("6 - R6\n");
        printf("7 - R7\n");
        printf("8 - R8\n");
        printf("9 - R9\n");
        printf("- - R10\n");
        printf("0 - Sair\n");
        op = getch();

        switch(op){
            case '1':
                R1(C,A);
            break;

            case '2':
                R2(A);
            break;

            case '3':
                R3(A);
            break;

            case '4':
                R4(A);
            break;

            case '5':
                R5(A,C);
            break;

            case '6':
                R6(A,C);
            break;

            case '7':
                R7(A,C);
            break;

            case '8':
                R8(A);
            break;

            case '9':
                R9(A,C);
            break;

            case '-':
                R10(A);
            break;

            case '0':
                fim = 1;
            break;
        }
    }
}
