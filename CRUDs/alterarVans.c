#include "funcoes.h"

void alterarVans(const char *funcionalidade, const char *nomeMenu)
{
    Van transporte;
    int verificador = 0;
    char placa[10];

    arq = fopen("Registro Vans.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a placa do veículo: ");
    limpezaBuffer();
    scanf ("%s", &placa);
    limpaTela();
    cabecalho();

    while (fread (&transporte, sizeof(transporte), 1, arq))
    {
         if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*'))
        {
            printf("\n\tPlaca: %s\n", transporte.placa);
            verificador = 1;

            fseek(arq, sizeof(transporte)*-1, SEEK_CUR);

            printf("\n\tNome do proprietário: ");
            limpezaBuffer();
            gets(transporte.nome);

            printf("\n\tCPF do proprietário: ");
            limpezaBuffer();
            scanf("%s", &transporte.cpf);

            printf("\n\tMarca: ");
            limpezaBuffer();
            scanf("%s", &transporte.marca);

            printf("\n\tModelo: ");
            limpezaBuffer();
            scanf("%s", &transporte.modelo);

            printf("\n\tAno: ");
            limpezaBuffer();
            scanf("%s", &transporte.ano);

            transporte.deletado = '\0'; // Garante que a van seja incluido no banco de dados sem interferir na exclusão de outras vans

            fwrite (&transporte, sizeof(transporte), 1, arq);
            fseek(arq, sizeof(transporte)* 0, SEEK_END);

            retornarMensagem("\n Dados do veículo alterados com sucesso!\n\n");

            confirmacaoAlterarVans(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Veiculo não cadastrado!!\n Por favor tente cadastrá-lo novamente!!", nomeMenu);
}

