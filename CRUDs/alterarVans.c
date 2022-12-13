#include "funcoes.h"

void alterarVans(const char *funcionalidade, const char *nomeMenu)
{
    Van transporte;
    int verificador = 0;
    char placa[10];

    arq = fopen("Registro Vans.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a placa do ve�culo: ");
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

            printf("\n\tNome do propriet�rio: ");
            limpezaBuffer();
            gets(transporte.nome);

            printf("\n\tCPF do propriet�rio: ");
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

            transporte.deletado = '\0'; // Garante que a van seja incluido no banco de dados sem interferir na exclus�o de outras vans

            fwrite (&transporte, sizeof(transporte), 1, arq);
            fseek(arq, sizeof(transporte)* 0, SEEK_END);

            retornarMensagem("\n Dados do ve�culo alterados com sucesso!\n\n");

            confirmacaoAlterarVans(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Veiculo n�o cadastrado!!\n Por favor tente cadastr�-lo novamente!!", nomeMenu);
}

