#include"assambler.h"

/*===================================================================================================================================================================*/
void first_pass(char* file_name,FILE *target,Line *parsed_line,BinaryTable* tabl_memori,symbol_table_entry** symbol_table,ExternList* extern_list,EntryList* entry_list,JampList* jamp_list)
{
	target = fopen(file_name, "r");
	char *line=(char *)malloc(MAX_LEN*sizeof(char));

	while (fgets(line, MAX_LEN, target) != NULL && get_error(parsed_line)==FALSE)
	{

		parse_line(line, parsed_line,symbol_table,extern_list, entry_list);
		syntax_analiz(parsed_line,symbol_table,extern_list, entry_list);

		if(get_error(parsed_line)==FALSE)
			inToSymbolTable(parsed_line,symbol_table,extern_list,entry_list,jamp_list);

	}
	
	update_symbol_table_flag(symbol_table,  extern_list, entry_list);
	fclose(target);
	free(line);


}
/*===================================================================================================================================================================*/


