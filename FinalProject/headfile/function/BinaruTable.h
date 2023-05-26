#ifndef BINARY_TABLE_H
#define BINARY_TABLE_H
/*
========================================================================================================================================================================
								 BinaruTable.h

  |In this file, an array of structures for a binary code is declared, we create a bit type
  |variable, after an array of bit type is created and after that it is    combined into a table of binary  
  |words,field implementation goes in C file.

  typedef struct         /struct BinaryWord		/struct BinaryTable
   unsigned int on :1; ==>BinalriLineType type =========>BinaryWord* words[RAM]
   Bit		         \Bit digit[SIZE_WORD]	 	\int size;

========================================================================================================================================================================
*/  
                                                                                      
/* 	Definitions of kinds of binary words words of kind and statements of words of type directive.
*/ 	typedef enum {instrction, derectiv,no_type} BinalriLineType;

/* 	Data type declaration binary word.
*/ 	typedef struct BinaryWord BinaryWord;

/* 	Data type definition binary table.
*/ 	typedef struct BinaryTable BinaryTable;

/* 	A function free_binary_word: that deletes a binary word variable. 
*/ 	void free_binary_word(BinaryWord** word);

/* 	Set_binary_table_size->function inserts address into pointer.
*/ 	void set_binary_table_size(BinaryTable* table, int size);

/* 	get_binary_table_size:A function that returns the size of a binary character.
*/ 	int get_binary_table_size(BinaryTable* table);

/* 	Function is used to convert instruction string to binary code.
*/ 	void firstword_to_binary_word(char* str,BinaryTable* tabl_memori);

/* 	Auxiliary function for converting acai codes into binary form
*/ 	BinaryWord char_to_binary_word(char c);

/* 	Functions are used to translate a string into binary code.
*/ 	void string_to_binary_words(char* str,BinaryTable* table,Line *line);

/* 	free_binary_tabl->clear table function.
*/ 	void free_binary_table(BinaryTable* table);

/* 	creat binary table function,gets the type of the operand and the operand itself.
*/ 	BinaryTable* create_binary_table();

/*	Function add to binary table
*/	void add_to_binary_table(BinaryTable* table, BinaryWord* word, BinalriLineType type);

/*	Helper function for debugging prints table.
*/	void print_binary_table(BinaryTable* table);

/*	Function converts strings of date type to binary code.
*/	void data_to_binary_words(char* str, BinaryTable* tabl_memori, Line* line);

/*	Function to convert sourse registers to binary code.
*/	void register_sourse_to_binary_table(char* reg_str, BinaryTable* tabl_memori);

/*	Function to convert def registers to binary code.
*/	void register_def_to_binary_table(char* reg_str, BinaryTable* tabl_memori);

/*	Function to convert two registers to binary code.
*/	void two_register_to_binary_table(char* reg_str1, char* reg_str2, BinaryTable* tabl_memori);

/*	Function converts operand addresses to binary code.
*/	void number_to_binary_table(int num, BinaryTable* tabl_memori);

/*	Function converts number to binary code.
*/	void immediate_to_binary_word(char* imm_str, BinaryTable* tabl_memori);

/*	The function adds a new element to the binary table.
*/	void add_name_to_binary_table(BinaryTable* table, char *name);

/*	Function converts exter operand to binary code.
*/	void extern_to_binary_table( BinaryTable* table_memory);

/*	Function rest table all operand on NULL.
*/	void reset_binary_table(BinaryTable* table);

/*	Function creates file.ob if do not have error in asambler file. 
*/ 	void write_convertBinary_table_to_file(BinaryTable* table, char* filename);

#endif /* BINARY_TABLE_H */

