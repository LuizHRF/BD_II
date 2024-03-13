#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

//  gcc [aplicativo].c -o [nome executável de saída] para compilar
//  .\[executável] [argumento de entrada] para executar


//A contagem de tabelas está contabilizando uma extra, atributos tmb


int main(int argc, char *argv[]){
     
    if (argc>1)
    {
        readFile(argv[1]);
        return 0;
    }
    printf("Missing parameter: logical file name\n");
    return 0;
    
}