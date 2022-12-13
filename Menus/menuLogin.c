#include "funcoes.h"

void menuLogin(){

    loginEstrutura login;
    int tentativas = 0;
    char usuario[USUARIO_MAX];
    char senha[SENHA_MAX];

    arq = fopen("Logins.txt", "a+b");
    verificacaoArquivoArq();

do{
            printf("****************************************\n\n");
            printf("\t\tLOGIN\n\n");
            printf("****************************************\n\n");
            printf("\tUsuário: ");
            limpezaBuffer();
            scanf("%s", &usuario);
            limpezaBuffer();
            printf("\tSenha: ");
            gets(senha);

fseek(arq, sizeof(loginEstrutura)*-1, SEEK_SET);

while(fread(&login, sizeof(loginEstrutura), 1, arq))
{
            if(strcmp(usuario, login.usuario) == 0 && strcmp(senha, login.senha) == 0 && (login.deletado != '*')) {
                if(login.tipo == 1) {
                    limpaTela();
                    tentativas = 0;
                    printf("**********************************\n\n");
                    printf("\tSeja Bem Vindo!\n\n");
                    printf("**********************************\n\n");
                    fclose(arq);
                    funcoesSystem();
                    fseek(arq, sizeof(loginEstrutura)*0, SEEK_END);
                    menuAdministrador();
                }
                else {
                    limpaTela();
                    tentativas = 0;
                    printf("**********************************\n\n");
                    printf("\tSeja Bem Vindo!\n\n");
                    printf("**********************************\n\n");
                    fclose(arq);
                    funcoesSystem();
                    fseek(arq, sizeof(loginEstrutura)*0, SEEK_END);
                    menuTransportador();
                }
            }
}
                if(strcmp(usuario, "admin@admin") == 0 && strcmp(senha, "Lh7g2@d28dF") == 0){
                    limpaTela();
                    tentativas = 0;
                    printf("**********************************\n\n");
                    printf("\tSeja Bem Vindo!\n\n");
                    printf("**********************************\n\n");
                    fclose(arq);
                    funcoesSystem();
                    fseek(arq, sizeof(loginEstrutura)*0, SEEK_END);
                    menuAdministrador();
                }
                fseek(arq, sizeof(loginEstrutura)*0, SEEK_END);
                printf("\n Usuário ou senha invalido!\n");
                funcoesSystem();
                tentativas++;

} while (tentativas < 4);

        limpaTela();
        printf("Número máximo de tentativas alcançado!\nPor favor entre em contato com um administrador do sistema!\n");
        fclose(arq);
        exit(1);

}

