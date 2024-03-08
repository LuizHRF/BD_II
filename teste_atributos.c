#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//App pra testar se a contagem de Atributos está correta (não está)
//Por que os valores de opcionalidade estão assim?

typedef struct table_att{
    int id;
    char att_name[20];
    char type;
    int opt;
}Table_att;

typedef struct number_atributes{
    int general;
    int specific;
}Number_atributes;

Number_atributes numberof_att(int table_id, FILE *att){ //Calcula o numero de atributos. Tanto gerais (todos do arquivo) qaunto da tabelas especificas
    
    Number_atributes NA;
    NA.general = 0;
    NA.specific = 0;
    printf("Atributos:\n");

    while(!feof(att)){
        Table_att table_att1;
        fread(&table_att1, sizeof(Table_att), 1, att);
        printf("ID: %d\tNome:%s\tTipo: %c\tOpt: %d\n", table_att1.id, table_att1.att_name, table_att1.type, table_att1.opt);

        if(table_att1.id == table_id){
            NA.specific+=1;
        }

        NA.general+=1;
    }

    return NA;
}

int main(int argc, char *argv[]){

    FILE *atributos = fopen("homework/att.dic", "r+");
    Number_atributes NA = numberof_att(111, atributos);

    printf("\nNumero de att: %d, %d\n", NA.general, NA.specific);
}