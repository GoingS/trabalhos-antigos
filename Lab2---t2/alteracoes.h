ListaC* adicionarCliente(ListaC* C){
    char nome[30], cpf[12], fone[10];

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

    return C;
}

ListaC* removerCliente(ListaC* C, ListaA** A){
    char cpf[12];
    int conta;
    ListaA* auxA;
    ListaT* auxT;
    ListaC* auxC;
    ListaCO* auxCO;

    system("cls");
    printf("Removendo cliente:\n\nInforme o CPF: ");
    fflush(stdin);
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
            if(conta != 0){
                for(auxT = auxA->trans; auxT != NULL; auxT = auxT->prox){
                    if(auxT->conta == conta){
                        printf("Transacao codigo %d removida.\n", auxT->codigo);
                        (*A)->trans = rmv_trn(auxT, auxT->codigo);
                    }
                }
                printf("Conta numero %d excluida da agencia %d.\n", conta, auxA->codigo);
                (*A)->contas = rmv_con(auxA->contas, conta);
            }
        }

        printf("\nCliente excluido: ");
        puts(auxC->nome);
        C = rmv_clt(C, cpf);
    }
    printf("\n\n\nPressione qualquer tecla...");
    getch();

    return C;
}

ListaA* adicionarAgencia(ListaA* A){
    int codigo;
    char nome[15], endereco[30], gerente[30];

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

    return A;
}

ListaA* removerAgencia(ListaA* A){
    int codigo;
    ListaA* auxA;
    ListaT* auxT;
    ListaC* auxC;
    ListaCO* auxCO;

    system("cls");
    printf("Removendo agencia:\n\nInforme o codigo da agencia: ");
    fflush(stdin);
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

    return A;
}

ListaA* adicionarConta(ListaA* A, ListaC* C){
    int codigo, numero, saldo, limite;
    int contaJaCadastrada, clienteJaCadastrado;
    char cpf[12], data[11];
    ListaC* auxC;
    ListaCO* auxCO;
    ListaA* auxA;

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

    return A;
}

ListaA* removerConta(ListaA* A){
    int codigo, numero;
    ListaA* auxA;
    ListaCO* auxCO;
    ListaT* auxT;


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

    return A;
}

ListaA* removerTransacao(ListaA* A){
    ListaA* auxA;
    ListaT* auxT;
    int codigo;

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

    return A;
}
