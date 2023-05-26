#include "assambler.h"

/*===================================================================================================================================================================*/
void secondRun(char *file_name,FILE *target,Line *parsed_line,BinaryTable* tabl_memori,symbol_table_entry** symbol_table,ExternList* extern_list, EntryList* entry_list,JampList* jump_list)
{
	target = fopen(file_name, "r");

	set_line_address(parsed_line,START_ADRESS);

	set_number_line(parsed_line,FIRST_LINE);

	char *line=(char *)malloc(MAX_LEN*sizeof(char));

	while (fgets(line, MAX_LEN, target) != NULL && get_error(parsed_line)==FALSE)
	{

		parse_line(line, parsed_line,symbol_table,extern_list, entry_list);

		analiz_operand(parsed_line,jump_list,symbol_table);

		update_symbol_adress(parsed_line);

		set_line_address(parsed_line,get_line_DC(parsed_line)+get_line_IC(parsed_line)+get_line_address(parsed_line));

		if(get_error(parsed_line)==FALSE)
		{
			if(get_line_directive(parsed_line)!=extr ||get_line_directive(parsed_line)!=entry)

				add_to_mamory_machine_code(parsed_line,tabl_memori,symbol_table, extern_list);
		}
		if(get_binary_table_size(tabl_memori)>RAM-1)
		{
			set_error(parsed_line,TRUE);

			printf("Line %d.<Error: table size big of size RAM>\n", get_number_line(parsed_line));
		}
		

	}
	fclose(target);
	free(line);

}
/*===================================================================================================================================================================*/
