#ifndef LINE_H
#define LINE_H
/*
========================================================================================================================================================================
The line structure is used to collect information from lines from a file
The file contains an example of fields and function declarations	
Type of structure:

	|LineType type;                         -> typedef enum{EMPTY_LINE,COMMENT_LINE,DIRECTIVE_LINE,INSTRUCTION_LINE,START_LINE} LineType
  	|Derectiv_type directive;               -> typedef enum{string,data,entry,extr,no_derectiv} Derectiv_type;
  	|Instruction_type instruction;	        -> typedef enum{mov,cmp,add,sub,nott,clr,lea,inc,dec,jmp,bne,red,prn,jsr,rts,stop,no_instruction} Instruction_type;
	
	
		
  	|Operand operand1;\    		        / typedef struct operand
  	|Operand operand2; ========== stucrt  ->   Operand_type type;     ->typedef enum{REGISTER,NUMBER,JUMP,NOT_DEFINED,DATA,EXT,ENT,COD,INVALID} Operand_type;
  	|Operand extra;	  /	     operand	\ char *value;} Operand
				
  	|Count_Type_instruction count_operand;	->typedef enum{one_operand,two_operand,no_operand,data_operand,jump_operand(for 1 paremetrs)
								,big_jamp(for 3 parameters),invalid}Count_Type_instruction;
					
						/typedef struct label
  	|Label label;================= struct ->  Label_type type;
				       label	\char *value;} Label
 

  	|Boolean error;				->typedef enum{TRUE,FALSE} Boolean;
  	|int quotes;				-> count quotes in the line
  	|int comma;				-> count comma in the line 
  	|char *in_data;				-> string for data operands
  	|int count_data;			-> count data operand 
  	|char *clon;				-> clon of line
  	|int address;				-> adress in tables
  	|int IC;				-> IC
  	|int DC;				-> DC
  	|int number_line;			-> number of line in thr file 
	
	struct implementation done in line.c
========================================================================================================================================================================
*/
/*	Types of information

*/	typedef enum{EMPTY_LINE,COMMENT_LINE,DIRECTIVE_LINE,INSTRUCTION_LINE,START_LINE} LineType;

	typedef enum{string,data,entry,extr,no_derectiv} Derectiv_type;

	typedef enum{REGISTER,NUMBER,JUMP,NOT_DEFINED,DATA,EXT,ENT,COD,INVALID} Operand_type;

	typedef enum{DATTA,CODE,EXTERN,ENTRY,NO_TYPE}Label_type;
	
	typedef enum{mov,cmp,add,sub,nott,clr,lea,inc,dec,jmp,bne,red,prn,jsr,rts,stop,no_instruction} Instruction_type;
	
	typedef enum{TRUE,FALSE} Boolean;

	typedef enum{one_operand,two_operand,no_operand,data_operand,jump_operand,big_jamp,invalid_count}Count_Type_instruction;

/*	Structure declaration line that works performs the function of collecting information and parsing lines is implemented in the line.c file
*/	typedef struct line_t Line;
/*===================================================================================================================================================================*/

/*	Function updates counter IC|
*/	void updet_IC(Line *line);

/*	The function resets all variables|
*/	void restLine(Line *parsed_line);
	
/*|	Function creates a line structure
*/	Line* create_empty_line();

/*	The function deletes the line structure|
*/	void free_line(Line* line);

/*	All the functions below refer to the get set functions for the struct line
*/

/*	Function for set type error
*/	void set_error(Line* line, Boolean error);
/*
	Function for get type error
*/	Boolean get_error(Line* line);
/*
	Function set count comma in line
*/	void set_line_comma_count(Line *line, int comma);
/*
	Function get count comma
*/	int get_line_comma_count(Line *line);
/*
	Function of count quotes
*/	void set_line_quotes_count(Line* line, int value);
/*
	Function fir get count qoutes
*/	int get_line_quotes_count(Line* line);
/*
	Function for set clon of line
*/	void set_clon(Line* line, char* clon);
/*
	Function for get clon of line
*/	char* get_clon(Line* line);
/*
	Function get line type
*/	LineType get_line_type(Line *line);
/*
	Function set line type
*/	void set_line_type(Line *line, LineType type);
/*
	Function set of label type
*/	void set_label_type(Line* line, Label_type type);
/*
	Function get label type
*/	Label_type get_label_type(Line* line) ;
/*
	Function set value of label
*/	void set_label_value(Line* line, char* value);
/*
	Function get value label
*/	char* get_label_value(Line* line);
/*
	Function set line instruction 
*/	void set_line_instruction(Line* line, Instruction_type instruction);
/*
	Function get line instruction
*/	Instruction_type get_line_instruction(Line* line);
/*
	Function set count of operands in the line
*/	void set_line_count_operand(Line* line, Count_Type_instruction count_operand);
/*
	Function get count of operands in the line
*/	Count_Type_instruction get_line_count_operand(Line* line);
/*
	Function set type of operand1
*/	void set_operand1_type(Line* line, Operand_type type);
/*
	Function get type of operand1
*/	Operand_type get_operand1_type(Line* line) ;
/*
	Function set value of operand1
*/	void set_operand1_value(Line* line, char* value);
/*
	Function get value of operand1
*/	char* get_operand1_value(Line* line);
/*
	Function set type if operand2
*/	void set_operand2_type(Line* line, Operand_type type);
/*
	Function get type operand2
*/	Operand_type get_operand2_type(Line* line) ;
/*
	Function set value operand2
*/	void set_operand2_value(Line* line, char* value);
/*
	Function get operand2
*/	char* get_operand2_value(Line* line);
/*
	Function set extra operand
*/	void set_extra_type(Line* line, Operand_type type);
/*
	Function get extta operand
*/	Operand_type get_extra_type(Line* line) ;
/*
	Function set extra operand value
*/	void set_extra_value(Line* line, char* value);
/*
	Function get extra operand value
*/	char* get_extra_value(Line* line);
/*
	Function set type extra operand
*/	void set_extra_type(Line* line, Operand_type type);
/*
	Function set type derictiv 
*/	void set_line_directive(Line* line, Derectiv_type directive);
/*
	Function get derectiv of line type
*/	Derectiv_type get_line_directive(Line* line);
/*
	Function set  data operand
*/	void set_line_in_data(Line* line, char* in_data);

/*	Function for get operand data
*/	char* get_line_in_data(Line* line);

/*	Function for set number line
*/
	void set_number_line(Line *line, int number);
/*	Function for get number line 
*/	int get_number_line(Line *line);

/*	Function for get count data
*/	int get_line_count_data(Line* line) ;

/*	Function for set count data
*/	void set_line_count_data(Line* line, int count_data);

/*	Function for set IC
*/	void set_line_IC(Line* line, int ic);

/*	Function for get IC
*/	int get_line_IC(Line* line);

/*	Function for set DC
*/	void set_line_DC(Line* line, int dc);

/* 	Function for get DC 
*/	int get_line_DC(Line* line);

/*	Function for get adrees in tables
*/	int get_line_address(Line *line);

/*	Function Set line address	
*/	void set_line_address(Line *line, int address);


/*===================================================================================================================================================================*/
#endif

