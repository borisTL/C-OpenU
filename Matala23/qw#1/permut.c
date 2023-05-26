#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permute(char* a, int start_word, int end_word, char* word)
{
	if (start_word == end_word) 
	{
        	if (strstr(word, a) != NULL)
			printf("%s\n", a);
	}
	else
	{
	   for (int i = start_word; i <= end_word; i++) 
	   {
            	char temp = a[start_word];
            	a[start_word] = a[i];
            	a[i] = temp;
            	permute(a, start_word+1, end_word, word);
            	temp = a[start_word];
            	a[start_word] = a[i];
            	a[i] = temp;
           }
       }
}

int main(int argc, char* argv[])
{
	if (argc != 3)
        {
        	fprintf(stderr, "Invalid number of arguments\n");
        	return 1;
        }
    	char* file_name = argv[1];
    	char* word = argv[2];
    	int n = strlen(word);

    	FILE* fp = fopen(file_name, "r");
    	if (!fp)
	{
	        fprintf(stderr, "Error opening file\n");
	        return 1;
        }

	fseek(fp, 0, SEEK_END);
	long size_file = ftell(fp); 
	rewind(fp); 

    	if(size_file <= 0)
	{
	        printf("File is empty\n");
	        return 1;
	}

	char buffer[1024];
    	int found = 0;

    	while (fgets(buffer,sizeof(buffer),fp))
	{
     	   permute(word,0,n-1,buffer);
     	   if(strstr(buffer,word) != NULL) 
    	       found++;
	}
	fclose(fp);

	if (found==0) 
        	printf("No permutations found in file\n");

	return 0;
}   


