#include "funcoes.h"

void consultarAlunos(const char *funcionalidade, const char *nomeMenu)
{
    Dados aluno;
    int verificador = 0;
    char matricula[7];

    arq = fopen("Registro Alunos.txt", "rb");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a matr�cula do aluno: ");
    limpezaBuffer();
    scanf("%s", &matricula);
    limpaTela();
    cabecalho();

    while(fread (&aluno, sizeof(aluno), 1, arq))
    {
        if (strcmp(matricula, aluno.matricula) == 0 && (aluno.deletado != '*'))
        {

            printf("\tMatricula: %s\n\n\tNome: %s\n", aluno.matricula, aluno.nome);
            printf("\n\tCPF: %s\n\n\tTransporte (placa da Van): %s\n", aluno.cpf, aluno.transporte);
            printf("\n\tS�rie: %s\n", aluno.serie);
            printf("\n\tPer�odo: %s\n\n\tEndere�o: %s\n", aluno.periodo, aluno.endereco);
            printf("\n\tNome do Respons�vel: %s\n\n\tTelefone de contato 1: %s\n", aluno.nomeResponsavel, aluno.telefoneUm);
            printf("\n\tTelefone de contato 2: %s\n\n\tE-mail: %s\n", aluno.teleforneDois, aluno.email);
            verificador = 1;

            confirmacaoConsultarAlunos(funcionalidade, nomeMenu);
        }
    }

    verificacaoConteudo(verificador, "\n Matr�cula n�o cadastrada!!\n Por favor tente cadastrar o aluno novamente!!", nomeMenu);
}
