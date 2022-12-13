#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

#define USUARIO_MAX   64
#define SENHA_MAX   32

    //  Estruturas
    typedef struct {
    char deletado;
    char transporte[10];
    char matricula[7];
    char nome[100];
    char cpf[20];
    char serie[4];
    char periodo[10];
    char endereco[80];
    char nomeResponsavel[100];
    char telefoneUm[16];
    char teleforneDois[16];
    char email[50];
} Dados;

    typedef struct {
    char deletado;
    char nome[100];
    char cpf[20];
    char placa[10];
    char marca[20];
    char modelo[20];
    char ano[5];
} Van;

    typedef struct {
    char deletado;
    int tipo;
    char placaVan[10];
    char usuario[USUARIO_MAX];
    char senha[SENHA_MAX];
} loginEstrutura;

    //  Gerenciamento
    void gerenciarMenu(int opcao, const char *funcionalidade, const char *nomeMenu);
    void montarMenu(const char *funcionalidade, const char *nomeMenu);

    //  Menus
    void cabecalho(void);
    void menuLogin(void);
    void menuPrincipal(void);
    void sobre(void);
    void menuAdministrador(void);
    void menuTransportador(void);
    void listaVanAlunos(const char *nomeMenu);
    void listaVanAlunosTransportes(const char *nomeMenu);

   //  Funções úteis
    void retornarMensagem(const char *mensagem);
    void esperaTecla(void);
    void limpaTela(void);
    void funcoesSystem(void);
    void mensagemOpcaoInvalida(void);
    int validacaoEntrada (char entradaTeclado[2]);
    void limpezaBuffer(void);

    //  Confirmação Alunos
    void confirmacaoConsultarAlunos(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoAlterarAlunos(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoExcluirAlunos(const char *funcionalidade, const char *nomeMenu);

    //  Confirmação Vans
    void confirmacaoConsultarVans(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoAlterarVans(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoExcluirVans(const char *funcionalidade, const char *nomeMenu);

    //  Confirmação Login
    void confirmacaoConsultarLogin(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoAlterarLogin(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoExcluirLogin(const char *funcionalidade, const char *nomeMenu);

    //  Confirmação Presença
    void confirmacaoPresenca(const char *funcionalidade, int lacoRepeticao);
    void confirmacaoConsultarPresenca(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoAlterarPresenca(const char *funcionalidade, const char *nomeMenu);
    void confirmacaoExcluirPresenca(const char *funcionalidade, const char *nomeMenu);

    //  Arquivo
    FILE *arq, *arq2;
    void verificacaoArquivoArq(void);
    void verificacaoArquivoArq2(void);
    void verificacaoConteudo(int verificador, char *mensagem, const char *nomeMenu);
    void verificacaoConteudo2(int verificador, char *mensagem, const char *funcionalidade, const char *nomeMenu);

    //  CRUD Alunos
    void cadastrarAlunos(const char *funcionalidade, const char *nomeMenu);
    void consultarAlunos(const char *funcionalidade, const char *nomeMenu);
    void alterarAlunos(const char *funcionalidade, const char *nomeMenu);
    void excluirAlunos(const char *matricula, const char *funcionalidade, const char *nomeMenu);

    //  CRUD Vans
    void cadastrarVans(const char *funcionalidade, const char *nomeMenu);
    void consultarVans(const char *funcionalidade, const char *nomeMenu);
    void alterarVans(const char *funcionalidade, const char *nomeMenu);
    void excluirVans(const char *placa, const char *funcionalidade, const char *nomeMenu);

    //  CRUD Logins
    void cadastrarLogin(const char *funcionalidade, const char *nomeMenu);
    void consultarLogin(const char *funcionalidade, const char *nomeMenu);
    void alterarLogin(const char *funcionalidade, const char *nomeMenu);
    void excluirLogin(const char *matricula, const char *funcionalidade, const char *nomeMenu);

#endif // FUNCOES_H_INCLUDED
