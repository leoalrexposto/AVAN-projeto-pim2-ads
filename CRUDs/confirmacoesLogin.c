#include "funcoes.h"

void confirmacaoConsultarLogin(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];
            printf("\nDeseja realizar outra consulta? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                fclose(arq);
                consultarLogin(funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                if(strcmp("Transportador", nomeMenu) == 0){
                    fclose(arq);
                    menuTransportador();
                }
                else {
                    fclose(arq);
                    montarMenu(funcionalidade, nomeMenu);
                }
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                fclose(arq);
                confirmacaoConsultarLogin(funcionalidade, nomeMenu);
            }
}

void confirmacaoExcluirLogin(const char *funcionalidade, const char *nomeMenu)
{
            loginEstrutura login;
            int verificador = 0;
            char usuario[USUARIO_MAX];
            char certeza[2];

            arq = fopen("Logins.txt", "rb");
            verificacaoArquivoArq();

            cabecalho();

            printf("\tDigite o usuário que deseja excluir: ");
            limpezaBuffer();
            scanf("%s", &usuario);


            while(fread (&login, sizeof(login), 1, arq))  // verifica se tem cadastros no banco de dados
            {
                if (strcmp(usuario, login.usuario) == 0 && (login.deletado != '*'))
                {
                    verificador = 1;
                }
            }

    verificacaoConteudo(verificador, "\n Usuário não cadastrado!!\n Por favor tente cadastrar o usuário novamente!!", nomeMenu);

            printf("\n\tDeseja realmente EXCLUIR este usuário? s/n\n");
            limpezaBuffer();
            printf("\t");
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                fclose(arq);
                excluirLogin(usuario, funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                fclose(arq);
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                fclose(arq);
                confirmacaoExcluirLogin(funcionalidade, nomeMenu);
            }
}

void confirmacaoAlterarLogin(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];
            printf("\nDeseja realizar outra Alteração? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                fclose(arq);
                alterarLogin(funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                fclose(arq);
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                fclose(arq);
                confirmacaoAlterarLogin(funcionalidade, nomeMenu);
            }
}

