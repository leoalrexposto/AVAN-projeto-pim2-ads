#include "funcoes.h"

void cadastrarAlunos(const char *funcionalidade, const char *nomeMenu)
{
    Dados aluno;
    int verificador = 0;
    char matricula[7];

    arq = fopen("Registro Alunos.txt", "a+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tInforme os dados para registro:\n");
    printf("\n\tMatrícula: ");
    limpezaBuffer();
    scanf("%s", &matricula);

    while(fread (&aluno, sizeof(Dados), 1, arq))
    {
        if (strcmp(matricula, aluno.matricula) == 0 && (aluno.deletado != '*')){
            printf("\n Aluno já cadastrado!");
            funcoesSystem();
            fclose(arq);
            montarMenu(funcionalidade, nomeMenu);
        }
    }
    strcpy(aluno.matricula, matricula);

    printf("\n\tNome: ");
    limpezaBuffer();
    gets(aluno.nome);

    printf("\n\tCPF: ");
    limpezaBuffer();
    scanf("%s", &aluno.cpf);

    printf("\n\tTransporte (placa da Van): ");
    limpezaBuffer();
    scanf("%s", &aluno.transporte);

    printf("\n\tSérie (Ano/Bloco): ");
    limpezaBuffer();
    gets(aluno.serie);

    printf("\n\tPeríodo: ");
    limpezaBuffer();
    scanf("%s", &aluno.periodo);

    printf("\n\tEndereço (Rua/Av.- Nº - Bairro): ");
    limpezaBuffer();
    gets(aluno.endereco);

    printf("\n\tNome do responsável: ");
    limpezaBuffer();
    gets(aluno.nomeResponsavel);

    printf("\n\tTelefone de contato 1: ");
    limpezaBuffer();
    gets(aluno.telefoneUm);

    printf("\n\tTelefone de contato 2: ");
    limpezaBuffer();
    gets(aluno.teleforneDois);

    printf("\n\tE-mail: ");
    limpezaBuffer();
    scanf("%s", &aluno.email);

    aluno.deletado = '\0'; // Garante que o aluno seja incluido no banco de dados sem interferir na exclusão de outros alunos

    verificador = fwrite (&aluno, sizeof(aluno), 1, arq);
    if (verificador == 1)
    {
        fclose(arq);
        retornarMensagem("\n Dados do aluno cadastrados com sucesso!");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
    else
    {
        fclose(arq);
        retornarMensagem("\n Falha ao cadastrar os dados do aluno.");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
}

