#include"assambler.h"

/*===================================================================================================================================================================*/
void add_to_mamory_machine_code(Line *line, BinaryTable *tabl_memori, symbol_table_entry **symbol_table, ExternList *extern_list)
{
    if (get_line_type(line) == INSTRUCTION_LINE)
    {

        switch (get_line_instruction(line))
        {
        case mov:
        case cmp:
        case add:
        case sub:
        case lea:

            convert_to_machine_code_first_word(line, tabl_memori);

            if (get_operand1_type(line) == REGISTER && get_operand2_type(line) == REGISTER)

                two_register_to_binary_table(get_operand1_value(line), get_operand2_value(line), tabl_memori);
            else
            {
                if (get_operand1_type(line) == REGISTER)
                    register_sourse_to_binary_table(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == NUMBER)
                    immediate_to_binary_word(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == EXT)
                {

                    extern_to_binary_table(tabl_memori);
                    update_address_in_list_by_name(extern_list, get_operand1_value(line), get_binary_table_size(tabl_memori) - 1);
                }

                else if (get_operand1_type(line) == DATA || get_operand1_type(line) == COD)
                    number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);

                if (get_operand2_type(line) == REGISTER)
                    register_def_to_binary_table(get_operand2_value(line), tabl_memori);

                else if (get_operand2_type(line) == NUMBER)
                    immediate_to_binary_word(get_operand2_value(line), tabl_memori);

                else if (get_operand2_type(line) == EXT)
                {
                    extern_to_binary_table(tabl_memori);
                    update_address_in_list_by_name(extern_list, get_operand2_value(line), get_binary_table_size(tabl_memori) - 1);
                }

                else if (get_operand2_type(line) == DATA || get_operand2_type(line) == COD)
                    number_to_binary_table((get_address_by_name(get_operand2_value(line), symbol_table)), tabl_memori);
            }

            break;

        case nott:
        case clr:
        case inc:
        case dec:
        case red:
        case prn:

            convert_to_machine_code_first_word(line, tabl_memori);

            if (get_operand1_type(line) == REGISTER)
                register_sourse_to_binary_table(get_operand1_value(line), tabl_memori);

            else if (get_operand1_type(line) == NUMBER)
                immediate_to_binary_word(get_operand1_value(line), tabl_memori);

            else if (get_operand1_type(line) == EXT)
            {
                extern_to_binary_table(tabl_memori);
                update_address_in_list_by_name(extern_list, get_operand1_value(line), get_binary_table_size(tabl_memori) - 1);
            }
            else if (get_operand1_type(line) == ENT)
            {
                number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);
            }

            else if (get_operand1_type(line) == DATA || get_operand1_type(line) == COD)
                number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);
            break;

        case jmp:
        case bne:
        case jsr:

            convert_to_machine_code_first_word(line, tabl_memori);

            if (get_line_count_operand(line) == jump_operand)
            {
                if (get_operand1_type(line) == REGISTER)
                    register_sourse_to_binary_table(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == NUMBER)
                    immediate_to_binary_word(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == EXT)
                {
                    extern_to_binary_table(tabl_memori);
                    update_address_in_list_by_name(extern_list, get_operand1_value(line), get_binary_table_size(tabl_memori) - 1);
                }

                else if (get_operand1_type(line) == ENT)
                    number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);

                else if (get_operand1_type(line) == DATA || get_operand1_type(line) == COD)
                    number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);
            }
            else if (get_line_count_operand(line) == big_jamp)

            {

                if (get_operand1_type(line) == REGISTER)
                    register_sourse_to_binary_table(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == NUMBER)
                    immediate_to_binary_word(get_operand1_value(line), tabl_memori);

                else if (get_operand1_type(line) == EXT)
                {
                    extern_to_binary_table(tabl_memori);
                    update_address_in_list_by_name(extern_list, get_operand1_value(line), get_binary_table_size(tabl_memori) - 1);
                }

                else if (get_operand1_type(line) == DATA || get_operand1_type(line) == COD)

                    number_to_binary_table((get_address_by_name(get_operand1_value(line), symbol_table)), tabl_memori);

                if (get_operand2_type(line) == REGISTER && get_extra_type(line) == REGISTER)
                    two_register_to_binary_table(get_operand2_value(line), get_extra_value(line), tabl_memori);
                else
                {
                    if (get_operand2_type(line) == REGISTER)
                        register_sourse_to_binary_table(get_operand2_value(line), tabl_memori);
                    else if (get_operand2_type(line) == NUMBER)
                        immediate_to_binary_word(get_operand2_value(line), tabl_memori);
                    else if (get_operand2_type(line) == EXT)
                    {
                        extern_to_binary_table(tabl_memori);
                        update_address_in_list_by_name(extern_list, get_operand2_value(line), get_binary_table_size(tabl_memori) - 1);
                    }

                    else if (get_operand2_type(line) == DATA || get_operand2_type(line) == COD)
                        number_to_binary_table((get_address_by_name(get_operand2_value(line), symbol_table)), tabl_memori);

                    if (get_extra_type(line) == REGISTER)
                        register_def_to_binary_table(get_extra_value(line), tabl_memori);

                    else if (get_extra_type(line) == NUMBER)
                        immediate_to_binary_word(get_extra_value(line), tabl_memori);

                    else if (get_extra_type(line) == EXT)
                    {
                        extern_to_binary_table(tabl_memori);
                        update_address_in_list_by_name(extern_list, get_extra_value(line), get_binary_table_size(tabl_memori) - 1);
                    }

                    else if (get_extra_type(line) == DATA || get_extra_type(line) == COD)
                        number_to_binary_table((get_address_by_name(get_extra_value(line), symbol_table)), tabl_memori);
                }
            }

            break;

        case rts:
        case stop:
            convert_to_machine_code_first_word(line, tabl_memori);
            break;
        case no_instruction:
            printf("no instruction\n");
            break;
        }
    }

    else if (get_line_type(line) == DIRECTIVE_LINE)
    {

        if (get_line_directive(line) == string)
            string_to_binary_words(get_operand1_value(line), tabl_memori, line);
        else if (get_line_directive(line) == data)
            data_to_binary_words(get_line_in_data(line), tabl_memori, line);
    }
}
/*====================================================================================================================================================================*/
void convert_to_machine_code_first_word(Line *line,BinaryTable* tabl_memori) 
{   
	MachineCode* mc = create_machine_code();

	if(get_line_type(line)==INSTRUCTION_LINE)
	{
   	 

	     if(get_line_instruction(line)==mov)
		set_machine_code_opcode(mc,0);

	else if(get_line_instruction(line)==cmp)
		set_machine_code_opcode(mc,1);

	else if(get_line_instruction(line)==add)
		set_machine_code_opcode(mc,2);

	else if(get_line_instruction(line)==sub)
		set_machine_code_opcode(mc,3);

	else if(get_line_instruction(line)==nott)
		set_machine_code_opcode(mc,4);

	else if(get_line_instruction(line)==clr)
		set_machine_code_opcode(mc,5);

	else if(get_line_instruction(line)==lea)
		set_machine_code_opcode(mc,6);

	else if(get_line_instruction(line)==inc)
		set_machine_code_opcode(mc,7);

	else if(get_line_instruction(line)==dec)
		set_machine_code_opcode(mc,8);

	else if(get_line_instruction(line)==jmp)
		set_machine_code_opcode(mc,9);

	else if(get_line_instruction(line)==bne)
		set_machine_code_opcode(mc,10);

	else if(get_line_instruction(line)==red)
		set_machine_code_opcode(mc,11);

	else if(get_line_instruction(line)==prn)
		set_machine_code_opcode(mc,12);

	else if(get_line_instruction(line)==jsr)
		set_machine_code_opcode(mc,13);

	else if(get_line_instruction(line)==rts)
		set_machine_code_opcode(mc,14);

	else if(get_line_instruction(line)==stop)
		set_machine_code_opcode(mc,15);

	if(get_line_count_operand(line)==jump_operand)
	{
		if(get_operand1_type(line)==COD|| get_operand1_type(line)==DATA || get_operand1_type(line)==EXT )
			set_addr_mode2(mc,ADDRESSIMG_METHOD_1);

		else if(get_operand1_type(line)==REGISTER )
			set_addr_mode2(mc,ADDRESSIMG_METHOD_3);
	}
	else if(get_line_count_operand(line)==big_jamp)
	{
		if(get_operand1_type(line)==COD|| get_operand1_type(line)==DATA || get_operand1_type(line)==EXT )
		set_addr_mode2(mc,ADDRESSIMG_METHOD_2);

		else if(get_operand1_type(line)==REGISTER )
			set_addr_mode2(mc,ADDRESSIMG_METHOD_3);

		if(get_operand2_type(line)==REGISTER )
			set_machine_code_op1(mc,ADDRESSIMG_METHOD_3);

		else if(get_operand2_type(line)==NUMBER)
        		set_machine_code_op1(mc,ADDRESSIMG_METHOD_0);

		else if(get_operand2_type(line)==COD ||get_operand2_type(line)==DATA || get_operand2_type(line)==EXT )
			set_machine_code_op1(mc,ADDRESSIMG_METHOD_1);

		if(get_extra_type(line)==REGISTER )
			set_machine_code_op2(mc,ADDRESSIMG_METHOD_3);

		else if(get_extra_type(line)==NUMBER)
        		set_machine_code_op2(mc,ADDRESSIMG_METHOD_0);

		else if(get_extra_type(line)==COD||get_extra_type(line)==DATA || get_extra_type(line)==EXT )
			set_machine_code_op2(mc,ADDRESSIMG_METHOD_1);
	}
	else
	{    
		if(get_line_count_operand(line)==two_operand)
		{
			if(get_operand1_type(line)==REGISTER )
				set_addr_mode1(mc,ADDRESSIMG_METHOD_3);

			else if(get_operand1_type(line)==NUMBER)
        			set_addr_mode1(mc,ADDRESSIMG_METHOD_0);

			else if(get_operand1_type(line)==COD|| get_operand1_type(line)==DATA || get_operand1_type(line)==EXT )
				set_addr_mode1(mc,ADDRESSIMG_METHOD_1);

			if(get_operand2_type(line)==REGISTER )
				set_addr_mode2(mc,ADDRESSIMG_METHOD_3) ;

			else if(get_operand2_type(line)==NUMBER)
        			set_addr_mode2(mc,ADDRESSIMG_METHOD_0);

			else if(get_operand2_type(line)==COD ||get_operand2_type(line)==DATA || get_operand2_type(line)==EXT)
				set_addr_mode2(mc,ADDRESSIMG_METHOD_1);
		  }
	      else
		{
			if(get_operand1_type(line)==REGISTER )
				set_addr_mode2(mc,ADDRESSIMG_METHOD_3) ;

			else if(get_operand1_type(line)==NUMBER)
        			set_addr_mode2(mc,ADDRESSIMG_METHOD_0);

			else if(get_operand1_type(line)==COD|| get_operand1_type(line)==DATA || get_operand1_type(line)==EXT )
				set_addr_mode2(mc,ADDRESSIMG_METHOD_1);

		}
	
	

		
	}
	set_are(mc,ARE);
	}
	
	char* binary = calloc(SIZE_WORD, sizeof(char));


	fmachine_code_to_binary(mc, binary);

	
	firstword_to_binary_word(binary,tabl_memori);

	free(binary);
	free_machine_code(mc);

}
/*===================================================================================================================================================================*/
