#include "assambler.h"

/*===================================================================================================================================================================*/
void free_resources(macro_table_entry** macro_table, symbol_table_entry** symbol_table, ExternList* extern_list, JampList* jump_list, EntryList* entry_list, Line* parsed_line, BinaryTable* tabl_memori) {
   
	free_macro_table(macro_table,RAM);
	clear_extern_list(extern_list);

	free_entry_list(entry_list);

	free_jamp_list( jump_list);

	free_symbol_table(symbol_table);

	restLine(parsed_line);
	
	free_line(parsed_line);

	
	free_binary_table(tabl_memori);
}
/*===================================================================================================================================================================*/
void initialize_program(macro_table_entry*** macro_table, symbol_table_entry*** symbol_table, ExternList** extern_list,
    JampList** jump_list, EntryList** entry_list, Line** parsed_line, BinaryTable** binary_table) {
    
    *macro_table = create_macro_table(RAM);
    *symbol_table = create_symbol_table(RAM);
    *extern_list = create_extern_list();
    *jump_list = create_jump_list();
    *entry_list = create_entry_list();
    *parsed_line = create_empty_line();
    *binary_table = create_binary_table();
}
/*===================================================================================================================================================================*/
unsigned int hash(char *key, int size) 
{
    unsigned int h = 0;
    for (int i = 0; key[i] != '\0'; i++)
        h = (h * 31 + key[i]) % size;
   return h;
}
/*===================================================================================================================================================================*/
