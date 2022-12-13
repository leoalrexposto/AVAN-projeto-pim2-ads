#include "funcoes.h"

void cadastrarVans(const char *funcionalidade, const char *nomeMenu)
{
    Van transporte;
    int verificador = 0;
    char placa[8];

    arq = fopen("Registro Vans.txt", "a+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tInforme os dados para registro:\n");
    printf("\n\tPlaca do ve�culo: ");
    limpezaBuffer();
    scanf("%s", &placa);

    while(fread (&transporte, sizeof(transporte), 1, arq))
    {
        if (strcmp(placa, transporte.placa) == 0 && (transporte.deletado != '*')){
            printf("\n Ve�culo j� cadastrado!");
            funcoesSystem();
            fclose(arq);
            montarMenu(funcionalidade, nomeMenu);
        }

    }
    strcpy(transporte.placa, placa);

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

    verificador = fwrite (&transporte, sizeof(transporte), 1, arq);
    if (verificador == 1)
    {
        fclose(arq);
        retornarMensagem("\n Dados do ve�culo inclusos com sucesso!");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
    else
    {
        fclose(arq);
        retornarMensagem("\n Falha ao gravar os dados do ve�culo.");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
}

