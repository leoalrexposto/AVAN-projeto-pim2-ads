#include "funcoes.h"

void alterarLogin(const char *funcionalidade, const char *nomeMenu)
{
    loginEstrutura login;
    int verificador = 0;
    char usuario[USUARIO_MAX];
    char senha1[SENHA_MAX];
    char senha2[SENHA_MAX];

    arq = fopen("Logins.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite o usuário: ");
    limpezaBuffer();
    scanf("%s", &usuario);
    limpaTela();
    cabecalho();

    while (fread (&login, sizeof(login), 1, arq))
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

            fseek(arq, sizeof(login)*-1, SEEK_CUR);

            printf("\n\tDigite a nova senha: ");
            limpezaBuffer();
            gets(senha1);
            limpaTela();
            cabecalho();

            printf("\n\tConfirme a senha: ");
            limpezaBuffer();
            gets(senha2);

            if(strcmp(senha1, senha2) != 0) {
                printf("\n A confirmação de senha não confere.");
                fclose(arq);
                fseek(arq, sizeof(login) * 0, SEEK_END);
                funcoesSystem();
                alterarLogin(funcionalidade, nomeMenu);
            }
            else {
                strcpy(login.senha, senha2);
            }

            login.deletado = '\0'; // Garante que o usuário seja incluido no banco de dados sem interferir na exclusão de outros usuários

            fwrite (&login, sizeof(login), 1, arq);
            fseek(arq, sizeof(login) * 0, SEEK_END);


            retornarMensagem("\n Senha do usuário alterado com sucesso!\n\n");

            confirmacaoAlterarLogin(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Usuário não cadastrado!!\n Por favor tente cadastrar o usuário novamente!!", nomeMenu);
}
