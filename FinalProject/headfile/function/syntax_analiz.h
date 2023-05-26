/*
======================================================================================================================================================================
								         syntax_analiz.h
======================================================================================================================================================================

	|In this file, there is a function declaration for parsing
*/

/*	|Iincluding data structures for the function to work
*/	
	#include "line.h"
	#include "symbolTabel.h"
	#include "lists.h"


/*	|A function that checks sintax in line which were defined in the project |
*/	 void syntax_analiz(Line *parsed_line,symbol_table_entry **symbol_table,ExternList* extern_list,EntryList* entry_list);

/*	|The function counts the number comma.
*/	int count_comma(char *line);

/*	|The function counts the number quotes.
*/	int count_quotes(char *line);

/*	The function counts the number baskets.
*/	int count_scob(char *line);


/*	|The function counts the number in .data.
*/	int count_elements_indata(char *str);

/*	|Check for invalid characters in .string.
*/	Boolean check_string_of_abc(char *string);

/*	Check for invalid characters in .data.
*/	Boolean check_data_operand(char *data_str,Line *parsed_line);

/*	|Function check if comma between operands. 
*/ 	 Boolean comma_between(char* str,Line *parsed_line );

/*	|Function check for invalid name of label|
*/	Boolean check_lable(char *label);

/*	|Function check for invalid name of operand|
*/	Boolean check_operand(char *operand);

/*	|Function check for invalid name of macro.
*/	Boolean check_macro_name(char *label);

/*	|Function check for invalid type of operand.
*/	void analiz_operand(Line *line,JampList* jump_lis,symbol_table_entry **symbol_table);

/*	|The function looks for the first occurrence of a string as a whole word.
*/	char* strstr_word(const char* str1, const char* str2);

/*	|Function check string of #line.
*/	 Boolean is_valid_number(const char* str,Line *line);

/*	|Function that creates a copy of the specified null-terminated string on the heap (using malloc) 
  	|and returns a pointer to it. To free up space used by the created copy.
*/	 char* strdup(const char* str);

/*===================================================================================================================================================================*/

