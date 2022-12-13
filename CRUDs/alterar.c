#include "funcoes.h"

void alterarAlunos(const char *funcionalidade, const char *nomeMenu)
{
    Dados aluno;
    int verificador = 0;
    char matricula[7];

    arq = fopen("Registro Alunos.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a matrícula do aluno: ");
    limpezaBuffer();
    scanf("%s", &matricula);
    limpaTela();
    cabecalho();

    while (fread (&aluno, sizeof(aluno), 1, arq))
    {
         if (strcmp(matricula, aluno.matricula) == 0 && (aluno.deletado != '*'))
        {
            printf("\n\tMatricula: %s\n", aluno.matricula);
            verificador = 1;

            fseek(arq, sizeof(aluno)*-1, SEEK_CUR);

            printf("\n\tNome: ");
            limpezaBuffer();
            gets(aluno.nome);

            printf("\n\tCPF: ");
            limpezaBuffer();
            scanf("%s", &aluno.cpf);

            printf("\n\tTransporte (placa da Van): ");
            limpezaBuffer();
            scanf("%s", &aluno.transporte);

            printf("\n\tSérie: ");
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

            fwrite (&aluno, sizeof(aluno), 1, arq);
            fseek(arq, sizeof(aluno) * 0, SEEK_END);

            retornarMensagem("\n Dados do aluno alterados com sucesso!\n\n");

            confirmacaoAlterarAlunos(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Matrícula não cadastrada!!\n Por favor tente cadastrar o aluno novamente!!", nomeMenu);
 }
