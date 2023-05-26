/*======================================================================================================================================================================
						String processing function declarations

	|Implementation is in lexer.c
=========================================================================================================================================================================
*/

/*	Enabling access to data structures:
*/
	#include "line.h"
	#include "symbolTabel.h"
	#include "lists.h"

/*	The function splits the string into tokens and processes the string
	The function adds tokens to the line structure depending on the keywords instruction, directive, 
	places in the operand linedivision into tokens is divided into four types for strings of functions
	of the append is divided with () for row string "" row data and and instruction strings
*/	void parse_line(char *line, Line *parsed_line,symbol_table_entry **symbol_table, ExternList* extern_list,EntryList* entry_list);


/*	Function determines the type of operands
	The function receives pointers to data structures and performs a check on the operands in the structures
	and assigning types to them if the operand is not found in any of the structures, then this operand will
	be defined as not known, which will cause an error. This function is used in the second pass when the data 
	is collected.
	in the first pass, some variables will be defined as unknown because not all data has been collected.	
*/	Operand_type get_operand_type(char *operand, Line *line,symbol_table_entry **symbol_table,ExternList* extern_list, EntryList* entry_list);
/*===================================================================================================================================================================*/
