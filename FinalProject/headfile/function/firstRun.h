/*
=======================================================================================================================================================================
						File for the declaration of the first pass
=======================================================================================================================================================================
*/

/*	Enabling access to data structures which used in first run:
*/
	#include "line.h"
	#include "BinaruTable.h"
	#include "symbolTabel.h"
	#include "lists.h"
/*	
	 |The first pass function accepts pointers to structures and inside it runs a number
	 |of programs for splitting a string into tokens checking for errors in strings and and the 
	 |function of adding to lists and to the table of symbols of labels and operands.
	 |It is worth noting that if the assmbler lines have syntax errors, then the check ends at this stage.
	 |implementation is in firstRun.c
*/	 void first_pass(char* file_name,FILE *target,Line *parsed_line,BinaryTable* tabl_memori,symbol_table_entry** symbol_table,ExternList* extern_list, EntryList* 		    entry_list,JampList* list);
/*====================================================================================================================================================================*/



