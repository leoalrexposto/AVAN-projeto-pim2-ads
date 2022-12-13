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
                retornarMensagem("Digite uma op��o v�lida!");
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
            printf("\n\tDigite a placa do ve�culo: ");
            limpezaBuffer();
            scanf("%s", &placa);

            while(fread (&transporte, sizeof(transporte), 1, arq))
            {
                if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*'))
                {
                    verificador = 1;
                }
            }

    verificacaoConteudo(verificador, "\n Veiculo n�o cadastrado!!\n Por favor tente cadastrar o ve�culo novamente!!", nomeMenu);

            printf("\n\tDeseja realmente EXCLUIR este registro de ve�culo? s/n\n");
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
                retornarMensagem("Digite uma op��o v�lida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoExcluirVans(funcionalidade, nomeMenu);
            }
}

void confirmacaoAlterarVans(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];
            printf("\nDeseja realizar outra Altera��o? s/n\n");
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
                retornarMensagem("Digite uma op��o v�lida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoAlterarVans(funcionalidade, nomeMenu);
            }
}
