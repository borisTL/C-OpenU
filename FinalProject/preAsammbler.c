#include"assambler.h"
/*====================================================================================================================================================================*/
void perAssambler(FILE *in_file, FILE *out_file, macro_table_entry **macro_table, Line *linem)
{
    char *macro_text = malloc(MAX_LEN * sizeof(char));
    char *macro_name = malloc(LEN_NAME * sizeof(char));
    char *line = (char *)malloc(CHECK_LINE * sizeof(char));
    int in_macro = 0;
    int line_number = 1;

    memset(macro_name, 0, LEN_NAME);
    memset(macro_text, 0, MAX_LEN);

    while (fgets(line, CHECK_LINE, in_file) != NULL && get_error(linem) == FALSE)
    {
        if (strlen(line) > MAX_LEN)
        {
            printf("Line %d:<Error: So big line>\n", line_number);
            set_error(linem, TRUE);
        }

        char *ptr = line;
        while (isspace(*ptr))
            ++ptr;
        if (strncmp(ptr, "mcr", 3) == 0 && !in_macro)
        {
            in_macro = 1;
            ptr = ptr + strlen("mcr");

            while (isspace(*ptr))
                ++ptr;

            sscanf(ptr, "%s", macro_name);
            ptr = ptr + strlen(macro_name);

            while (isspace(*ptr))
                ++ptr;

            if (strlen(macro_name)==0)
            {
                printf("Line %d Error: Macro name is not defined", line_number);
                set_error(linem, TRUE);
            }

            else if (check_macro_name(macro_name) == TRUE)
            {
                printf("Line %d: Error: Illegal Macro Name, Name of Constant", line_number);
                set_error(linem, TRUE);
            }

            else if (macro_table_lookup(macro_name, macro_table) != NULL)
            {
                set_error(linem, TRUE);
                printf("Line %d: Illegal macro name this name is in use\n", line_number);
            }
            else if (*(ptr) != '\0')
            {
                printf("Line %d Error:Text after macro name\n ", line_number);
                set_error(linem, TRUE);
            }
        }
        else if (strncmp(ptr, "endmcr", 6) == 0 && in_macro)
        {
            ptr = ptr + strlen("endmcr");

            while (isspace(*ptr))
                ++ptr;

            if (*ptr != '\0')
            {
                printf("Line %d Error:Text after end macro", line_number);
                set_error(linem, TRUE);
            }

            in_macro = 0;
            macro_text[strlen(macro_text) - 1] = '\0';
            macro_table_insert(macro_name, macro_text, macro_table);
            memset(macro_name, 0, LEN_NAME);
            memset(macro_text, 0, MAX_LEN);
        }
        else if (in_macro)
        {

            strcat(macro_text, ptr);
        }
        line_number++;
    }
    fseek(in_file, 0, SEEK_SET);

    if(get_error(linem)==FALSE)
    	replace_keys_with_values(in_file,out_file,macro_table);

    free(macro_name);
    free(macro_text);
    free(line);
    
    fclose(in_file);
    fclose(out_file);
}
/*====================================================================================================================================================================*/
void replace_keys_with_values(FILE *in_file, FILE *out_file, macro_table_entry **macro_table)
{

    int in_macro = 0;
    char *line = (char *)malloc(MAX_LEN * sizeof(char));
    while (fgets(line, MAX_LEN, in_file) != NULL)
    {
	
        

        char *key_start = line;
	while (isspace(*key_start))
                ++key_start;

        if (strncmp(key_start, "mcr", 3) == 0 && !in_macro)
            in_macro = 1;
        else if (strncmp(key_start, "endmcr", 6) == 0 && in_macro)
            in_macro = 0;

        else
        {

            while (key_start != NULL && *key_start != '\0' && !in_macro)
            {
                char *key_end = strchr(key_start, ' ');
                if (key_end == NULL)
                    key_end = strchr(key_start, '\n');

                int key_len = key_end - key_start;
                char key[key_len + 1];
                strncpy(key, key_start, key_len);
                key[key_len] = '\0';

                char *value = getvalue(macro_table, key);

                if (value != NULL)
                {

                    fwrite(value, strlen(value), 1, out_file);
                    key_start = key_end;
                }
                else
                {
                    fwrite(key_start, 1, 1, out_file);
                    key_start++;
                }
            }
        }
    }
    free(line);
    
}
/*===================================================================================================================================================================*/

