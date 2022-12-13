#include "funcoes.h"

void excluirLogin(const char *usuario, const char *funcionalidade, const char *nomeMenu)
{
    loginEstrutura login;
    int verificador = 0;

    arq = fopen("Logins.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    while (fread (&login, sizeof(login), 1, arq))
    {
         if (strcmp(usuario, login.usuario) == 0 && (login.deletado != '*'))
        {
            printf("\tUsu�rio: %s\n", login.usuario);
            verificador = 1;

            login.deletado = '*';

            fseek(arq, sizeof(login) * -1, SEEK_CUR);
            fwrite (&login, sizeof(login), 1, arq);
            fseek(arq, sizeof(login) * 0, SEEK_END);

            retornarMensagem("\n Usu�rio exclu�do com sucesso!");
            limpaTela();
            montarMenu(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Usu�rio n�o cadastrado!!\n Por favor tente cadastrar o usu�rio novamente!!", nomeMenu);

}
