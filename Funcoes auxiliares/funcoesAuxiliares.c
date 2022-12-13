#include "funcoes.h"

void cabecalho()
{
    printf("***********************************************************\n\n");
    printf("\t\t\tAVAN\n\n");
    printf("***********************************************************\n\n");
}

void esperaTecla()
{
    system("pause>nul");
}

void limpaTela()
{
    system("cls || clear");
}

void funcoesSystem()
{
    esperaTecla();
    limpaTela();
}

void retornarMensagem(const char *mensagem)
{
    printf("%s", mensagem);
    esperaTecla();
}

void mensagemOpcaoInvalida()
{
    limpaTela();
    retornarMensagem("Digite uma opção válida\n");
}

void limpezaBuffer()
{
    fflush(stdin);
}

void verificacaoArquivoArq()
{
    if (arq == NULL)
    {
        retornarMensagem("\nArquivo inexistente! \n Por favor verifique se o banco de dados realmente existe\n");
        getch();
        exit(1);
    }
}

void verificacaoArquivoArq2()
{
    if (arq2 == NULL)
    {
        retornarMensagem("\nArquivo inexistente! \n Por favor verifique se o banco de dados realmente existe\n");
        getch();
        exit(1);
    }
}

void verificacaoConteudo(int verificador, char *mensagem, const char *nomeMenu)
{
    if (!verificador)
    {
        retornarMensagem(mensagem);
        limpezaBuffer();
        if(strcmp(nomeMenu, "Administrador") == 0) {
            limpaTela();
            menuAdministrador();
        }
        else{
            limpaTela();
            menuTransportador();
        }
    }
    fclose(arq);
}

void verificacaoConteudo2(int verificador, char *mensagem, const char *funcionalidade, const char *nomeMenu)
{
    if (!verificador)
    {
        retornarMensagem(mensagem);
        limpezaBuffer();
        montarMenu(funcionalidade, nomeMenu);
    }
    fclose(arq2);
}

int validacaoEntrada(char entradaTeclado[2])
{
    char *parteTexto;
    int tamanhoTexto;

    strtol(entradaTeclado, &parteTexto, 10);
    tamanhoTexto = strlen(parteTexto);

    if(tamanhoTexto == 1){
        return 0;
    }
    else
    {
        return 1;
    }
}

