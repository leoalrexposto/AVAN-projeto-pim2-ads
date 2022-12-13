#include "funcoes.h"

void consultarLogin(const char *funcionalidade, const char *nomeMenu)
{
    loginEstrutura login;
    int verificador = 0;
    char usuario[USUARIO_MAX];

    arq = fopen("Logins.txt", "rb");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite o usuário para consultar: ");
    limpezaBuffer();
    scanf("%s", &usuario);
    limpaTela();
    cabecalho();

    while(fread (&login, sizeof(login), 1, arq))
    {
        if (strcmp(usuario, login.usuario) == 0 && (login.deletado != '*'))
        {
            printf("\tUsuário: %s\n", login.usuario);
            if(login.tipo == 2){
                printf("\tTipo: transportador\n");
                printf("\tPlaca: %s\n", login.placaVan);
            }
            else {
                printf("\tTipo: administrador\n");
            }

            verificador = 1;

            confirmacaoConsultarLogin(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Usuário não cadastrado!!\n Por favor tente cadastrar o usuário novamente!!", nomeMenu);
}
