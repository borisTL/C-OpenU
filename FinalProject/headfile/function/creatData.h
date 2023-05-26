/*
=======================================================================================================================================================================
									CreatData.h
=======================================================================================================================================================================	
	
	|A file that declares functions for creating and deleting data structures and Hash function for tables.
        |Implementation is in creatData.c
*/


/*	|Declaration of access to structures for these functions.
*/	
	#include "line.h"
	#include "BinaruTable.h"
	#include"macroTable.h"
	#include "symbolTabel.h"
	#include "lists.h"

/*	|Hash function to create hash table macro and symbol.
*/	 unsigned int hash(char *key, int size);

/*	|A function that removes all data structures that are used in the project.
*/	 void free_resources(macro_table_entry** macro_table, symbol_table_entry** symbol_table, ExternList* extern_list, JampList* jump_list, EntryList* entry_list, 					Line* parsed_line, BinaryTable* tabl_memori);

/*	|A function that creat all data structures that are used in the project.
*/	 void initialize_program(macro_table_entry*** macro_table, symbol_table_entry*** symbol_table, ExternList** extern_list,
    	 JampList** jump_list, EntryList** entry_list, Line** parsed_line, BinaryTable** binary_table);

