
#include "functions.h"

//  gcc Main.c functions.c -o [nome executável de saída] para compilar
//  .\[executável] [argumento de entrada] para executar

int main(int argc, char *argv[]){
     
    if (argc==2)
    {
        readFile(argv[1]);
        return 0;
    }else if (argc > 2){
        printf("Too many parameters\n");
    } else {
        printf("Missing parameter: logical file name\n");
        }
    return 0;
    
}