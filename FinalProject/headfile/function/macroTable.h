#ifndef MACRO_TABLE_ENTRY_H
#define MACRO_TABLE_ENTRY_H
/*
========================================================================================================================================================================
|Declaration of the hash table name and functions for working with it the table is implemented in macroTable.c
|there is also an announcement of functions for working with macros
|
| struct macro_table_entry
|    char *name                      ->name of macro  
|    char *definition                ->macro text
|    struct macro_table_entry *next;   
|
========================================================================================================================================================================
*/
	typedef struct macro_table_entry macro_table_entry;

/*	Function that create table
*/	macro_table_entry **create_macro_table(int size);


/*	Function that delet table
*/	void free_macro_table(macro_table_entry **table, int size);


/*	Function that add new operand in table
*/	void macro_table_insert(char *name, char *definition,macro_table_entry** macro_table);

/*	Function that find name of key in table 
*/	macro_table_entry *macro_table_lookup(char *name,macro_table_entry** macro_table);

/*	Helper function prints a table
*/	void print_macro_table(macro_table_entry **table, int size);

/*	Returns a value from a table
*/
	char* getvalue(macro_table_entry **table, char *name);
/*===================================================================================================================================================================*/
#endif /* MACRO_TABLE_ENTRY_H */
