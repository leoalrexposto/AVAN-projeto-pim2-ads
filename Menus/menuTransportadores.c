#include "funcoes.h"

void menuTransportador() {

    int opcao, retorno = 0;
    char entrada[2];

    cabecalho();

    printf("\tMenu do Transportador\n\n");
    printf("Informe uma op��o v�lida e aperte a tecla enter\n\n");
    printf("1. Consultar Aluno\n");
    printf("2. Lista de alunos\n");
    printf("3. Deslogar\n");

    limpezaBuffer();
    scanf("%s", &entrada);
    retorno = validacaoEntrada(entrada);

    if(retorno == 1){
        opcao = strtol(entrada, NULL, 10);
        limpaTela();

        switch(opcao)
        {
            case 1:
                gerenciarMenu(3, "Alunos", "Transportador");
                break;
            case 2:
                listaVanAlunosTransportes("Transportador");
                break;
            case 3:
                limpaTela();
                menuPrincipal();
                break;
            default:
                retornarMensagem("Digite uma op��o v�lida\n");
                funcoesSystem();
                menuTransportador();
        }
    }
    else {
        mensagemOpcaoInvalida();
        limpaTela();
        menuTransportador();
    }


}


