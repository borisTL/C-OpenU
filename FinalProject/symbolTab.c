#include"assambler.h"
/*====================================================================================================================================================================*/
 struct symbol_table_entry
{
    char *name;        
    int address;     
    int is_code;       
    int is_data;      
    int is_entry;     
    int is_external;
	struct symbol_table_entry *next;  
} ;
/*===================================================================================================================================================================*/
Boolean has_no_external_symbol(symbol_table_entry * *symbol_table)
{
        size_t table_size = sizeof(symbol_table) / sizeof(symbol_table_entry *);
        for (size_t i = 0; i < table_size; i++)
        {
            symbol_table_entry *entry = symbol_table[i];
            while (entry != NULL)
            {
                if (entry->is_external)
                {
                    return FALSE;
                }
                entry = entry->next;
            }
        }
        return TRUE;
}
/*====================================================================================================================================================================*/
symbol_table_entry **create_symbol_table(int size)
{
    symbol_table_entry **symbol_table = malloc(sizeof(symbol_table_entry*) * size);
    if (symbol_table == NULL) {
        return NULL;
    }
    memset(symbol_table, 0, sizeof(symbol_table_entry*) * size);
    return symbol_table;
    
    
    free(symbol_table);
}
/*====================================================================================================================================================================*/
void set_symbol_table_entry_name(symbol_table_entry* entry, const char* name)
{
    char* name_copy = malloc(strlen(name) + 1);
    strcpy(name_copy, name);
    entry->name = name_copy;
}


/*====================================================================================================================================================================*/
void add_symbol(char *name, int address, int is_code, int is_data, int is_entry, int is_external, symbol_table_entry **symbol_table)
{
    unsigned int index = hash(name, RAM);

    symbol_table_entry *new_entry = malloc(sizeof(symbol_table_entry));
    new_entry->name = malloc(strlen(name) + 1);
    strcpy(new_entry->name, name);
    new_entry->address = address;
    new_entry->is_code = is_code;
    new_entry->is_data = is_data;
    new_entry->is_entry = is_entry;
    new_entry->is_external = is_external;
    new_entry->next = NULL;

    if (symbol_table[index] == NULL)
        symbol_table[index] = new_entry;
    else
    {
        symbol_table_entry *current_entry = symbol_table[index];
        while (current_entry->next != NULL)
        {
            current_entry = current_entry->next;
        }
        current_entry->next = new_entry;
    }
}
/*====================================================================================================================================================================*/
symbol_table_entry *lookup_symbol(char *name, symbol_table_entry **symbol_table)
{
    unsigned int index = hash(name, RAM);
    symbol_table_entry *current_entry = symbol_table[index];

    while (current_entry != NULL)
    {
        if (strcmp(current_entry->name, name) == 0)
        {
            return current_entry;
        }
        current_entry = current_entry->next;
    }
    return NULL;
}
/*====================================================================================================================================================================*/
int get_address_by_name(char *name, symbol_table_entry **symbol_table)
    {
        symbol_table_entry *entry = lookup_symbol(name, symbol_table);
        if (entry != NULL)
        {
            return entry->address;
        }
        else
        {
            printf("Label %s not found in symbol table\n", name); 
            return -1;
        }
    }
/*====================================================================================================================================================================*/
Label_type get_typeLabel(char *name, symbol_table_entry **symbol_table)
    {
        symbol_table_entry *entry = lookup_symbol(name, symbol_table);
        if (entry != NULL)
        {
            if (entry->is_data)
                return DATTA;

            else if (entry->is_code)
                return CODE;

            else if (entry->is_external)
                return EXTERN;

            else if (entry->is_entry)
                return ENTRY;
        }
        return NO_TYPE;
    }

/*===================================================================================================================================================================*/
void sort_symbol_table(symbol_table_entry **symbol_table)
{
    symbol_table_entry *temp;
    int i, j;

    for (i = 0; i < RAM-1; i++) {
        for (j = i + 1; j < RAM; j++) {
            if (symbol_table[i] != NULL && symbol_table[j] != NULL) {
                if (symbol_table[i]->address > symbol_table[j]->address) {
                    temp = symbol_table[i];
                    symbol_table[i] = symbol_table[j];
                    symbol_table[j] = temp;
                }
            }
        }
    }
}
/*===================================================================================================================================================================*/
void print_symbol_table(symbol_table_entry **symbol_table)
{
    printf("Symbol table:\n");
    printf("Name\tAddress\tCode\tData\tEntry\tExternal\n");
    sort_symbol_table(symbol_table);
    for (int i = 0; i < RAM; i++)
    {
        symbol_table_entry *current_entry = symbol_table[i];
        while (current_entry != NULL)
        {
            printf("%s\t%d\t%d\t%d\t%d\t%d\n",
                current_entry->name,
                current_entry->address,
                current_entry->is_code,
                current_entry->is_data,
                current_entry->is_entry,
                current_entry->is_external);
            current_entry = current_entry->next;
        }
    }
}
/*===================================================================================================================================================================*/
void free_symbol_table(symbol_table_entry **symbol_table)

{
    if (symbol_table == NULL) {
        return;
    }
    for (int i = 0; i < RAM; i++) {
        symbol_table_entry *current_entry = symbol_table[i];
        while (current_entry != NULL) {
            symbol_table_entry *temp_entry = current_entry;
            current_entry = current_entry->next;
            free(temp_entry->name);
            free(temp_entry);
        }
    }
    free(symbol_table);
}

/*===================================================================================================================================================================*/
 void update_symbol_table_flag(symbol_table_entry * *symbol_table, ExternList * extern_list, EntryList * entry_list)
    {
        for (int i = START_ADRESS; i < RAM; i++)
        {
            symbol_table_entry *current_entry = symbol_table[i];
            while (current_entry != NULL)
            {
                if (current_entry->is_external == 0)
                {
                    if (extern_list != NULL)
                    {
                        ExternNode *extern_node = find_extern_node(get_extern_list_head(extern_list), current_entry->name);
                        if (extern_node != NULL)
                        {
                            current_entry->is_external = 1;
                        }
                    }

                    if (entry_list != NULL)
                    {
                        EntryNode *entry_node = find_entry_node(get_entry_list_head(entry_list), current_entry->name);
                        if (entry_node != NULL)
                        {
                            current_entry->is_entry = 1;
                        }
                    }
                }
                current_entry = current_entry->next;
            }
        }
    }

/*===================================================================================================================================================================*/
void inToSymbolTable(Line * parsed_line, symbol_table_entry * *symbol_table, ExternList * extern_list, EntryList * entry_list, JampList * list)
    {
        update_symbol_adress(parsed_line);

        if (get_line_type(parsed_line) == DIRECTIVE_LINE)
        {
            if (get_line_directive(parsed_line) == string)
            {
                if (get_label_value(parsed_line) != NULL)
                    add_symbol(get_label_value(parsed_line), get_line_address(parsed_line), 0, get_line_DC(parsed_line), 0, 0, symbol_table);
            }

            else if (get_line_directive(parsed_line) == data)
            {
                if (get_label_value(parsed_line) != NULL)
                    add_symbol(get_label_value(parsed_line), get_line_address(parsed_line), 0, get_line_DC(parsed_line), 0, 0, symbol_table);
            }

            else if (get_line_directive(parsed_line) == extr)
            {
                if (get_operand1_value(parsed_line) != NULL)
                    add_extern_node(extern_list, get_operand1_value(parsed_line));
            }
            else if (get_line_directive(parsed_line) == entry)
            {
                if (get_operand1_value(parsed_line) != NULL)
                    add_entry_label(entry_list, get_operand1_value(parsed_line));
            }
        }
        else if (get_line_type(parsed_line) == INSTRUCTION_LINE)
        {
            if (get_label_value(parsed_line) != NULL)
                add_symbol(get_label_value(parsed_line), get_line_address(parsed_line), get_line_IC(parsed_line), 0, 0, 0, symbol_table);

            if (get_line_instruction(parsed_line) == jmp || get_line_instruction(parsed_line) == bne || get_line_instruction(parsed_line) == jsr)
                add_jump_label(list, get_operand1_value(parsed_line));
        }
        set_line_address(parsed_line, get_line_DC(parsed_line) + get_line_IC(parsed_line) + get_line_address(parsed_line));
    }
/*===================================================================================================================================================================*/
void update_symbol_adress(Line * parsed_line)
    {
        if (get_line_type(parsed_line) == DIRECTIVE_LINE)
        {
            if (get_line_directive(parsed_line) == string && get_operand1_value(parsed_line) != NULL)
                set_line_DC(parsed_line, strlen(get_operand1_value(parsed_line)) + 1);

            else if (get_line_directive(parsed_line) == data && get_line_in_data(parsed_line) != NULL)
                set_line_DC(parsed_line, count_elements_indata(get_line_in_data(parsed_line)));
        }
        else if (get_line_type(parsed_line) == INSTRUCTION_LINE)
            updet_IC(parsed_line);
    }
/*===================================================================================================================================================================*/
void write_entries_to_file(EntryList * entry_list, symbol_table_entry * *symbol_table, char *filename)

{

    char *new_filename = add_ext_to_filename(filename, ".ent");
    FILE *file = fopen(new_filename, "w");
    if (file == NULL)
    {
        printf("Error open %s.\n", new_filename);
        free(new_filename);
        return;
    }

    EntryNode *current_node = get_entry_list_head(entry_list);

    int found_entry = 0;

    while (current_node != NULL)
    {

        char *label = get_label(current_node);

        symbol_table_entry *symbol_entry = lookup_symbol(label, symbol_table);

        if (symbol_entry != NULL )
        {
            found_entry = 1;
            fprintf(file, "%s %d \n", label, symbol_entry->address);
        }
        current_node = get_next_node(current_node);
    }

    if (!found_entry)
    {
      
        fclose(file);
        remove(new_filename);
    }
    else
    {
        fclose(file);
    }

    free(new_filename);

}

/*===================================================================================================================================================================*/
