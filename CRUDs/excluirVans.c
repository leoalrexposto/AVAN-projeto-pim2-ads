#include "funcoes.h"

void excluirVans(const char *placa, const char *funcionalidade, const char *nomeMenu)
{
    Van transporte;
    int verificador = 0;

    arq = fopen("Registro Vans.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    while(fread (&transporte, sizeof(transporte), 1, arq))
    {
         if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*'))
        {
            printf("\tPlaca: %s\n", transporte.placa);
            verificador = 1;

            transporte.deletado = '*';

            fseek(arq, sizeof(transporte)*-1, SEEK_CUR);
            fwrite (&transporte, sizeof(transporte), 1, arq);
            fseek(arq, sizeof(transporte)* 0, SEEK_END);

            retornarMensagem("\n Dados do veículo excluídos com sucesso!");
            limpaTela();
            montarMenu(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Veiculo não cadastrado!!\n Por favor tente cadastrar o veículo novamente!!", nomeMenu);

}
