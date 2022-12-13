#include "funcoes.h"

void excluirAlunos(const char *matricula, const char *funcionalidade, const char *nomeMenu)
{
    Dados aluno;
    int verificador = 0;

    arq = fopen("Registro Alunos.txt", "r+b");
    verificacaoArquivoArq();

    cabecalho();

    while(fread (&aluno, sizeof(aluno), 1, arq))
    {
         if (strcmp(matricula, aluno.matricula) == 0 && (aluno.deletado != '*'))
        {
            printf("\tMatricula: %s\n\tNome: %s\n", aluno.matricula, aluno.nome);
            verificador = 1;

            aluno.deletado = '*';

            fseek(arq, sizeof(aluno)*-1, SEEK_CUR);
            fwrite (&aluno, sizeof(aluno), 1, arq);
            fseek(arq, sizeof(aluno)* 0, SEEK_END);

            retornarMensagem("\n Dados do aluno excluídos com sucesso!");
            limpaTela();
            montarMenu(funcionalidade, nomeMenu);
        }
    }
    verificacaoConteudo(verificador, "\n Matrícula não cadastrada!!\n Por favor tente cadastrar o aluno novamente!!", nomeMenu);

}
