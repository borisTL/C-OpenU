#include "assambler.h"

/*===================================================================================================================================================================*/
void assambler(int argc, char* argv[])
{
	int fileCount = argc - 1;
	int i = 1;
	if(fileCount < 1)
	{
		fprintf(stderr,"\nNot passed any sourse files to assambler.\n");
		exit(1);
	}

	while (--argc != 0)
	{
		printf("Status: file processing started [%s] \n",argv[i]);
	 	handleSingel(argv[i]);
		printf("Status: file processing finish [%s]\n\n",argv[i]);
    		i++;
	}
}
/*===================================================================================================================================================================*/
int handleSingel(char *arg)
{	
	FILE *in_file=NULL,*out_file=NULL; 
	char *file_name=add_ext_to_filename(arg, ".as");
	char* target_filename = add_ext_to_filename(arg, ".am");
	

	
	in_file = fopen(file_name, "r");
  	if (!in_file)
	{
		printf("Error: unable to open file <%s>\n", file_name);
		free(file_name);
		free(target_filename);
    		return 1 ;
  	}
	
	out_file = fopen(target_filename, "w");
  	if (!out_file)
	{
		
		printf("Error: unable to create file <%s>\n", target_filename);

		free(file_name);
		free(target_filename);
    		return 1 ;
  	}
	if(in_file && out_file )
	{
		Line* parsed_line;
		macro_table_entry** macro_table;
		symbol_table_entry** symbol_table;
		ExternList* extern_list;
		JampList* jump_list;
		EntryList* entry_list;
		BinaryTable* tabl_memori;

		initialize_program(&macro_table, &symbol_table, &extern_list, &jump_list, &entry_list, &parsed_line, &tabl_memori);
	
	
		perAssambler(in_file,out_file,macro_table,parsed_line);

		if(get_error(parsed_line)==FALSE)
			first_pass(target_filename,in_file,parsed_line,tabl_memori,symbol_table, extern_list, entry_list, jump_list);
		if(get_error(parsed_line)==FALSE)
			secondRun(target_filename,in_file,parsed_line, tabl_memori,symbol_table, extern_list, entry_list,jump_list);
	
	
	
	
		if(get_entry_list_head(entry_list)!=NULL && get_error(parsed_line)==FALSE)
			write_entries_to_file( entry_list,symbol_table,target_filename);
	
	
		if(get_error(parsed_line)==FALSE)
			write_convertBinary_table_to_file(tabl_memori,target_filename);

		if(get_extern_list_head(extern_list)!=NULL && get_error(parsed_line)==FALSE)
 			process_file( extern_list,target_filename);
	
	
	
		free_resources(macro_table, symbol_table, extern_list, jump_list, entry_list, parsed_line, tabl_memori);
		free(target_filename);
		free(file_name);
    }

    return 0;
}





