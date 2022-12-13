#include "funcoes.h"

void confirmacaoConsultarVans(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];

            printf("\nDeseja realizar outra consulta? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                consultarVans(funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                if(strcmp("Transportador", nomeMenu) == 0){
                    menuTransportador();
                }
                else {
                    montarMenu(funcionalidade, nomeMenu);
                }
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoConsultarVans(funcionalidade, nomeMenu);
            }
}

void confirmacaoExcluirVans(const char *funcionalidade, const char *nomeMenu)
{
            Van transporte;
            int verificador = 0;
            char placa[10];
            char certeza[2];

            arq = fopen("Registro Vans.txt", "rb");
            verificacaoArquivoArq();

            cabecalho();
            printf("\n\tDigite a placa do veículo: ");
            limpezaBuffer();
            scanf("%s", &placa);

            while(fread (&transporte, sizeof(transporte), 1, arq))
            {
                if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*'))
                {
                    verificador = 1;
                }
            }

    verificacaoConteudo(verificador, "\n Veiculo não cadastrado!!\n Por favor tente cadastrar o veículo novamente!!", nomeMenu);

            printf("\n\tDeseja realmente EXCLUIR este registro de veículo? s/n\n");
            limpezaBuffer();
            printf("\t");
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                excluirVans(placa, funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoExcluirVans(funcionalidade, nomeMenu);
            }
}

void confirmacaoAlterarVans(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];
            printf("\nDeseja realizar outra Alteração? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                alterarVans(funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoAlterarVans(funcionalidade, nomeMenu);
            }
}
