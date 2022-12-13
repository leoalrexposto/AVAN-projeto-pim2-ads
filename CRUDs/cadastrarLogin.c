#include "funcoes.h"

void cadastrarLogin(const char *funcionalidade, const char *nomeMenu)
{
    loginEstrutura login;
    int verificador = 0;
    char tipoUsuario[2];
    char usuario[USUARIO_MAX];

    arq = fopen("Logins.txt", "a+b");

    cabecalho();

    printf("\n\tInforme os dados para registro:\n");
    printf("\n\tUsuário: ");
    limpezaBuffer();
    scanf("%s", &usuario);

    while(fread (&login, sizeof(login), 1, arq))
    {
        if (strcmp(usuario, login.usuario) == 0 && (login.deletado != '*')){
            printf("\n Usuário já cadastrado!");
            funcoesSystem();
            fclose(arq);
            montarMenu(funcionalidade, nomeMenu);
        }
    }
    strcpy(login.usuario, usuario);

    printf("\n\tSenha: ");
    limpezaBuffer();
    gets(login.senha);
    printf("\n\tTipo de Usuário\n");
    printf("\n\t1. Administrador\n");
    printf("\t2. Transportador\n");
    limpezaBuffer();
    printf("\t");
    scanf("%s", &tipoUsuario);

    if(strcmp(tipoUsuario, "1") == 0){
        login.tipo = 1;
    }
    else if(strcmp(tipoUsuario, "2") == 0){
        login.tipo = 2;
    }
    else {
        mensagemOpcaoInvalida();
        limpaTela();
        fclose(arq);
        cadastrarLogin(funcionalidade, nomeMenu);
    }

    if(login.tipo == 2){
        printf("\tPlaca da Van: ");
        limpezaBuffer();
        scanf("%s", &login.placaVan);
    }

    login.deletado = '\0'; // Garante que o usuário seja incluido no banco de dados sem interferir na exclusão de outros usuários

    verificador = fwrite (&login, sizeof(login), 1, arq);
    if (verificador == 1)
    {
        fclose(arq);
        retornarMensagem("\n Cadastro feito com sucesso!");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
    else
    {
        fclose(arq);
        retornarMensagem("\n Falha ao realizar o cadastro\n Tente novamente!.");
        limpaTela();
        montarMenu(funcionalidade, nomeMenu);
    }
}

