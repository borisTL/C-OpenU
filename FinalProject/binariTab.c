#include"assambler.h"
/*===================================================================================================================================================================*/
typedef struct
{
    unsigned int on : 1;
} Bit;
/*===================================================================================================================================================================*/
struct BinaryWord{
    
    BinalriLineType type;
    Bit digit[SIZE_WORD];
};
/*===================================================================================================================================================================*/
 struct BinaryTable{
	
    BinaryWord* words[RAM];
	  int size;
	 
} ;
/*===================================================================================================================================================================*/
int get_binary_table_size(BinaryTable* table)
{return table->size;}
/*===================================================================================================================================================================*/
void set_binary_table_size(BinaryTable* table, int size) 
{table->size = size;}
/*====================================================================================================================================================================*/
void firstword_to_binary_word(char* str, BinaryTable* tabl_memori)
{
	
   BinaryWord* binary_word = malloc(sizeof(BinaryWord));

    for (int i = 0; i < SIZE_WORD; i++)
    {
        if (str[i] == '1') 
            binary_word->digit[i].on = 1;
        else 
            binary_word->digit[i].on = 0;
    }
    add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);


}
/*====================================================================================================================================================================*/
BinaryTable* create_binary_table()
{
	BinaryTable* table = malloc(sizeof(BinaryTable));
	table->size=START_ADRESS;
	

    	for (int i = 0; i < RAM; i++) 
        	table->words[i] = NULL;
    	return table;
}
/*====================================================================================================================================================================*/
void add_to_binary_table(BinaryTable* table, BinaryWord* word, BinalriLineType type) 
{
    if (table->size < 0 || table->size > RAM-1)
    {
        printf("Error:Index out of range (binary table)\n");
        return;
    }
    if (table->words[table->size] != NULL)
    {
        printf("Error:Index already occupied (binary table)\n");
        return;
    }
    
    BinaryWord* new_word = malloc(sizeof(BinaryWord));
    if (new_word == NULL) {
        printf("Error: Memory allocation failed (binary word)\n");
        return;
    }
    
    memcpy(new_word, word, sizeof(BinaryWord));
    new_word->type = type;
    table->words[table->size] = new_word;
    table->size++;
}
/*====================================================================================================================================================================*/
void delete_from_binary_table(BinaryTable* table, int index)
{
    if (index < 0 || index > RAM-1) 
    {
        printf("Error:Index out of range (binary table\n");
        return;
    }

    if (table->words[index] == NULL) {
        printf("Error:Index is already empty (binary table)\n");
        return;
    }

    free(table->words[index]);
    table->words[index] = NULL;
}
/*====================================================================================================================================================================*/
void print_binary_table(BinaryTable* table) 
{
    printf("Binary table:\n");

   
    for (int i = 0; i < table->size; i++)
    {
        if (table->words[i] != NULL && table->words[i]->type == instrction)
	{
            printf("[%d] ", i);
            for (int j = 0; j < SIZE_WORD; j++)
	    {
                printf("%d", table->words[i]->digit[j].on);
            }
            printf("\n");
        }
    }

    
    for (int i = 0; i < table->size; i++)
    {
        if (table->words[i] != NULL && table->words[i]->type == derectiv)
        {
            printf("[%d] ", i);
            for (int j = 0; j < SIZE_WORD; j++)
	    {
                printf("%d", table->words[i]->digit[j].on);
            }
            printf("\n");
        }
    }
}
/*===================================================================================================================================================================*/
void reset_binary_table(BinaryTable* table)
{
    for (int i = 0; i < RAM; i++)
    {
        if (table->words[i] != NULL) 
             table->words[i] = NULL;
        
    }
}

/*====================================================================================================================================================================*/
void free_binary_word(BinaryWord** word_ptr) {
    if (word_ptr == NULL || *word_ptr == NULL) {
        return;
    }
    free(*word_ptr);
    *word_ptr = NULL;
}
/*====================================================================================================================================================================*/
void free_binary_table(BinaryTable* table) {
    for (int i = 0; i < RAM; i++) {
        if (table->words[i] != NULL) {
            free_binary_word(&table->words[i]);
        }
    }
    free(table);
}

/*====================================================================================================================================================================*/
BinaryWord char_to_binary_word(char c)
{
    BinaryWord binary_word = {0};
    for (int i = 0; i < 7; i++)
    {
        if (c & (1 << i))
            binary_word.digit[13-i].on = 1;
        else
            binary_word.digit[13-i].on = 0;
    }
    return binary_word;
}
/*====================================================================================================================================================================*/
void string_to_binary_words(char* str,BinaryTable* tabl_memori,Line *line) 
{
    int len = strlen(str);
    BinaryWord* binary_words = malloc((len + 1) * sizeof(BinaryWord));
    int j = len - 1;

    for (int i = 0; i < len; i++)
    {
        BinaryWord* new_word = malloc(sizeof(BinaryWord));
        *new_word = char_to_binary_word(str[i]);
        binary_words[j] = *new_word;
        add_to_binary_table(tabl_memori, new_word, derectiv);
        j--;
	free(new_word);
    }
    binary_words[len] = (BinaryWord) {0};
    add_to_binary_table(tabl_memori, &binary_words[len],derectiv);
    free(binary_words);
	
}
/*====================================================================================================================================================================*/void data_to_binary_words(char* str, BinaryTable* tabl_memori, Line* line) 
 {
    char* token = strtok(str, ",");
    while (token != NULL) {
        BinaryWord* word = malloc(sizeof(BinaryWord));
        int num;
        int is_negative = 0;
        if (token[0] == '-') {
            is_negative = 1;
            num = atoi(token + 1);
        } else {
            num = atoi(token);
        }
        for (int i = 0; i < SIZE_WORD; i++) {
            word->digit[SIZE_WORD - 1 - i].on = (num >> i) & 1;
        }
        if (is_negative) {
            int carry = 1;
            for (int i = 0; i < SIZE_WORD; i++) {
                word->digit[SIZE_WORD - 1 - i].on = (word->digit[SIZE_WORD - 1 - i].on ^ 1);
                if (carry) {
                    word->digit[SIZE_WORD - 1 - i].on = (word->digit[SIZE_WORD - 1 - i].on + 1) & 1;
                    if (word->digit[SIZE_WORD - 1 - i].on == 1) {
                        carry = 0;
                    }
                }
            }
        }
        add_to_binary_table(tabl_memori, word, data);
	free(word);
        token = strtok(NULL, ",");
    }

}
/*====================================================================================================================================================================*/
void register_sourse_to_binary_table(char* reg_str, BinaryTable* tabl_memori)
{
	BinaryWord* binary_word = malloc(sizeof(BinaryWord));
	int reg_num;
	reg_num = atoi(reg_str + 1);
        for (int i = 5; i >= 0; i--)
	{

            binary_word->digit[i].on = (reg_num & 1);
            reg_num >>= 1;
        }
	for(int i=6;i<14;i++)
	binary_word->digit[i].on=0;
	

   	add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);
}
/*====================================================================================================================================================================*/
void register_def_to_binary_table(char* reg_str, BinaryTable* tabl_memori)
{
	BinaryWord* binary_word = malloc(sizeof(BinaryWord));
	int reg_num;
	reg_num = atoi(reg_str + 1);
        for (int i = 11; i >= 6; i--)
	{
            binary_word->digit[i].on = (reg_num & 1);
            reg_num >>= 1;
        }
	for(int i=5;i>=0;i--)
	 binary_word->digit[i].on=0;

	binary_word->digit[12].on=0;
	binary_word->digit[13].on=0;

   	add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);
}
/*====================================================================================================================================================================*/
void immediate_to_binary_word(char* str, BinaryTable* tabl_memori)
{
    BinaryWord* binary_word = malloc(sizeof(BinaryWord));
    int num;
    int is_negative = 0;

	if (str[0] == '-')
	{
	        is_negative = 1;
	        num = atoi(str + 1);
	} 
	else 
	        num = atoi(str + 1);

	for (int i = 0; i < 12; i++)
	{
	        binary_word->digit[11 - i].on = (num & 1);
	        num >>= 1;
	}

	if (is_negative)
	{
       		int carry = 1;
		for (int i = 0; i < 12; i++)
		{
			binary_word->digit[11 - i].on = (binary_word->digit[11 - i].on ^ 1);
			if(carry)
			{
				binary_word->digit[11 - i].on = (binary_word->digit[11 - i].on + 1) & 1;
                		if (binary_word->digit[11 - i].on == 1)
					carry = 0;
                
        		}
      		}
    	}
	binary_word->digit[12].on=0;
	binary_word->digit[13].on=0;
	add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);
}
/*====================================================================================================================================================================*/
void two_register_to_binary_table(char* reg_str1, char* reg_str2, BinaryTable* tabl_memori)
{
    BinaryWord* binary_word = malloc(sizeof(BinaryWord));
    int reg_num1, reg_num2;
	if (reg_str1[0] == 'r') 
	{
	        reg_num1 = atoi(reg_str1 + 1);
	        for (int i = 5; i >= 0; i--)
		{
            		binary_word->digit[i].on = (reg_num1 & 1);
            		reg_num1 >>= 1;
        	}
    	}
	if (reg_str2[0] == 'r')
	{
	        reg_num2 = atoi(reg_str2 + 1);
	        for (int i = 11; i >= 6; i--)
		{
            		binary_word->digit[i].on = (reg_num2 & 1);
            		reg_num2 >>= 1;
        	}
        }
	binary_word->digit[12].on=0;
	binary_word->digit[13].on=0;
	
	add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);
}
/*====================================================================================================================================================================*/
void number_to_binary_table(int num, BinaryTable* tabl_memori)
{
    BinaryWord* binary_word = malloc(sizeof(BinaryWord));
    for (int i = 11; i >= 0; i--)
    {
        binary_word->digit[i].on = (num & 1);
        num >>= 1;
	}
    
    binary_word->digit[13].on = 0;
    binary_word->digit[12].on = 1;
       
    
    add_to_binary_table(tabl_memori, binary_word,instrction);
	free(binary_word);
}
/*====================================================================================================================================================================*/
void extern_to_binary_table( BinaryTable* table_memory)
{
    BinaryWord* binary_word = malloc(sizeof(BinaryWord));
    for(int i=0;i<13;i++)
	binary_word->digit[i].on = 0;
 
    binary_word->digit[13].on = 1; 
    add_to_binary_table(table_memory, binary_word,instrction);
    free(binary_word);
}
/*====================================================================================================================================================================*/
void write_convertBinary_table_to_file(BinaryTable *table, char *filename)
{
char *new_filename = add_ext_to_filename(filename, ".ob");
FILE *file = fopen(new_filename, "w");
if (file == NULL)
{
    printf("Error open %s.\n", new_filename);
    free(new_filename);
    return;
}

int num_instr = 0, num_data = 0;
for (int i = START_ADRESS; i < RAM && i < table->size; i++)
{
    if (table->words[i] != NULL)
    {
        if (table->words[i]->type == instrction)
        {
            ++num_instr;
        }
        else if (table->words[i]->type == derectiv)
        {
            ++num_data;
        }
    }
}

fprintf(file, "    %d %d\n", num_instr, num_data);
int adress=START_ADRESS;

for (int i = START_ADRESS; i < RAM && i < table->size; i++)
{
    if (table->words[i] != NULL && table->words[i]->type == instrction)
    {
        fprintf(file, "%04d	 ", adress);
	adress++;

        for (int j = 0; j < SIZE_WORD; j++)
        {
            if (table->words[i]->digit[j].on == 1)
            {
                fprintf(file, "/");
            }
            else
            {
                fprintf(file, ".");
            }
        }

        fprintf(file, "\n");
    }
}


for (int i = START_ADRESS; i < RAM && i < table->size; i++)
{
    if (table->words[i] != NULL && table->words[i]->type == derectiv)
    {
        fprintf(file, "%04d	 ", adress);
	adress++;
        for (int j = 0; j < SIZE_WORD; j++)
        {
            if (table->words[i]->digit[j].on == 1)
            {
                fprintf(file, "/");
            }
            else
            {
                fprintf(file, ".");
            }
        }

        fprintf(file, "\n");
    }
}

fclose(file);
free(new_filename);
}
/*====================================================================================================================================================================*/
