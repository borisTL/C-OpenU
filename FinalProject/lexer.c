#include "assambler.h"

/*====================================================================================================================================================================*/
void parse_line(char *line, Line *parsed_line,symbol_table_entry **symbol_table, ExternList* extern_list,EntryList* entry_list) 
{
	restLine(parsed_line);

	set_line_comma_count(parsed_line,count_comma(line));
	set_line_quotes_count( parsed_line,count_quotes(line));

	set_clon (parsed_line,line);
       

	if (*line == '\0' || *line == ';')
	{
		*line == '\0' ? set_line_type(parsed_line, EMPTY_LINE) : set_line_type(parsed_line, COMMENT_LINE);

		
	}
	else
	{
		
		char *token = strtok(line, " ,\t\n\"");
    		int token_count = 0;
		int check_function_in_line=0;


		while (token != NULL) 
		{
			if(*token==';')
				break;
				
			if (token_count == 0 && token[strlen(token) - 1] == ':')
			{
				token[strlen(token) - 1] ='\0';
				set_label_value(parsed_line,token);
				
			}

			else  if (strcmp(token, "mov")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,mov);
				set_line_count_operand( parsed_line,two_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "cmp")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,cmp);
				set_line_count_operand( parsed_line,two_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "add")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,add);
				set_line_count_operand( parsed_line,two_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "sub")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,sub);
				set_line_count_operand( parsed_line,two_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "lea")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,lea);
				set_line_count_operand( parsed_line,two_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "not")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,nott);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "clr")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,clr);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "inc")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,inc);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "dec")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,dec);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "red")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,red);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "prn")==0 )
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,prn);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "jmp")==0)
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,jmp);
				set_line_count_operand( parsed_line,jump_operand);
				check_function_in_line++;
			}
			else  if (strcmp(token, "bne")==0)
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,bne);	
				set_line_count_operand( parsed_line,jump_operand);
				check_function_in_line++;
			} 
			else  if (strcmp(token, "jsr")==0)
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,jsr);	
				set_line_count_operand( parsed_line,jump_operand);
				check_function_in_line++;
			}
			else  if ( strcmp(token, "rts")== 0)
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,rts);
				set_line_count_operand( parsed_line,no_operand);
				check_function_in_line++;
 			}
			else  if ( strcmp(token, "stop")== 0)
			{
				set_line_type(parsed_line,INSTRUCTION_LINE);
				set_line_instruction(parsed_line,stop);
				set_line_count_operand( parsed_line,no_operand);
				check_function_in_line++;
 			}
			else if ((token_count == 2 && get_label_value(parsed_line)!=NULL) ||
				 (token_count == 1 && get_label_value(parsed_line)==NULL))
			{ 
			       set_operand1_value(parsed_line,token);
			       set_operand1_type(parsed_line,get_operand_type(get_operand1_value(parsed_line),parsed_line,symbol_table,extern_list, entry_list));
				
					
					
			}

			else if ((token_count == 3 && get_label_value(parsed_line)!=NULL) ||
				 (token_count == 2 && get_label_value(parsed_line)==NULL) )
			{
					set_operand2_value(parsed_line,token);
				     set_operand2_type(parsed_line,get_operand_type(get_operand2_value(parsed_line),parsed_line,symbol_table,extern_list, entry_list));
			}
			
			else if ((token_count == 3 &&get_label_value(parsed_line)==NULL) ||
				 (token_count == 4 && get_label_value(parsed_line)!=NULL) )
			{
				set_extra_value(parsed_line,token);
		                set_extra_type(parsed_line,get_operand_type(get_extra_value(parsed_line),parsed_line,symbol_table,extern_list, entry_list));

					if(get_line_instruction(parsed_line)==jmp ||get_line_instruction(parsed_line)==bne ||get_line_instruction(parsed_line)==jsr)
						set_line_count_operand( parsed_line,big_jamp);
			}

			else if(strcmp(token, ".string")==0)
			{
				set_line_type(parsed_line,DIRECTIVE_LINE);
				set_line_directive(parsed_line,string);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;

			}
			else if(strcmp(token, ".extern")==0)
			{
				set_line_type(parsed_line,DIRECTIVE_LINE);
				set_line_directive(parsed_line,extr);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;

			}
			else if(strcmp(token, ".entry")==0)
			{
				set_line_type(parsed_line,DIRECTIVE_LINE);
				set_line_directive(parsed_line,entry);
				set_line_count_operand( parsed_line,one_operand);
				check_function_in_line++;
			}
			else if(strcmp(token, ".data")==0)
 			{
				set_line_type(parsed_line,DIRECTIVE_LINE);
				set_line_count_operand( parsed_line,data_operand);
            			set_line_directive(parsed_line,data);
            			set_line_in_data(parsed_line,strtok(NULL, "\n"));
				check_function_in_line++;
				
				break;
			}
			
			else
			{
			printf("Line %d:Grammar or syntax error\n",get_number_line(parsed_line));
				token_count--;
				set_error(parsed_line, TRUE);
				break;
			}
			 if (check_function_in_line>1)
			{
				printf("Line %d:Error: More than one function or derivative per line\n",get_number_line(parsed_line));
				set_error(parsed_line, TRUE);
				break;
			}
			if(get_line_directive(parsed_line) == string)
				token = strtok(NULL," \"\n");


			else if(get_line_instruction(parsed_line)==jmp ||get_line_instruction(parsed_line)==bne ||get_line_instruction(parsed_line)==jsr)
			token = strtok(NULL, " ,()\t\n");
			else 
			token = strtok(NULL, " ,\t\n");
				
			token_count++;
			
		}
	}
}
/*====================================================================================================================================================================*/
Operand_type get_operand_type(char *operand, Line *line,symbol_table_entry **symbol_table,ExternList* extern_list,EntryList* entry_list)
{ 

	if(operand!=NULL)
	{
    		if (operand[0] == 'r' && (operand[1] >= '0' || operand[1] <= '7'))
			return REGISTER;
		
     
		else if (operand[0]=='#')
		{	
			if(is_valid_number(operand,line)==TRUE)
		 	return NUMBER;
		}
		

		else if(find_extern_node(get_extern_list_head(extern_list),operand)!=NULL )
			return EXT;

		else if (get_typeLabel(operand,symbol_table)==DATTA)
			return DATA;

		else if(get_typeLabel(operand,symbol_table)==CODE)
			return COD;
		else if(find_entry_node(get_entry_list_head(entry_list),operand)!=NULL && lookup_symbol(operand,symbol_table)==NULL)
			return ENT;
		else
			return NOT_DEFINED;

	}
	return INVALID;
}
/*====================================================================================================================================================================*/
