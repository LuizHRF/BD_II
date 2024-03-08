#include <stdio.h>
#include <stdlib.h>
#include "functions.c"

//  gcc [aplicativo].c -o [nome executável de saída] para compilar
//  .\[executável] [argumento de entrada] para executar


//Duas coisas não funcionam, a contagem de tabelas está contabilizando uma extra, atributos tmb. Além disso, a contagem de atributos está incorreta.

int main(int argc, char *argv[]){

    //argv[1] para acessar o input
    
    FILE *tables_file = fopen("homework/table.dic", "r+"); //Abre arquivo

    if(!validate(tables_file)){return EXIT_FAILURE;} //Verifica se abriu corretamente
    
    Table_info *table_info = is_in_table(argv[1], tables_file); //Verifica se o nome logico passado por parametro existe entre as tabelas

    if(table_info != NULL){

        FILE *att = fopen("homework/att.dic", "r+"); //Se existir, abre o arquivo de atributos
        Table *Final = setup_tab(tables_file, table_info, att);

        print_table(Final);
    }

    printf("Aperte enter para finalizar\n");
    char ch=fgetc(stdin);
}
