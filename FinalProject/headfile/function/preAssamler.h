/*
========================================================================================================================================================================
								    preAssamler.h	
========================================================================================================================================================================
	|This file declares functions for collecting macros from a file and copying files with the release of macro text by keys.
*/
	
/*	|Including structs for functions:
*/	
	#include "line.h"
	#include"macroTable.h"


/*	|Function to write macro to table
  	|bypasses the file finds mcr adds the name to the key and everything else to the text of the macro until the end of the macro is found.
*/	 void perAssambler(FILE *in_file,FILE *out_file, macro_table_entry** macro_table, Line *linem);


/*	|The function that rewrites the macro to the file is named and removes the macro definitions from the file.
*/	 void replace_keys_with_values(FILE *in_file,FILE *out_file,macro_table_entry** macro_table);
/*====================================================================================================================================================================*/
