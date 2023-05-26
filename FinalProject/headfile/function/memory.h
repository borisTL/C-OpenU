/*
========================================================================================================================================================================
			          This file contains the declaration of functions for converting assembler strings into binary code.
========================================================================================================================================================================
*/
/*
        |Structures that are used for conversion:
*/
	#include "line.h"
	#include "machincod.h"
	#include "BinaruTable.h"
	#include "symbolTabel.h"
	#include "lists.h"

/*	|The function starts the translation of the instruction string for converting,Gets the string that the native code converts through the structure
*/	void convert_to_machine_code_first_word(Line *line,BinaryTable* tabl_memori) ;


/*	|A function inside which there is a conversion of different operands and adding them to a binary table.
	|Receives structures from which information is extracted how to convert and then add to the binary table.
*/	void add_to_mamory_machine_code(Line *line,BinaryTable* tabl_memori,symbol_table_entry** symbol_table,ExternList* extern_list);






