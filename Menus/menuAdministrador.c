#include "funcoes.h"

void menuAdministrador() {

    int opcao, retorno = 0;
    char entrada[2];

    cabecalho();

    printf("\tMenu do Administrador\n\n");
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Gerenciar Alunos\n");
    printf("2. Gerenciar Vans\n");
    printf("3. Gerenciar Logins\n");
    printf("4. Lista de alunos p/ Van\n");
    printf("5. Deslogar\n");

    limpezaBuffer();
    scanf("%s", &entrada);
    retorno = validacaoEntrada(entrada);

    if(retorno == 1){
        opcao = strtol(entrada, NULL, 10);
        limpaTela();

        switch(opcao)
        {
            case 1:
                montarMenu("Alunos", "Administrador");
                break;
            case 2:
                montarMenu("Vans", "Administrador");
                break;
            case 3:
                montarMenu("Logins", "Administrador");
                break;
            case 4:
                listaVanAlunos("Administrador");
                break;
            case 5:
                menuPrincipal();
            default:
                retornarMensagem("Digite uma opção válida\n");
                funcoesSystem();
                menuAdministrador();
        }
    }
    else {
        mensagemOpcaoInvalida();
        menuAdministrador();
    }
}
