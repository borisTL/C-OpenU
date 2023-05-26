#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
/**********************************************************************************************************************************************************************/




set *find_set(char *name) 
{    
	     if (strcmp(name, "SETA") == 0)
		return set_array[0];
	else if (strcmp(name, "SETB") == 0)
		return set_array[1];
	else if (strcmp(name, "SETC") == 0) 
	    	return set_array[2];
	else if (strcmp(name, "SETD") == 0) 
	    	return set_array[3];
	else if (strcmp(name, "SETE") == 0) 
	    	return set_array[4];
	else if (strcmp(name, "SETF") == 0) 
	    	return set_array[5];
	else 
	{
		printf("Undefined set name\n");
	    	return NULL;
	 }
}

/**********************************************************************************************************************************************************************/
int init_sets()
{
	for (int i = 0; i < AMOUN_SETS; i++)
	{
	        set_array[i] = (set*) calloc(AMOUNT_OF_BITES,SIZE_OF_BYTE);
		if (set_array[i] == NULL)
		{
	            printf("Error: memory allocation failed.\n");
			return 1;
		}
	}
	return 0;
}
/**********************************************************************************************************************************************************************/
void free_sets(set **sets, int num_sets) 
{
	for (int i = 0; i < num_sets; i++) 
	free_set(sets[i]);
}
/**********************************************************************************************************************************************************************/
void free_set(set *s) 
{ 
  int i;
  for (i = 0; i < AMOUNT_OF_BITES; i++) 
    s->data[i] = 0;
  
  free(s);
  
}

/**********************************************************************************************************************************************************************/
void read_set(set *s, int *nums) 
{	  
	memset(s->data, 0, sizeof(s->data));
	int i = 0;
	while (nums[i] != -1) 
	{
          	if (nums[i] >= 0 && nums[i] < BIGEST_NUMBER)
		{ 
			 s->data[nums[i] /  SIZE_OF_BYTE ] |= 1 << (nums[i] % SIZE_OF_BYTE);
			 s->size++;
		}
			
   		i++;
        }
	printf("Done\n");
}
/**********************************************************************************************************************************************************************/
void print_set(set *s) 
{
	if (s->size == 0)
 	     	printf("Set is empty\n");
        else
	{
		for (int i = 0; i < AMOUNT_OF_BITES; i++) 
		{	
			for (int j = 0; j < SIZE_OF_BYTE; j++) 
			{
				if (s->data[i] & (1 << j)) 
				{	
					printf("%d ", i * SIZE_OF_BYTE + j);
					
				}
			
				
			}
		
		}
	}
	printf("\n");
}
/**********************************************************************************************************************************************************************/
void union_set(set *s1, set *s2,set *result)
{
	
	for (int i = 0; i < AMOUNT_OF_BITES; i++)
	{
		result->data[i] = s1->data[i] | s2->data[i];
		if (s1->data[i] | s2->data[i]) 
        		result->size++;
	}
printf("Done\n");
}
/**********************************************************************************************************************************************************************/
void intersect_set(set *s1, set *s2,set *result)
{
	for (int i = 0; i < AMOUNT_OF_BITES; i++) 
	{
		result->data[i] = s1->data[i] & s2->data[i];
		if (result->data[i]) 
		{
			result->size++;
		}
	}
	printf("Done");
}
/*********************************************************************************************************************************************************************/
void sub_set(set *s1, set *s2, set *result)
{
	int size = 0;
    	for (int i = 0; i <AMOUNT_OF_BITES; i++)
	{
       		result->data[i] = s1->data[i] & (~s2->data[i]);
        	for(int j=0;j<SIZE_OF_BYTE;j++)
         	   if(result->data[i] & 1<<j)
            	       size++;
    	}
    	result->size = size;
	printf("Done");
}
/**********************************************************************************************************************************************************************/
void symdiff_set(set *s1, set *s2, set *result)
{
	int size = 0;
	for (int i = 0; i < AMOUNT_OF_BITES; i++)
	{
      		result->data[i] = (s1->data[i] ^ s2->data[i]) & (~(s1->data[i] & s2->data[i]));
       		for(int j=0;j<SIZE_OF_BYTE;j++)
        		if(result->data[i] & 1<<j)
                		size++;
        }
    	result->size = size;
	printf("Done");
}
/**********************************************************************************************************************************************************************/

