#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H
/*
======================================================================================================================================================================
								    symbolTable.h
======================================================================================================================================================================

      |In this file there is a declaration of a hash table for labels and a declaration of a function for working with a table
      | and a get / set function for working with   other files.
*/

/*	|Including structs for functions work:
*/
	#include "line.h"
	#include "lists.h"

/*	Declaration of the hash table name and functions for working with it the table is implemented in symbolTable.c.
*/	typedef struct symbol_table_entry symbol_table_entry;


/*	Function for creat table.
*/	symbol_table_entry **create_symbol_table(int size);

/*	Function for add new label.
*/	void add_symbol(char *name, int address, int is_code, int is_data, int is_entry, int is_external, symbol_table_entry **symbol_table);

/*	Function to check if the operand is in a table.
*/	symbol_table_entry *lookup_symbol(char *name, symbol_table_entry **symbol_table);

/*	The function determines the label type.
*/	Label_type get_typeLabel(char *name, symbol_table_entry **symbol_table);



/*	Function for sort table.
*/	void sort_symbol_table(symbol_table_entry **symbol_table);

	
/*	Debagin fuction for print table.
*/	void print_symbol_table(symbol_table_entry **symbol_table);


/*	Function removes table.
*/	void free_symbol_table(symbol_table_entry **symbol_table);

/*	Function returns address by name.
*/	int get_address_by_name(char* name, symbol_table_entry** symbol_table);

/* 	Functions get symbol table name.
*/	char* get_symbol_table_entry_name(const symbol_table_entry* entry);

/*	Function set symbol table name.
*/	void set_symbol_table_entry_name(symbol_table_entry* entry, const char* name);


/*	The function updates the flag and using lists for this.
*/	void update_symbol_table_flag(symbol_table_entry** symbol_table, ExternList* extern_list, EntryList* list);

/*	The function adds a different type of label.
*/	void inToSymbolTable(Line *parsed_line,symbol_table_entry **symbol_table,ExternList* extern_list,EntryList* list,JampList* jump_list);


/*	The function check if label extern type.
*/	Boolean has_no_external_symbol( symbol_table_entry **symbol_table);


/*	Function updates address of label.
*/ 	void update_symbol_adress(Line *parsed_line);

/*	The function creates an entry file if the entry is empty or the entry is not used in the file, then the file will not be created.
*/	void write_entries_to_file(EntryList* entry_list, symbol_table_entry** symbol_table, char* filename);

/*====================================================================================================================================================================*/
#endif /* SYMBOL_TABLE_ENTRY_H */

