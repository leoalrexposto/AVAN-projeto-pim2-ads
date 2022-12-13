#include "funcoes.h"

void gerenciarMenu(int opcao, const char *funcionalidade, const char *nomeMenu)
{
    switch(opcao)
    {
        case 1: // Cadastrar
            if(strcmp(funcionalidade, "Alunos") == 0)
            {
                cadastrarAlunos(funcionalidade, nomeMenu);
            }
            else if (strcmp(funcionalidade, "Vans") == 0)
            {
                cadastrarVans(funcionalidade, nomeMenu);
            }
            else
            {
                cadastrarLogin(funcionalidade, nomeMenu);
            }
            break;

        case 2: // Alterar
            if(strcmp(funcionalidade, "Alunos") == 0)
            {
                alterarAlunos(funcionalidade, nomeMenu);
            }
            else if (strcmp(funcionalidade, "Vans") == 0)
            {
                alterarVans(funcionalidade, nomeMenu);
            }
            else
            {
                alterarLogin(funcionalidade, nomeMenu);
            }
            break;

        case 3: // Consultar
            if(strcmp(funcionalidade, "Alunos") == 0)
            {
                consultarAlunos(funcionalidade, nomeMenu);
            }
            else if (strcmp(funcionalidade, "Vans") == 0)
            {
                consultarVans(funcionalidade, nomeMenu);
            }
            else
            {
                consultarLogin(funcionalidade, nomeMenu);
            }
            break;

        case 4: // Excluir
            if(strcmp(funcionalidade, "Alunos") == 0)
            {
                confirmacaoExcluirAlunos(funcionalidade, nomeMenu);
            }
            else if (strcmp(funcionalidade, "Vans") == 0)
            {
                confirmacaoExcluirVans(funcionalidade, nomeMenu);
            }
            else
            {
                confirmacaoExcluirLogin(funcionalidade, nomeMenu);
            }
            break;

        case 5: // Menus
            if(strcmp(nomeMenu, "Administrador") == 0)
            {
                menuAdministrador();
            }
            else if (strcmp(nomeMenu, "Transportador") == 0)
                {
                    menuTransportador();
                }
            else {
                printf("Erro crítico!\nVocê será redirecionado ao Menu Principal!!");
                menuPrincipal();
            }
            break;

        default:
            printf("Digite uma opção válida\n");
            funcoesSystem();
            montarMenu(funcionalidade, nomeMenu);
        }
}
