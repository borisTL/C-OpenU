/*	File for function declarations that operation on files
*/

	
	int handleSingel(char *arg);
/*	The function takes a filename and appends the ending .as to it.
	After that, the check of the possibility of opening the file will
	be checked if the file can be opened, it will open the second file
	with the ending am.
	The next step is to create data structures and allocate memory for 
	them, if the creation was successful, the pre-assembler function is 
	launched.
	After the first and second passes are launched, which will be explained
	in their files after the pass if there were no errors depending on the 
	contents of the file, the functions of creating files ext ent ob will be written.
*/

	char *add_ext_to_filename(const char* filename, const char* ext);
/*	Function appends an ending to a file.
*/

