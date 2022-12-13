#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funcoes.h"

int validacaoEntrada(char entradaTeclado[2])
{
    char *parteTexto;
    int tamanhoTexto;

    strtol(entradaTeclado, &parteTexto, 10);
    tamanhoTexto = strlen(parteTexto);

    if(tamanhoTexto == 1){
        return 0;
    }
    else
    {
        return 1;
    }
}

