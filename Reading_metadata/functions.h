#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct table_info{ //Estrutura que guarda as informações básicas da tabela
    int id;
    char log_name[20];
    char phy_name[20];
}Table_info;

typedef struct table_att{ //Estrutura que guarda as informações de atributos da tabela
    int id;
    char att_name[20];
    char type;
    char opt;
    int size;
}Table_att;

typedef struct table{  //Estrutura que compila as informações da básicas com as de atrtributo de uma tabela
    int size;
    Table_info meta;
    Table_att atributes[];
}Table;

typedef struct number_atributes{
    int general;
    int specific;
}Number_atributes;

int validate(FILE *f); //Verifica se um arquivo foi aberto corretamente

int numberof_table(FILE *f); //Calcula o número de tabelas em um arquivo

Number_atributes numberof_att(int table_id, FILE *att); //Calcula o número de atributos em um arqiuivo e em uma tabela especifica

Table_info* is_in_table(char log_name[], FILE *f); //Verifica se uma tabela está no arquivo

Table *setup_tab(FILE *f, Table_info *t, FILE *att); //Cria uma estrutura de tabela

void print_table(Table *t); //Imprime as informações (básicas e de atributos) de uma tabela

void read_table_content(Table *t); //Imprime o conteúdo de uma tabela

int readFile(char* name); //Função principal que recebe o nome da tabela

#endif // FUNCTIONS_H