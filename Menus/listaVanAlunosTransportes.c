#include "funcoes.h"

void listaVanAlunosTransportes(const char *nomeMenu)
{
    Dados aluno;
    loginEstrutura login;
    int verificador = 0;
    char placa[8];


    arq = fopen("Registro Alunos.txt", "rb");
    verificacaoArquivoArq();

    arq2 = fopen("Logins.txt", "rb");
    verificacaoArquivoArq2();


    while(fread (&login, sizeof(login), 1, arq2))
    {
        strcpy(placa, login.placaVan);
    }

    fclose(arq2);

    cabecalho();

    while(fread (&aluno, sizeof(aluno), 1, arq))
    {
        for(int x = 0; x <= (sizeof(aluno.matricula) / 8); x++){
        if (strcmp(placa, aluno.transporte) == 0 && (aluno.deletado != '*'))
            {
                printf("\tMatricula: %s\n\tNome: %s\n\n", aluno.matricula, aluno.nome);
                verificador = 1;
            }
        }
    }
    verificacaoConteudo(verificador, "\n Alunos nao cadastrados!!\n Por favor cadastre um aluno valido!!", nomeMenu);
    printf("\n\n Pressione qualquer tecla para voltar ao menu...");
    funcoesSystem();
    menuTransportador();
}
