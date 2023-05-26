#include"assambler.h"

/*====================================================================================================================================================================*/
 struct macro_table_entry
{
    char *name;          
    char *definition;     
    struct macro_table_entry *next;   
} ;

/*====================================================================================================================================================================*/
macro_table_entry **create_macro_table(int size)
{
    macro_table_entry **table = (macro_table_entry **)malloc(size * sizeof(macro_table_entry *));
    memset(table, 0, size * sizeof(macro_table_entry *));
    return table;
}
/*====================================================================================================================================================================*/
void free_macro_table(macro_table_entry **table, int size)
{
    for (int i = 0; i < size; i++)
    {
        macro_table_entry *current_entry = table[i];
        while (current_entry != NULL)
        {
            macro_table_entry *temp_entry = current_entry;
            current_entry = current_entry->next;
            free(temp_entry->name);
            free(temp_entry->definition);
            free(temp_entry);
        }
    }
    free(table);
}
/*====================================================================================================================================================================*/
void macro_table_insert(char *name, char *definition,macro_table_entry** macro_table)
{
    unsigned int h = hash(name, MACRO_TABLE_SIZE);
    macro_table_entry *e = (macro_table_entry *)malloc(sizeof(macro_table_entry));

    e->name = (char *)malloc(strlen(name) + 1);
    strcpy(e->name, name);
    e->definition = (char *)malloc(strlen(definition) + 1);
    strcpy(e->definition, definition);
    e->next = macro_table[h];
    macro_table[h] = e;
}
/*====================================================================================================================================================================*/
macro_table_entry *macro_table_lookup(char *name,macro_table_entry** macro_table)
{
    unsigned int h = hash(name, MACRO_TABLE_SIZE);
    macro_table_entry *e = macro_table[h];
    while (e != NULL && strcmp(name, e->name) != 0)
        e = e->next;
    
    return e;
}
/*====================================================================================================================================================================*/
void print_macro_table(macro_table_entry **table, int size)
{	
    printf("Macro table:\n");
    for (int i = 0; i < size; i++)
    {
        macro_table_entry *entry = table[i];
        while (entry != NULL)
	{
            printf("%s:%s\n", entry->name, entry->definition);
            entry = entry->next;
        }
    }
}
/*====================================================================================================================================================================*/
char* getvalue(macro_table_entry **table, char *name)
{
    unsigned int h = hash(name, MACRO_TABLE_SIZE);
    macro_table_entry *entry = table[h];
    while (entry != NULL)
    {
        if (strcmp(entry->name, name) == 0)
	{
            return entry->definition;
        }
        entry = entry->next;
    }
    return NULL; 
}
/*====================================================================================================================================================================*/
