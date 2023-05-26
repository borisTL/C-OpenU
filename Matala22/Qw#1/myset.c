#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "set.h"
/**********************************************************************************************************************************************************************/
int parse_input();
int check_comma(char *input);
int iligal_comma(char *input);
/**********************************************************************************************************************************************************************/int main()
{	printf("Hello\n");	
	printf("1. Valid set names only: SETA, SETB, SETC, SETD, SETE, SETF.\n");
	printf("2. Valid opertaions only: read_set, print_set, union_set, ");
	printf("intersect_set, sub_set,symdiff_set.\n");
	printf("3. Valid range of numbers: 0-127 inc.\n");
	printf("4. To perform read_set, input as follows:\n");
	printf("read_set <setname>,<number>,...,<number>,-1 <ENTER>\n");
	printf("Example: read_set SETA, 12, 13 ,14 ,-1\n");
	printf("5. To perform print_set, input as follows:\n");
	printf("print_set <setname><ENTER>\n");
	printf("Example: print_set SETA\n");
	printf("6. To perform union/intersect/sub_set/symdiff_set, input as follows:\n");
	printf("<operation> <setname1>,<setname2>,<setname3><ENTER>\n");
	printf("Example: intersect_set SETB, SETF, SETD\n");
	printf("NOTE: the same set can be used twice or 3 times ");
	printf("in uni/inter/sub operations.\n");
	printf("7. To quit: stop<ENTER>\n");
	
	if (init_sets()==1)
		return 1;
	if (parse_input()==0)
		printf("Error: no 'stop' command at EOF redirection.\n");
	else 
		printf("Program finish\n");
	return 0;
}
/**********************************************************************************************************************************************************************/
int parse_input()
{
	char input[LINE_SIZE];
	char copy_input[LINE_SIZE];
	char *temp,*name_set,*nelment,*name1,*name2,*name3,*temp_copy;
	set *set_1,*set_2,*result;
	int end;
	printf("\n\n~prompt: ");
	while(fgets(input, LINE_SIZE, stdin)!=NULL )
	{
		strcpy(copy_input, input);
			if(input[0]!='\n')
			{	
				temp=input;
				temp_copy=copy_input;
				while (isspace(*temp))
					++temp;
				if(check_comma(temp_copy)==0){
				if (iligal_comma(temp_copy)==0)
				{	

					temp=strtok(input," ,\n");

					if (strcmp(temp,"read_set")==0)
					{	
						name_set=strtok(NULL,",\n");
						if(name_set!=NULL)
						{
							while (isspace(*name_set))
								++name_set;
							set* set_name=set_name=find_set(name_set);
							if(set_name!=NULL)
							{
								nelment= strtok(NULL, ",\n");					 
								if(nelment!=NULL)
								{
									int element=0 ;
									int elements[BIGEST_NUMBER];
									int i = 0;
									while (nelment != NULL)
									{   
									    if (strpbrk(nelment,"./*+!@#$%^&*()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"))
									    {
									    	printf("Invalid set member – not an integer\n");
										break;
									     }else
										element=atoi(nelment);
										if(element>BIGEST_NUMBER || element<END)
										{
											printf("Invalid set member – value out of range\n");
											break;
										}
										elements[i++] = element;
										if(i>=BIGEST_NUMBER)
										{
											printf("Invalid set  –  out of range\n");
											break;
										}
										nelment = strtok(NULL, ",\n");
										
										if(element!=END && nelment==NULL )
										{
											printf("List of set members is not terminated correctly\n");
											break;
										}
										if(nelment!=NULL && element==END)
										{
											printf("Extraneous text after end of command\n");
											break;
										}
										if(element==END && nelment==NULL )
										{
											read_set(set_name,elements);
										}
										
											
									
									}/*while*/
								
							 
							
							}else
							printf("Missing elemnts\n");
						
						}/*setname*/
					
					}else
					printf("Missing set name and elements\n");
				  
				}
	
				else if(strcmp(temp, "print_set")==0)
				{
					while (isspace(*temp))
					++temp;
					
					name_set=strtok(NULL,"\n");
					if(name_set!=NULL)
					{
						while (isspace(*name_set))
						++name_set;
						if(strlen(name_set)==4)
						{
							set*set_name=find_set(name_set);
							if(set_name!=NULL)
							print_set(set_name);
						}
						else 
						printf("Extraneous text after end of command\n");
					
					}else
					printf("Missing set name\n");
			
				}	

				else if(strcmp(temp, "union_set")==0||strcmp(temp, "intersect_set")==0||strcmp(temp, "sub_set")==0||strcmp(temp,"symdiff_set")==0)
				{	
					
					
						name1=strtok(NULL,",\n");
						if(name1!=NULL)
						{	if(strlen(name1)==SIZE_LINE_SET){
							while (isspace(*name1))
								++name1;
							if((set_1=find_set(name1))!=NULL)
							{	
								name2=strtok(NULL,",\n");
								if(name2!=NULL)
	  							{	if(strlen(name2)==SIZE_LINE_SET){
									while (isspace(*name2))
										++name2;
									if((set_2=find_set(name2))!=NULL)
									{
										name3=strtok(NULL,"\n");
										if(name3!=NULL)
										{	
											if((end=strlen(name3))==SIZE_LINE_SET)
											{
												if((result=find_set(name3))!=NULL)
												{	     		
													if(strcmp(temp, "union_set")==0)
										 			union_set(set_1, set_2,result);
										 			if(strcmp(temp, "intersect_set")==0)
												 	intersect_set(set_1, set_2,result);
									         			if(strcmp(temp, "sub_set")==0)
										 			sub_set(set_1, set_2,result);
									         			if(strcmp(temp, "symdiff_set")==0)
													symdiff_set(set_1, set_2,result);
												}
											}else 
											printf("Extraneous text after end of command\n");
			
										}else
										printf("Missing name set3\n");
									}/*set name*/
								}else
								printf("Missing comma");
								}else
								printf("Missing name set2 and set3\n");
							   }/*set name*/
							}else
							printf("Missing comma");
							
						}else 
						printf("Missing name set's\n");
					
			}else if(strcmp(temp, "stop")==0)
			{	free_sets(set_array,  AMOUN_SETS) ;
				return 1;
			
			}else
			printf("Undefined command name\n");
		}
		}
		}else
		printf("Missing command\n");
		
		printf("\n\n~prompt: ");
		
			
	}/*while<fgets>*/
return 0;
}		

/**********************************************************************************************************************************************************************/
int check_comma(char *input)   /*|the function counts the number of commas*/
{
	

	int comma=0;
	int i;
	if (strstr(input,"union_set")||strstr(input,"intersect_set")||strstr(input,"sub_set")||strstr(input,"symdiff_set"))
	{
		for(i=0;i<strlen(input);i++)
		{	
			
			if(input[i]==',' &&input[i+1]==',')
			{
			printf("Multiple consecutive commas");
			return 1;
			}
		}
	}

	if (strstr(input,"read_set"))
	{	

		for(i=0;i<strlen(input);i++)
		{	if(input[i]==',')
			comma++;
			
			if(input[i]==',' &&input[i+1]==',')
			{
			printf("Multiple consecutive commas");
			return 1;
			}
		}
		if(comma==0){
		printf("Missing commas");
		return 1;
		}
		
		
	}
		


	
	
	
		
        
	return 0;
}
/**********************************************************************************************************************************************************************/
int iligal_comma(char *input_copy)
{
	char *token;                          
	token=strtok(input_copy,"sS");
	if(strpbrk(token,","))
	{
		printf("Illigal comma");
		return 1;
	}
						/*the function checks that there is no comma after the command*/

	return 0;
}
/**********************************************************************************************************************************************************************/







		

