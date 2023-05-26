#include"assambler.h"

/*====================================================================================================================================================================*/
void syntax_analiz(Line *parsed_line, symbol_table_entry **symbol_table, ExternList *extern_list, EntryList *entry_list)
{
    if (get_error(parsed_line) == FALSE)
    {
        if (get_label_value(parsed_line) != NULL)
        {
            if (check_lable(get_label_value(parsed_line)) == TRUE || lookup_symbol(get_label_value(parsed_line), symbol_table) != NULL)
            {
                printf("Line %d. <Error:Iligal name of label>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }

            else if (strlen(get_label_value(parsed_line)) > LEN_NAME)
            {
                printf("Line %d.<Error:To long name of label>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }

            else if (!isalpha(get_label_value(parsed_line)[0]))
            {
                printf("Line %d.<Error:Iligal name if label>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
        }
        if (get_line_type(parsed_line) == INSTRUCTION_LINE && get_error(parsed_line) == FALSE)
        {
            switch (get_line_instruction(parsed_line))
            {
            case mov:
            case cmp:
            case add:
            case sub:
            case lea:

                if (get_operand1_type(parsed_line) == INVALID)
                {
                    printf("Line %d.<Error:Operand=Null.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_operand2_type(parsed_line) == INVALID)
                {
                    printf("Line %d.<Error:Operand=Null.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_line_comma_count(parsed_line) != 1)
                {
                    printf("Line %d.<Error:Iligal count comma.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_extra_value(parsed_line) != NULL)
                {
                    printf("Line %d.<Error:Iligal text.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (comma_between(get_clon(parsed_line), parsed_line) == FALSE)
                {
                    printf("Line %d.<Error: No comma between operands.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (check_operand(get_operand1_value(parsed_line)) == TRUE || check_operand(get_operand2_value(parsed_line)) == TRUE)
                {
                    printf("Line %d.<Error: Iligal name of operand.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (count_scob(get_clon(parsed_line)) != 0)
                {
                    printf("Line %d.<Error: Iligal count of brackest.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                break;

            case nott:
            case clr:
            case inc:
            case dec:
            case red:
            case prn:

                if (get_operand1_type(parsed_line) == INVALID)
                {
                    printf("Line %d.<Error:Operand=Null.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_operand2_type(parsed_line) != INVALID)
                {
                    printf("Line %d.<Error:Extra text.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_line_comma_count(parsed_line) != 0)
                {
                    printf("Line %d.<Error:Iligal comma.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                break;

            case jmp:
            case bne:
            case jsr:

                if (get_line_count_operand(parsed_line) == jump_operand)
                {

                    if (get_operand1_type(parsed_line) == INVALID)
                    {
                        printf("Line %d.<Error:Operand=Null.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }

                    else if (get_operand2_type(parsed_line) != INVALID)
                    {
                        printf("Line %d.<Error:Iligal Text.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }
                }
                else if (get_line_count_operand(parsed_line) == big_jamp)
                {
                    if (get_operand1_type(parsed_line) == INVALID)
                    {
                        printf("Line %d.<Error:Operand=Null>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }

                    else if (get_operand2_type(parsed_line) == INVALID || get_extra_type(parsed_line) == INVALID)
                    {
                        printf("Line %d.<Error:Operand=Null.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }
                    else if (comma_between(get_clon(parsed_line), parsed_line) == FALSE)
                    {
                        printf("Line %d.<Error:No comma between operands.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }
                    else if (get_line_comma_count(parsed_line) > 1)
                    {
                        printf("Line %d.<Error:Iligal text.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }
                    else if (count_scob(get_clon(parsed_line)) != 2)
                    {
                        printf("Line %d:<Error:Iligal count brackets.>\n", get_number_line(parsed_line));
                        set_error(parsed_line, TRUE);
                    }
                }

                break;

            case rts:
            case stop:

                if (get_operand1_type(parsed_line) != INVALID)
                {
                    printf("Line %d:<Error:Iligal operand.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_line_comma_count(parsed_line) != 0)
                {
                    printf("Line %d:<Error:Iligal text.>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                break;

            case no_instruction:
                printf("Line %d <Error: no instruction.>", get_number_line(parsed_line));
                break;
            }
        }
        else if (get_line_type(parsed_line) == DIRECTIVE_LINE && get_error(parsed_line) == FALSE)
        {
            switch (get_line_directive(parsed_line))
            {
            case string:

                if (get_operand1_value(parsed_line) == NULL)
                {
                    printf("Line %d.<Error:No operand string>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }

                else if (get_line_quotes_count(parsed_line) != 2)
                {
                    printf("Line %d.<Error:No qoutes>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                /*else if (check_string_of_abc(get_operand1_value(parsed_line)) == TRUE)
                {
                    printf("Line %d.<Error:Not type string operabd>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }*/
                else if (get_operand2_value(parsed_line) != NULL)
                {
                    printf("%s", get_operand2_value(parsed_line));
                    printf("Line %d.<Error:Iligal text >\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                break;

            case data:

                if (get_line_in_data(parsed_line) == NULL)
                {
                    printf("Line %d.<Error:No data operand>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (check_data_operand(get_line_in_data(parsed_line), parsed_line) != TRUE)
                {
                    printf("Line %d.<Error:Iligal data operand>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                break;

            case entry:
            case extr:

                if (get_operand1_type(parsed_line) == INVALID)
                {
                    printf("Line %d.<Error:No operand>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (!(isalpha(get_operand1_value(parsed_line)[0])))
                {
                    printf("Line %d.<Error:Iligal text in operand>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_line_quotes_count(parsed_line) != 0)
                {
                    printf("Line %d.<Error:Iligal text>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_operand2_type(parsed_line) != INVALID)
                {
                    printf("Line %d.<Error:Iligal text>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
		else if(find_entry_node(get_entry_list_head(entry_list),get_operand1_value(parsed_line))!=NULL ||
			find_extern_node(get_extern_list_head(extern_list),get_operand1_value(parsed_line))!=NULL )
		{
			 printf("Line %d.<Error:Multipe entry/extern  opeand declaration>\n", get_number_line(parsed_line));
			  set_error(parsed_line, TRUE);
		}
                break;

            case no_derectiv:
                printf("Line %d.<Error:Unknow error no_derectiv>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
                break;
            }
        }
        else if (get_line_type(parsed_line) == EMPTY_LINE)
            return;
        else if (get_line_type(parsed_line) == COMMENT_LINE)
            return;

        else if (get_line_type(parsed_line) == START_LINE && get_error(parsed_line) == FALSE)
        {
            printf("Line %d.<Error: Unknow error type.>\n", get_number_line(parsed_line));
            set_error(parsed_line, TRUE);
        }
    }
}
/*===================================================================================================================================================================*/
void analiz_operand(Line *parsed_line, JampList *jump_list, symbol_table_entry **symbol_table)
{

    if (get_line_type(parsed_line) == INSTRUCTION_LINE)
    {
        switch (get_line_instruction(parsed_line))
        {
        case mov:
        case add:
        case sub:
            if (find_jamp_node(get_jamp_list_head(jump_list), get_operand1_value(parsed_line)) != NULL ||
                find_jamp_node(get_jamp_list_head(jump_list), get_operand2_value(parsed_line)) != NULL ||
                get_operand2_type(parsed_line) == NUMBER)
            {
                printf("Line %d.<Error:Iligal addres mathod for: mov/add/sub>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            else if (get_operand1_type(parsed_line) == NOT_DEFINED || get_operand2_type(parsed_line) == NOT_DEFINED)
            {
                printf("Line %d.<Error:not defined operand: mov/add/sub>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }

            break;
        case cmp:

            if (find_jamp_node(get_jamp_list_head(jump_list), get_operand1_value(parsed_line)) != NULL || find_jamp_node(get_jamp_list_head(jump_list), 													   get_operand2_value(parsed_line)) != NULL)
            {
                printf("Line %d.<Error:Iligal addres mathod for: cmp>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            else if (get_operand1_type(parsed_line) == NOT_DEFINED || get_operand2_type(parsed_line) == NOT_DEFINED)
            {
                printf("Line %d.<Error:not defined operand: cmp>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            break;
        case lea:

            if ((get_operand1_type(parsed_line) != DATA && get_operand1_type(parsed_line) != COD) || find_jamp_node(get_jamp_list_head(jump_list), get_operand2_value(parsed_line)) != NULL || get_operand1_type(parsed_line) == NUMBER  )
            {
                printf("Line %d.<Error:Iligal addres mathod for: lea>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            else if (get_operand1_type(parsed_line) == NOT_DEFINED || get_operand2_type(parsed_line) == NOT_DEFINED)
            {
                printf("Line %d.<Error:not defined operand: lea>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            break;

        case nott:
        case clr:
        case inc:
        case dec:
        case red:

            if (get_operand1_type(parsed_line) == NUMBER || find_jamp_node(get_jamp_list_head(jump_list), get_operand1_value(parsed_line)) != NULL || get_operand2_type(parsed_line) != INVALID)
            {
                printf("Line %d.<Error:Iligal addres mathod for:not/crl/inc/dec/red>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            else if (get_operand1_type(parsed_line) == NOT_DEFINED)
            {
                printf("Line %d.<Error:not defined operand: not/crl/inc/dec/red>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            break;
        case prn:

            if (find_jamp_node(get_jamp_list_head(jump_list), get_operand1_value(parsed_line)) != NULL || get_operand2_type(parsed_line) != INVALID)
            {
                printf("Line %d.<Error:Iligal addres mathod for:prn>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            else if (get_operand1_type(parsed_line) == NOT_DEFINED)
            {
                printf("Line %d.<Error:not defined operand: prn>\n", get_number_line(parsed_line));
                set_error(parsed_line, TRUE);
            }
            break;

        case jmp:
        case bne:
        case jsr:

            if (get_line_count_operand(parsed_line) == jump_operand)
            {
                if (get_operand1_type(parsed_line) == NUMBER)
                {
                    printf("Line %d.<Error:Iligal addres mathod for:jmp/bne/jsr>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
                else if (get_operand1_type(parsed_line) == NOT_DEFINED)
                {
                    printf("Line %d.<Error:not defined operand:jmp/bne/jsr>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
            }
            else if (get_line_count_operand(parsed_line) == big_jamp)
            {
                if (get_extra_type(parsed_line) == NOT_DEFINED || get_operand2_type(parsed_line) == NOT_DEFINED)
                {
                    printf("Line %d.<Error:not defined operand: jmp/bne/jsr>\n", get_number_line(parsed_line));
                    set_error(parsed_line, TRUE);
                }
            }
            break;
        case stop:
        case rts:
            break;
        case no_instruction:
            break;
        }
    }
    else if (get_line_type(parsed_line) == DIRECTIVE_LINE)
    {
        if (has_no_external_symbol(symbol_table) == FALSE)
            printf("Line %d.<Error:Extern name in table symbol .>\n", get_number_line(parsed_line));
    }
if(get_line_directive(parsed_line)!=entry)
{
    if ((get_operand1_type(parsed_line) == ENT && lookup_symbol(get_operand1_value(parsed_line), symbol_table) == NULL) ||
        (get_operand2_type(parsed_line) == ENT && lookup_symbol(get_operand2_value(parsed_line), symbol_table) == NULL) ||
        (get_extra_type(parsed_line) == ENT && lookup_symbol(get_extra_value(parsed_line), symbol_table) == NULL))
    {
	set_error(parsed_line, TRUE);
        printf("Line %d.<Warring: Not defined entry adress>\n", get_number_line(parsed_line));
    }
}
}
/*===================================================================================================================================================================*/
int count_comma(char *line)
{
    int count = 0;
    while (*line != '\0')
    {
        if (*line == ',')
            count++;
        line++;
    }
    return count;
}
/*===================================================================================================================================================================*/
int count_quotes(char *line)
{
    int count = 0;
    while (*line != '\0')
    {
        if (*line == '"')
            count++;
        line++;
    }
    return count;
}
/*===================================================================================================================================================================*/
int count_scob(char *line)
{
    int count1 = 0;
    int count2 = 0;
    int count = 0;
    while (*line != '\0')
    {
        if (*line == '(')
            count1++;
        if (*line == ')')
            count2++;
        line++;
    }
    count = count1 + count2;
    return count;
}
/*===================================================================================================================================================================*/
Boolean check_string_of_abc(char *string)
{

    if (strpbrk(string, "01234/56789!@#$%^&*()_+~?><.:;{}]|["))
        return TRUE;

    return FALSE;
}
/*===================================================================================================================================================================*/
Boolean check_data_operand(char *data_str, Line *parsed_line)
{
    int num_count = 0;
    int comma_count = 0;
    char *current_char = data_str;
    char *next_char = data_str + 1;
    char *end_char = data_str + strlen(data_str) - 1;

    if (*current_char == ',' || *end_char == ',')
    {
        printf("Line %d.<Error:Iligal comma>\n", get_number_line(parsed_line));
        return 0;
    }

    while (*current_char)
    {
        if (*current_char == ',')
        {
            comma_count++;

            if (*next_char == ',')
            {
                printf(" %d Error: consecutive commas in data string\n", get_number_line(parsed_line));
                return FALSE;
            }
        }
        else if (*current_char == '+' || *current_char == '-')
        {
            if (*next_char == '+' || *next_char == '-')
            {
                printf("Error: consecutive signs in data string\n");
                return FALSE;
            }
        }
        else if (!isdigit(*current_char))
        {
            printf("Error: invalid character in data string\n");
            return FALSE;
        }
        else
        {
            while (isdigit(*next_char))
            {
                next_char++;
                current_char++;
            }
            num_count++;
        }
        current_char++;
        next_char++;
        while (isspace(*current_char))
        {
            current_char++;
            next_char++;
        }
    }
    if (num_count != comma_count + 1)
    {
        printf("Error: incorrect number of commas or numbers in data string\n");
        return FALSE;
    }
    set_line_count_data(parsed_line, num_count);
    return TRUE;
}
/*====================================================================================================================================================================*/
int count_elements_indata(char *str)
{
    int count = 0;
    int num_start = 0;
    int num_len = 0;

    while (*str != '\0')
    {
        if (*str == ',' || *str == '\n')
        {
            if (num_len > 0)
            {
                count++;
                num_len = 0;
            }
        }
        else if (*str == '+' || *str == '-')
        {
            if (num_len > 0)
            {
                return -1;
            }
            num_start++;
        }
        else if (isdigit(*str))
        {
            if (num_len == 0)
            {
                num_start = str - str;
            }
            num_len++;
        }
        else
        {
            return -1;
        }
        str++;
    }

    if (num_len > 0)
    {
        count++;
    }

    return count;
}

/*====================================================================================================================================================================*/

Boolean comma_between(char *str, Line *parsed_line)
{
    char *r1_pos;
    char *r2_pos;

    if (get_line_count_operand(parsed_line) == big_jamp)
    {
        r1_pos = strstr_word(str, get_operand2_value(parsed_line));
        r2_pos = strstr_word(str, get_extra_value(parsed_line));
    }
    else
    {
        r1_pos = strstr_word(str, get_operand1_value(parsed_line));
        r2_pos = strstr_word(str, get_operand2_value(parsed_line));
    }

    char *comma_pos = strstr(str, ",");

    if (r1_pos != NULL && r2_pos != NULL && comma_pos != NULL)
    {
        if (comma_pos > r1_pos && comma_pos < r2_pos)
            return TRUE;
    }
    return FALSE;
}
/*====================================================================================================================================================================*/
char *strstr_word(const char *str1, const char *str2)
{
    size_t str1_len = strlen(str1);
    size_t str2_len = strlen(str2);
    size_t start = 0;
    while (start + str2_len <= str1_len)
    {
        size_t end = start + str2_len;
        size_t match_len = strspn(str1 + start, str2);
        if (match_len == str2_len)
        {
            if ((start == 0 || isspace(str1[start - 1]) || ispunct(str1[start - 1])) &&
                (end == str1_len || isspace(str1[end]) || ispunct(str1[end])))
            {
                return (char *)(str1 + start);
            }
        }
        start += (match_len > 0) ? match_len : 1;
    }
    return NULL;
}

/*====================================================================================================================================================================*/
Boolean check_lable(char *label)
{
    if (label[strlen(label) - 1] == ':')
        label[strlen(label) - 1] = '\0';

    char *constant_name[] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop", ".string", ".entry", ".data", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r0"};

    for (int i = 0; i < 27; i++)
    {
        if (strncmp(label, constant_name[i], strlen(label)) == 0)
            return TRUE;
    }
    return FALSE;
}
/*====================================================================================================================================================================*/
Boolean check_operand(char *operand)
{
    char *operand_not[] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop", "MAIN", ".string", ".entry", ".data"};

    for (int i = 0; i < 19; i++)
    {
        if (strncmp(operand, operand_not[i], strlen(operand_not[i])) == 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}
/*====================================================================================================================================================================*/
Boolean check_macro_name(char *label)
{
    char *constant_name[] = {"mov", "cmp", "add", "sub", "not", "clr", "lea", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop", ".string", ".entry", ".data", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r0"};

    for (int i = 0; i < 27; i++)
    {
        if (strncmp(label, constant_name[i], strlen(label)) == 0)
            return TRUE;
    }
    return FALSE;
}
/*====================================================================================================================================================================*/
Boolean is_valid_number(const char *str, Line *line)
{
    if (*str != '#')
    {
        printf("Line %d. <Error: Invalid number format.>\n", get_number_line(line));
        set_error(line, TRUE);
        return FALSE;
    }
    str++;
    int sign_count = 0;
    while (*str != '\0')
    {
        if (*str == '+' || *str == '-')
        {
            if (++sign_count > 1)
            {
                printf("Line %d. <Error: Invalid number format.>\n", get_number_line(line));
                set_error(line, TRUE);
                return FALSE;
            }
        }
        else if (!isdigit(*str))
        {
            printf("Line %d. <Error: Invalid number format.>\n", get_number_line(line));
            set_error(line, TRUE);
            return FALSE;
        }
        str++;
    }
    return TRUE;
}
/*====================================================================================================================================================================*/
char* my_strdup(const char* str)
{
    size_t len = strlen(str) + 1; 
    char* new_str = malloc(len);   
    if (new_str == NULL)       
        return NULL;
    memcpy(new_str, str, len);     
    return new_str;
}
/*====================================================================================================================================================================*/
