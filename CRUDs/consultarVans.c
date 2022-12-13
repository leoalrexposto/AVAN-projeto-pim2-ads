#include "funcoes.h"

void consultarVans(const char *funcionalidade, const char *nomeMenu)
{
    Van transporte;
    int verificador = 0;
    char placa[8];

    arq = fopen("Registro Vans.txt", "rb");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a placa do veículo: ");
    limpezaBuffer();
    scanf("%s", placa);
    limpaTela();
    cabecalho();

    while(fread (&transporte, sizeof(transporte), 1, arq))
    {
        if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*'))
        {
            printf("\tPlaca: %s\n\n\tNome: %s\n", transporte.placa, transporte.nome);
            printf("\n\tCPF do proprietário: %s\n\n\tMarca: %s\n", transporte.cpf, transporte.marca);
            printf("\n\tModelo: %s\n\n\tAno: %s\n", transporte.modelo, transporte.ano);
            verificador = 1;

            confirmacaoConsultarVans(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Veiculo não cadastrado!!\n Por favor tente cadastrar o veículo novamente!!", nomeMenu);
}
