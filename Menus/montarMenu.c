#include "funcoes.h"

void montarMenu(const char *funcionalidade, const char *nomeMenu)
{
    int opcao, retorno = 0;
    char entrada[2];

    cabecalho();

    printf("\tMenu do %s - %s\n\n", nomeMenu, funcionalidade);
    printf("Informe uma opção válida e aperte a tecla enter\n\n");
    printf("1. Cadastrar %s\n", funcionalidade);
    printf("2. Alterar %s\n", funcionalidade);
    printf("3. Consultar %s\n", funcionalidade);
    printf("4. Excluir %s\n", funcionalidade);
    printf("5. Voltar ao menu do %s\n", nomeMenu);

    limpezaBuffer();
    scanf("%s", &entrada);
    retorno = validacaoEntrada(entrada);

    if(retorno == 1){
        opcao = strtol(entrada, NULL, 10);
        limpaTela();
        gerenciarMenu(opcao, funcionalidade, nomeMenu);
    }
    else {
        mensagemOpcaoInvalida();
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
}
