#include "funcoes.h"

void confirmacaoConsultarAlunos(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];

            printf("\nDeseja realizar outra consulta? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                consultarAlunos(funcionalidade, nomeMenu);
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
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoConsultarAlunos(funcionalidade, nomeMenu);
            }
}

void confirmacaoExcluirAlunos(const char *funcionalidade, const char *nomeMenu)
{
            Dados aluno;
            int verificador = 0;
            char matricula[7];
            char certeza[2];

            arq = fopen("Registro Alunos.txt", "rb");
            verificacaoArquivoArq();

            cabecalho();
            printf("\tDigite a matrícula do aluno: ");
            limpezaBuffer();
            scanf("%s", &matricula);

            while(fread (&aluno, sizeof(aluno), 1, arq))
            {
                if (strcmp(matricula, aluno.matricula) == 0 && (aluno.deletado != '*'))
                {
                    verificador = 1;
                }
            }

    verificacaoConteudo(verificador, "\n Matrícula não cadastrada!!\n Por favor tente cadastrar o aluno novamente!!", nomeMenu);

            printf("\n\tDeseja realmente EXCLUIR este registro de aluno? s/n\n");
            limpezaBuffer();
            printf("\t");
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                excluirAlunos(matricula, funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoExcluirAlunos(funcionalidade, nomeMenu);
            }
}

void confirmacaoAlterarAlunos(const char *funcionalidade, const char *nomeMenu)
{
            char certeza[2];

            printf("\nDeseja realizar outra alteração? s/n\n");
            limpezaBuffer();
            scanf("%s", &certeza);
            limpaTela();

            if (strcmp(certeza, "s") == 0){
                limpaTela();
                alterarAlunos(funcionalidade, nomeMenu);
            }
            else if (strcmp(certeza, "n") == 0){
                limpaTela();
                montarMenu(funcionalidade, nomeMenu);
            }
            else {
                retornarMensagem("Digite uma opção válida!");
                limpaTela();
                limpezaBuffer();
                confirmacaoAlterarAlunos(funcionalidade, nomeMenu);
            }
}

