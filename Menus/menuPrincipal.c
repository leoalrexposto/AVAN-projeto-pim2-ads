#include "funcoes.h"

void menuPrincipal() {

    int opcao, retorno = 0;
    char entrada[2];

    cabecalho();

    printf("\t\tMenu Principal\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Login\n");
    printf("2. Sobre\n");
    printf("3. Sair\n");

    limpezaBuffer();
    scanf("%s", &entrada);
    retorno = validacaoEntrada(entrada);

    if(retorno == 1){
        opcao = strtol(entrada, NULL, 10);
        limpaTela();

        switch(opcao)
        {
            case 1:
                limpaTela();
                menuLogin();
                break;
            case 2:
                limpaTela();
                sobre();
                break;
            case 3:
                exit(1);
            default:
                mensagemOpcaoInvalida();
                limpaTela();
                menuPrincipal();
        }
    }
    else {
        mensagemOpcaoInvalida();
        limpaTela();
        menuPrincipal();
    }

}

