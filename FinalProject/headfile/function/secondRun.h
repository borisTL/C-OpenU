/*
========================================================================================================================================================================
 									    secondRun.h
========================================================================================================================================================================
 |The file with the declaration of the second pass inside the function is splitting the string into tokens
 |and  checking the types of operands whether they correspond to the conditions of the project and if so,
 |then the function is called which first converts the stringsand then adds them to the table
*/

/*	|Iincluding data structures for the function to work
*/
	 #include "line.h"
	 #include "BinaruTable.h"
	 #include "symbolTabel.h"
	 #include "lists.h"


/*	|In the second pass, the string is divided into tokens, checking the types of operands and encoding in binary form.
*/	void secondRun(char* file_name,FILE *target,Line *parsed_line,BinaryTable* tabl_memori,symbol_table_entry** symbol_table,ExternList* extern_list, EntryList* 				entry_list,JampList* jump_list);
	
/*====================================================================================================================================================================*/
