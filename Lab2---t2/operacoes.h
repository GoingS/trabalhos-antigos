void saldo(ListaA* A){
    int agencia, conta;
    ListaA* auxA;
    ListaCO* auxCO;

    system("cls");
    printf("Checando saldo:\n\nDigite a agencia: ");
    fflush(stdin);
    scanf("%d", &agencia);
    auxA = bsc_agc(A, agencia);
    if(auxA == NULL)
        printf("\nAgencia nao encontrada.");
    else{
        printf("Digite a conta: ");
        scanf("%d", &conta);
        auxCO = bsc_con(auxA->contas, conta);
        if(auxCO == NULL)
            printf("\nConta nao encontrada");
        else
            printf("\n\nSaldo: %d", auxCO->saldo);
    }

    printf("\n\n\n\nPressione qualquer tecla...\n");
    getch();
}

ListaA* saque(ListaA* A){
    int agencia, conta, quantia, codigo;
    char data[11];
    ListaA* auxA;
    ListaCO* auxCO;

    system("cls");
    printf("Digite a agencia: ");
    fflush(stdin);
    scanf("%d", &agencia);
    auxA = bsc_agc(A, agencia);
    if(auxA == NULL)
        printf("\nAgencia nao encontrada.");
    else{
        printf("Digite a conta: ");
        fflush(stdin);
        scanf("%d", &conta);
        auxCO = bsc_con(auxA->contas, conta);
        if(auxCO == NULL)
            printf("\nConta nao encontrada");
        else{
            printf("\n\nData de hoje (DD/MM/AAAA): ");
            fflush(stdin);
            gets(data);
            printf("Digite a quantia: ");
            fflush(stdin);
            scanf("%d", &quantia);
            if(quantia>1000)
                printf("O saque excede o valor maximo diario");
            else if(auxCO->saldo - quantia < -1*(auxCO->limite))
                printf("O saque excede o limite");
            else{
                codigo = rand()% 10000; /// ARRUMAR
                auxA->trans = ins_trn(auxA->trans, codigo, conta, "Saque", data);
                auxCO->saldo = auxCO->saldo - quantia;
                printf("\n\nSaque efetivado. Codigo: %d", codigo);
            }
        }
    }

    printf("\n\n\n\nPressione qualquer tecla...\n");
    getch();

    return A;
}

ListaA* transferencia(ListaA* A){
    int agencia, conta, quantia, codigo;
    char data[11];
    ListaA* auxA, *auxA2;
    ListaCO* auxCO, *auxCO2;

    system("cls");
    printf("Digite a agencia: ");
    fflush(stdin);
    scanf("%d", &agencia);
    auxA = bsc_agc(A, agencia);
    if(auxA == NULL)
        printf("\nAgencia nao encontrada.");
    else{
        printf("Digite a conta: ");
        fflush(stdin);
        scanf("%d", &conta);
        auxCO = bsc_con(auxA->contas, conta);
        if(auxCO == NULL)
            printf("\nConta nao encontrada");
        else{
            printf("\n\nData de hoje (DD/MM/AAAA): ");
            fflush(stdin);
            gets(data);
            printf("\nDigite a agencia de destino: ");
            fflush(stdin);
            scanf("%d", &agencia);
            auxA2 = bsc_agc(A, agencia);
            if(auxA2 == NULL)
                printf("\nAgencia nao encontrada.");
            else{
                printf("Digite a conta de destino: ");
                fflush(stdin);
                scanf("%d", &conta);
                auxCO2 = bsc_con(auxA->contas, conta);
                if(auxCO2 == NULL)
                    printf("\nConta nao encontrada");
                else{
                    printf("\nDigite a quantia: ");
                    fflush(stdin);
                    scanf("%d", &quantia);
                    if(quantia > 5000)
                        printf("O pagamento excede o limite diario");
                    else if(auxCO->saldo - quantia < -1*auxCO->limite)
                        printf("O pagamento excede o limite");
                    else{
                        auxCO->saldo = auxCO->saldo - quantia;
                        auxCO2->saldo = auxCO2->saldo + quantia;
                        codigo = rand() % 10000;
                        auxA->trans = ins_trn(auxA->trans, codigo, conta, "Trans.", data);
                        printf("\n\nTransferencia feita. Codigo: %d\n", codigo);
                    }
                }
            }
        }
    }

    printf("\n\n\n\nPressione qualquer tecla...\n");
    getch();

    return A;
}

ListaA* pagamento(ListaA* A){
    int agencia, conta, quantia, codigo;
    char data[11];
    ListaA* auxA;
    ListaCO* auxCO;

    system("cls");
    printf("Digite a agencia: ");
    fflush(stdin);
    scanf("%d", &agencia);
    auxA = bsc_agc(A, agencia);
    if(auxA == NULL)
        printf("\nAgencia nao encontrada.");
    else{
        printf("Digite a conta: ");
        fflush(stdin);
        scanf("%d", &conta);
        auxCO = bsc_con(auxA->contas, conta);
        if(auxCO == NULL)
            printf("\nConta nao encontrada");
        else{
            printf("\n\nDigite o valor a ser pago: ");
            fflush(stdin);
            scanf("%d", &quantia);
            if(quantia>3000)
                printf("O pagamento excede o valor maximo diario");
            else if(auxCO->saldo - quantia < (auxCO->limite)*(-1))
                printf("O pagamento excede o limite");
            else{
                printf("\n\nData de hoje (DD/MM/AAAA): ");
                fflush(stdin);
                gets(data);
                codigo = rand()% 10000; /// ARRUMAR
                auxA->trans = ins_trn(auxA->trans, codigo, conta, "Pagamento", data);
                auxCO->saldo = auxCO->saldo - quantia;
                printf("\n\nPagamento efetivado. Codigo: %d", codigo);
            }
        }
    }

    printf("\n\n\n\nPressione qualquer tecla...\n");
    getch();

    return A;
}
