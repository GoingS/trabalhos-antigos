ListaC* alterarClientes(ListaC* C, ListaA** A){

    int fim = 0, conta;
    ListaC* auxC;
    ListaA* auxA;
    ListaCO* auxCO;
    ListaT* auxT;
    char op, nome[30], cpf[12], fone[10];

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
                system("cls");
                fflush(stdin);
                printf("Adicionando cliente:\n\nNome: ");
                gets(nome);
                fflush(stdin);
                printf("CPF: ");
                gets(cpf);
                fflush(stdin);
                printf("Fone: ");
                gets(fone);
                C = ins_clt(C, nome, cpf, fone);
                printf("\n\nCliente adicionado, pressione qualquer tecla...\n");
                getch();
            break;

            case '2':
                system("cls");
                printf("Removendo cliente:\n\nInforme o CPF: ");
                gets(cpf);
                auxC = bsc_clt(C, cpf);
                if (auxC == NULL)
                    printf("\nCliente nao encontrado.\n");
                else{
                    for(auxA = *A; auxA != NULL; auxA = auxA->prox){
                        conta = 0;
                        for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                            if(strcmp(auxCO->cliente->nome, auxC->nome) == 0)
                                conta = auxCO->numero;
                        for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox){
                            if(auxT->conta == conta){
                                printf("Transacao codigo %d removida.\n", auxT->codigo);
                                (*A)->trans = rmv_trn(auxT, auxT->codigo);
                            }
                        }
                        printf("Conta numero %d excluida da agencia %d.\n", conta, auxA->codigo);
                        (*A)->contas = rmv_con(auxA->contas, conta);
                    }

                    printf("\nCliente excluido: ");
                    puts(auxC->nome);
                    C = rmv_clt(C, cpf);
                }
                printf("\n\n\nPressione qualquer tecla...");
                getch();
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
    int fim = 0, op;
    ListaA* auxA;
    ListaCO* auxCO;
    ListaT* auxT;
    int codigo;
    char nome[15], endereco[30], gerente[30];

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
                system("cls");
                printf("Adicionando agencia:\n\nCodigo da agencia: ");
                scanf("%d", &codigo);
                fflush(stdin);
                printf("Nome da agencia: ");
                gets(nome);
                printf("Endereco: ");
                gets(endereco);
                printf("Gerente: ");
                gets(gerente);
                A = ins_agc(A, codigo, nome, endereco, gerente);
                printf("\n\nAgencia adicionada, pressione qualquer tecla...\n");
                getch();
            break;

            case '2':
                system("cls");
                printf("Removendo agencia:\n\nInforme o codigo da agencia: ");
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                if (auxA == NULL)
                    printf("\nAgencia nao encontrada.\n");
                else{
                    printf("\n");
                    for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox){
                        printf("Transacao codigo %d excluida.\n", auxT->codigo);
                        auxA->trans = rmv_trn(auxA->trans, auxT->codigo);
                    }
                    for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox){
                        printf("Conta numero %d excluida.\n", auxCO->numero);
                        auxA->contas = rmv_con(auxA->contas, auxCO->numero);
                    }
                    printf("\nNome da agencia excluida: ");
                    puts(auxA->nome);
                    A = rmv_agc(A, codigo);
                }
                printf("\n\n\nPressione qualquer tecla...");
                getch();
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
    int fim = 0, op, clienteJaCadastrado, contaJaCadastrada;
    ListaA* auxA;
    ListaCO* auxCO;
    ListaC* auxC;
    ListaT* auxT;
    int codigo;
    int numero, saldo, limite;
    char cpf[12], agencia[10], data[11];

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
                system("cls");
                printf("Adicionando conta:\n\nCodigo da agencia: ");
                fflush(stdin);
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                if(auxA == NULL)
                    printf("\n\nAgencia nao encontrada.\n\n");
                else{
                    printf("CPF do cliente: ");
                    fflush(stdin);
                    gets(cpf);
                    auxC = bsc_clt(C, cpf);
                    if(auxC == NULL)
                        printf("\n\nCliente nao cadastrado\n\n");
                    else{
                        clienteJaCadastrado = 0;
                        contaJaCadastrada = 0;
                        for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                            if(strcmp(auxCO->cliente->cpf, cpf) == 0)
                                clienteJaCadastrado = 1;
                        if(clienteJaCadastrado)
                            printf("\nCliente ja esta cadastrado nesta agencia\n");
                        else{
                            printf("\nCliente: ");
                            puts(auxC->nome);
                            fflush(stdin);
                            printf("Numero da conta: ");
                            scanf("%d", &numero);
                            fflush(stdin);
                            for(auxCO = auxA->contas; auxCO != NULL; auxCO = auxCO->prox)
                                if(auxCO->numero == numero)
                                    contaJaCadastrada = 1;
                            if(contaJaCadastrada)
                                printf("\nConta ja esta cadastrada nesta agencia");
                            else{
                                printf("Data: ");
                                gets(data);
                                printf("Saldo: ");
                                fflush(stdin);
                                scanf("%d", &saldo);
                                printf("Limite: ");
                                scanf("%d", &limite);

                                auxA->contas = ins_con(auxA->contas, numero, cpf, data, saldo, limite, C);
                                printf("\nConta adicionada.\n\n");
                            }
                        }
                    }
                }
                printf("\n\nPressione qualquer tecla...\n");
                getch();

            break;

            case '2':
                system("cls");
                printf("Removendo conta:\n\nCodigo da agencia: ");
                fflush(stdin);
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                if(auxA == NULL)
                    printf("Agencia nao encontrada.\n\n");
                else{
                    printf("Informe o numero da conta: ");
                    fflush(stdin);
                    scanf("%d", &numero);
                    auxCO = bsc_con(auxA->contas, numero);
                    if(auxCO == NULL)
                        printf("Conta nao encontrada");
                    else{
                        for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox){
                            if(auxT->conta == numero){
                                printf("\nTransacao numero %d foi removida.", auxT->codigo);
                                auxA->trans = rmv_trn(auxA->trans, auxT->codigo);
                            }
                        }
                        printf("\n\nConta removida de: ");
                        puts(auxCO->cliente->nome);
                        auxA->contas = rmv_con(auxA->contas, numero);
                    }

                }
                printf("\n\n\n\nPressione qualquer tecla...\n");
                getch();
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
    ListaT* auxT;

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
                system("cls");
                printf("Codigo da agencia: ");
                fflush(stdin);
                scanf("%d", &codigo);
                auxA = bsc_agc(A, codigo);
                printf("\n");
                if(auxA == NULL)
                    printf("\nAgencia nao encontrada.");
                else{
                    printf("\nCodigo da transacao: ");
                    scanf("%d", &codigo);
                    auxT = bsc_trn(auxA->trans, codigo);
                    if(auxT == NULL)
                        printf("Codigo nao encontrado");
                    else{
                        auxA->trans = rmv_trn(auxA->trans, codigo);
                        printf("\nTransacao codigo %d foi excluida\n", codigo);
                    }
                }


                printf("\n\n\n\nPressione qualquer tecla...\n");
                getch();
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
