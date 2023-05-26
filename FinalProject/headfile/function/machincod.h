#ifndef MACHINE_CODE_H
#define MACHINE_CODE_H
/*====================================================================================================================================================================
  						Translation file of instruction type string
  |In this filedeclaration of a structure name to generate a binary code for a string of type instruction.
  |It contains the operand, address method, and area fields.
  |also there is a declaration of functions to create delete and get/set functions of structure fields for work in other files
  |and look :

	|struct MachineCode  
	|unsigned short int are : 2;		-> current are  
	|unsigned short int addr_mode2 : 2;	-> current addr2_mode
	|unsigned short int addr_mode1 : 2;	-> current addr1_mode
	|unsigned short int opcode : 4;		-> opcode
	|unsigned short int op2 : 2;		-> operand1
	|unsigned short int op1 : 2; 		->operand2
	|each field has a number of bits
====================================================================================================================================================================*/
/*	Structure declaration
*/	typedef struct MachineCode MachineCode;

/*	Function create struct
*/	MachineCode* create_machine_code();

/*	The function will write the binary code of the instruction	
*/	void fmachine_code_to_binary(MachineCode* mc, char* code_word);

/*	function will remove structur
*/	void free_machine_code(MachineCode* mc);

/*	Below is a list of functions that set bits depending on the information they receive in a binary word
	Functions are used to interact with other files
*/
/*	Function set are
*/	void set_are(MachineCode* mc, unsigned short int are);

/*	Function get are
*/	unsigned short int get_are(MachineCode* mc);

/*	Function set addr_mode2
*/	void set_addr_mode2(MachineCode* mc, unsigned short int addr_mode2);

/*	Function get addr_mode2
*/	unsigned short int get_addr_mode2(MachineCode* mc);

/*	Function set opcode
*/	void set_machine_code_opcode(MachineCode* mc, unsigned short int opcode);

/*	Function get opcode
*/	unsigned short int get_machine_code_opcode(MachineCode* mc);

/*	Function set addr_mode1
*/	void set_addr_mode1(MachineCode* mc, unsigned short int addr_mode1);

/*	Function get add_mode1
*/	unsigned short int get_addr_mode1(MachineCode* mc);

/*	Function set operand1
*/	void set_machine_code_op1(MachineCode* mc, unsigned short int op1);

/*	Function get operand1
*/	unsigned short int get_machine_code_op1(MachineCode* mc);

/*	Function get operabd2
*/	void set_machine_code_op2(MachineCode* mc, unsigned short int op2);

/*	Function set operand2
*/	unsigned short int get_machine_code_op2(MachineCode* mc) ;
/*====================================================================================================================================================================*/
#endif 
