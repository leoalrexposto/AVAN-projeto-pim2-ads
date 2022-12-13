#include "funcoes.h"

void listaVanAlunos(const char *nomeMenu)
{
    Dados aluno;
    Van transporte;
    int verificador = 0;
    char placa[8];

    arq = fopen("Registro Alunos.txt", "rb");
    verificacaoArquivoArq();

    cabecalho();

    printf("\n\tDigite a placa da van: ");
    limpezaBuffer();
    scanf("%s", &placa);

    while(fread (&aluno, sizeof(Dados), 1, arq))
    {
        for(int x = 0; x <= (sizeof(aluno.matricula) / 8); x++){
        if (strcmp(placa, aluno.transporte) == 0 && (aluno.deletado != '*'))
            {
                printf("\n\tMatricula: %s\n\tNome: %s\n", aluno.matricula, aluno.nome);
                verificador = 1;
            }
        }
    }
    verificacaoConteudo(verificador, "\n Veiculo nao cadastrado!!\n Por favor tente cadastrar novamente", nomeMenu);
    printf("\n\n Pressione qualquer tecla para voltar ao menu...");
    funcoesSystem();
    menuAdministrador();

}
