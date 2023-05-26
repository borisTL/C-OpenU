#include "assambler.h"
/*===================================================================================================================================================================*/
typedef struct operand{
Operand_type type;
    char *value;
} Operand;
/*===================================================================================================================================================================*/
typedef struct label{
    Label_type type;
    char *value;
} Label;
/*===================================================================================================================================================================*/
struct line_t{
  LineType type;
  Derectiv_type directive;
  Instruction_type instruction;
  Operand operand1;     
  Operand operand2; 
  Operand extra;
  Count_Type_instruction count_operand;
  Label label; 
  Boolean error;     
  int quotes;
  int comma;
  char *in_data;
  int count_data;
  char *clon;
  int address;
  int IC;
  int DC;
  int number_line;
  int empity_entry;
  int empity_extern;
};
/*===================================================================================================================================================================*/
void set_error(Line* line, Boolean error)
{line->error = error;}
/*===================================================================================================================================================================*/
Boolean get_error(Line* line)
{return line->error;}
/*===================================================================================================================================================================*/
void set_line_comma_count(Line *line, int comma)
{line->comma = comma;}
/*===================================================================================================================================================================*/
int get_line_comma_count(Line *line)
{return line->comma;}
/*===================================================================================================================================================================*/
void set_line_quotes_count(Line* line, int value)
{line->quotes = value;}
/*===================================================================================================================================================================*/
int get_line_quotes_count(Line* line)
{return line->quotes;}
/*===================================================================================================================================================================*/
void set_clon(Line* line, char* clon) {
    if (line != NULL && clon != NULL) {
        if (line->clon != NULL) {
            free(line->clon);
            line->clon = NULL;
        }
        line->clon = malloc(strlen(clon) + 1);
        if (line->clon != NULL) {
            strcpy(line->clon, clon);
        } else {
            printf("Error: Memory allocation failed (set_clon)\n");
        }
    }
}
/*====================================================================================================================================================================*/
char* get_clon(Line* line)
{
  if (line != NULL) 
  {
    return line->clon;
  }
  return NULL;
}
/*===================================================================================================================================================================*/
void set_line_type(Line *line, LineType type)
{line->type = type;}
/*===================================================================================================================================================================*/
LineType get_line_type(Line *line)
{return line->type;}
/*===================================================================================================================================================================*/
void set_label_type(Line* line, Label_type type)
{line->label.type = type;}
/*===================================================================================================================================================================*/Label_type get_label_type(Line* line)
{return line->label.type;}
/*===================================================================================================================================================================*/
void set_label_value(Line* line, char* value)
{line->label.value = value;}
/*===================================================================================================================================================================*/char* get_label_value(Line* line)
{return line->label.value;}
/*===================================================================================================================================================================*/
void set_line_instruction(Line* line, Instruction_type instruction)
{line->instruction = instruction;}
/*===================================================================================================================================================================*/
Instruction_type get_line_instruction(Line* line)
{return line->instruction;}
/*===================================================================================================================================================================*/
void set_line_count_operand(Line* line, Count_Type_instruction count_operand)
{line->count_operand = count_operand;}
/*===================================================================================================================================================================*/
Count_Type_instruction get_line_count_operand(Line* line)
{return line->count_operand;}
/*===================================================================================================================================================================*/
void set_operand1_type(Line* line, Operand_type type)
{line->operand1.type = type;}
/*===================================================================================================================================================================*/
Operand_type get_operand1_type(Line* line)
{return line->operand1.type;}
void set_operand1_value(Line* line, char* value)
{line->operand1.value = value;}
/*===================================================================================================================================================================*/
char* get_operand1_value(Line* line)
{return line->operand1.value;}
/*===================================================================================================================================================================*/
void set_operand2_type(Line* line, Operand_type type)
{line->operand2.type = type;}
/*===================================================================================================================================================================*/
Operand_type get_operand2_type(Line* line)
{return line->operand2.type;}
/*===================================================================================================================================================================*/
void set_operand2_value(Line* line, char* value) 
{line->operand2.value = value;}
/*===================================================================================================================================================================*/
char* get_operand2_value(Line* line) 
{return line->operand2.value;}
/*===================================================================================================================================================================*/
void set_extra_type(Line* line, Operand_type type)
{line->extra.type = type;}
/*===================================================================================================================================================================*/
void set_line_directive(Line* line, Derectiv_type directive)
{line->directive = directive;}
/*===================================================================================================================================================================*/
Derectiv_type get_line_directive(Line* line) 
{return line->directive;}
/*===================================================================================================================================================================*/
void set_line_in_data(Line* line, char* in_data) 
{line->in_data = in_data;}
/*===================================================================================================================================================================*/
char* get_line_in_data(Line* line)
{return line->in_data;}
/*===================================================================================================================================================================*/
void set_number_line(Line *line, int number)
{line->number_line = number;}
/*===================================================================================================================================================================*/
int get_number_line(Line *line) 
{return line->number_line;}
/*===================================================================================================================================================================*/
Operand_type get_extra_type(Line* line)
{return line->extra.type;}
/*===================================================================================================================================================================*/
void set_extra_value(Line* line, char* value)
{line->extra.value = value;}
/*===================================================================================================================================================================*/
char* get_extra_value(Line* line) 
{return line->extra.value;}
/*===================================================================================================================================================================*/
int get_line_count_data(Line* line)
{return line->count_data;}
/*===================================================================================================================================================================*/
void set_line_count_data(Line* line, int count_data) 
{line->count_data = count_data;}
/*===================================================================================================================================================================*/
void set_line_IC(Line* line, int ic)
{line->IC = ic;}
/*===================================================================================================================================================================*/
int get_line_IC(Line* line)
{return line->IC;}
/*===================================================================================================================================================================*/
void set_line_DC(Line* line, int dc)
{line->DC = dc;}
/*===================================================================================================================================================================*/
int get_line_DC(Line* line)
{return line->DC;}
/*===================================================================================================================================================================*/
int get_line_address(Line *line)
{return line->address;}
/*===================================================================================================================================================================*/
void set_line_address(Line *line, int address)
{line->address = address;}
/*===================================================================================================================================================================*/
void set_empity_entry(Line *line,int no_empity)
{line->empity_entry=no_empity;}
/*===================================================================================================================================================================*/
int get_empity_entry(Line *line)
{return line->empity_entry;}
/*===================================================================================================================================================================*/
void updet_IC(Line *line)
{
	if(line->count_operand==two_operand)
	{
		if(get_operand1_type(line)==REGISTER && line->operand2.type==REGISTER)
			line->IC=+ COUNT_OP2;
		else 
			line->IC=+ COUNT_OP3;
	}
	else if(line->count_operand==one_operand)
		line->IC=+ COUNT_OP2;
	else if(line->count_operand==no_operand)
		line->IC=+ COUNT_OP1;
	else if(line->count_operand==jump_operand)
		line->IC=+ COUNT_OP2;
	else if(line->count_operand==big_jamp)
	{
		if(line->operand2.type==REGISTER && line->extra.type==REGISTER)
			line->IC=+ COUNT_OP3;
		else 
			line->IC=+ COUNT_OP4;
	}
	
}
/*===================================================================================================================================================================*/
Line* create_empty_line() {
    Line* line = (Line*) malloc(sizeof(Line));
    
    line->type = EMPTY_LINE;
    line->directive = no_derectiv;
    line->instruction = no_instruction;
    line->operand1.type = INVALID;
    
    line->operand1.value = NULL;
    line->operand2.type = INVALID;
   
    line->operand2.value = NULL;
    line->extra.type = INVALID;
   
    line->extra.value = NULL;
    line->count_operand = invalid_count;
    line->label.type = NO_TYPE;
    line->label.value =NULL;

    line->error = FALSE;

    line->quotes = 0;
    line->comma = 0;
    line->in_data = NULL;
    line->count_data = 0;
    line->clon = NULL;
    line->address = 100;
    line->IC = 0;
    line->DC = 0;
    line->number_line = 0;
    line->empity_entry=0;
    line->empity_extern=0;
    

    return line;
}

/*====================================================================================================================================================================*/
void free_line(Line* line) {
    if (line == NULL) {
        return;
    }
  
    free(line->operand1.value);
   
    free(line->operand2.value);
   
    free(line->extra.value);
    
    free(line->label.value);
  
    free(line->in_data);
    
    free(line->clon);
   
    free(line);
}

/*====================================================================================================================================================================*/
void restLine(Line *parsed_line)
{	
	
        parsed_line->type = START_LINE;
	parsed_line->directive=no_derectiv;
	parsed_line->instruction = no_instruction;
	parsed_line->count_operand=invalid_count;

	parsed_line->label.value = NULL;
	parsed_line->label.type=NO_TYPE;
	
	if(parsed_line->operand1.value!=NULL)
	parsed_line->operand1.value = NULL;
	parsed_line->operand2.value = NULL;
	parsed_line->extra.value = NULL;
	parsed_line->operand1.type = INVALID;
	parsed_line->operand2.type =INVALID;
	parsed_line->extra.type = INVALID;
       
	parsed_line->comma=0;
	parsed_line->quotes=0;
	parsed_line->in_data=NULL;
	parsed_line->count_data=0;
	parsed_line->IC=0;
	parsed_line->DC=0;

	if(parsed_line->clon!=NULL)
	free(parsed_line->clon);

        parsed_line->clon=NULL;
	parsed_line->error=FALSE;
	parsed_line->number_line=parsed_line->number_line+1;
	
}
/*====================================================================================================================================================================*/

