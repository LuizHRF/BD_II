#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct table_info{ 
    int id;
    char log_name[20];
    char phy_name[20];
}Table_info;

typedef struct table_att{
    int id;
    char att_name[20];
    char type;
    int opt;
}Table_att;

typedef struct table{
    Table_info *meta;
    Table_att *atributes;
}Table;

typedef struct number_atributes{
    int general;
    int specific;
}Number_atributes;

int validate(FILE *f){
    if (f == NULL){
        printf("\nFalha ao abrir arquivo\n\n");
        return 0;
    } else {
        printf("\nArquivo aberto com sucesso\n\n");
        return 1;
    }

    rewind(f);
}

int numberof_table(FILE *f){ //Calcula o número de tabelas de um arquivo

    int n = 0;
    
    while(!feof(f)){
        Table_info table1;
        fread(&table1, sizeof(Table_info), 1, f);

        printf("Nome: %s\tID: %d\tLocal: %s\n", table1.log_name, table1.id, table1.phy_name);
        n+=1;
    }

    rewind(f);
    return n;
}

Number_atributes numberof_att(int table_id, FILE *att){ //Calcula o numero de atributos. Tanto gerais (todos do arquivo) qaunto da tabelas especificas
    
    Number_atributes NA;
    NA.general = 0;
    NA.specific = 0;

    while(!feof(att)){
        Table_att table_att1;
        fread(&table_att1, sizeof(Table_att), 1, att);

        if(table_att1.id == table_id){
            NA.specific+=1;
        }

        NA.general=1;
    }

    return NA;
}

Table_info* is_in_table(char log_name[], FILE *f){ //Identifica se dada tabela existe
    int n = numberof_table(f);
    int count = 0;
    Table_info tables[n];

    while(!feof(f)){
        Table_info t;
        fread(&t, sizeof(Table_info), 1, f);

        strcpy(tables[count].log_name, t.log_name);
        strcpy(tables[count].phy_name, t.phy_name);
        tables[count].id = t.id;

        count+=1;
    }

    //printf("Número de tabelas: %d\n", n);

    for(int i=0; i<n; i++){

        if(!strcmp(log_name, tables[i].log_name)){
            printf("\nTabela encontrada\n\n");
            Table_info *ta = &tables[i];
            return ta;
        }
    }

    printf("Tabela nao encontrada\n\n");
    return NULL;
}

Table *setup_tab(FILE *f, Table_info *t, FILE *att){ //Retorna uma estrutura pronta com todas infos de uma tabela e também de seus campos
    Table table_done;
    table_done.meta = t;
    Number_atributes n = numberof_att(t->id, att);

    printf("Preparando Tabela, número de campos: %d\n", n.specific);

    Table_att atributes[n.specific];
    int specific_count = 0;

    for(int i=0; i<n.general; i++){

        Table_att temp;
        fread(&temp, sizeof(Table_att), 1, att);

        if(temp.id == t->id){
            atributes[specific_count] = temp;
            specific_count+=1;
        }
        
    }

    table_done.atributes = atributes;
}

void print_table(Table *t){
    printf("ID: %d\tNOME:%s\tLOCAL:%s\n", t->meta->id, t->meta->log_name, t->meta->phy_name);
    printf("Atributos:\n");

    int n = numberof_att(t->meta->id, (fopen("homework/att.dic", "r+"))).specific; //Um print bem custoso
    for(int i=0; i<n; i++){
        printf("<%d, %s, %c, %d\n>", t->atributes->id, t->atributes->att_name, t->atributes->type, t->atributes->opt);
    }

}