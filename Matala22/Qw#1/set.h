#define AMOUNT_OF_BITES 16
#define SIZE_OF_BYTE 8
#define END -1
#define AMOUN_SETS 6
#define BIGEST_NUMBER 128 
#define LINE_SIZE 512
#define SIZE_LINE_SET 4
/**********************************************************************************************************************************************************************/
typedef struct {
int size;
char data[AMOUNT_OF_BITES];
} set;
set *set_array[AMOUN_SETS];
/*********************************************************************************************************************************************************************/
void read_set(set *s, int *nums);				
/*|read_set function allows the user to insert integer values (range:0-127 inc.)   	|
  |into a selected valid set.Each call to this function will delete the previous   	|
  |data in the used set.Parameters:						   	|
  |	s - pointer to destination set.						   	|
  |	num - pointer to int args array (contains number args by user).            	|
*/
/**********************************************************************************************************************************************************************/
void print_set(set *s);
/*|print_set function allows the user to print the data contained by a set.	   	|
  |It will print in ascending order the values of that set,up to 16 values 	   	|
  |per line.parameters:							   	   	|
  |				s - pointer to set to be printed          	   	|
*/                   									
/**********************************************************************************************************************************************************************/
void intersect_set(set *set1, set *set2, set *result);
/*|intersect_set function provides the user with the option to perform the	   	|
  |mathematical operation of sets intersection on 2 sets. A third set will	   	| 
  |be inserted with the result.						  	   	|
  |	parameters:							  	   	|
  |			set1 - pointer to set argument 1.   		  	   	|
  |		 	set2 - pointer to set argument 2.		  	   	|
  |			result - pointer to set to be inserted with 	  	   	|
  |			intersection result.				  	   	|
  |									  	   	|
  |NOTE: the same set can be passed as any argument in the argument list. 	   	|
*/
/**********************************************************************************************************************************************************************/
void union_set(set *set1, set *set2, set *result);
/*|union_set function provides the user with the option to perform the mathematical	|
  |operation of sets union on 2 sets. A third set will be inserted with the result.	|
  |parameters:									   	|
  |		set1 - pointer to set argument 1.			   	   	|
  |		set2 - pointer to set argument 2.			   	   	|	
  |		result - pointer to set to be inserted with union result.	   	|
  |										   	|
  |NOTE: the same set can be passed as any argument in the argument list.	   	|
*/
/**********************************************************************************************************************************************************************/
void sub_set(set *set1, set *set2, set *result);
/*|sub_set function provides the user with the option to perform the mathematical  	|
  |operation of sets subtraction on 2 sets. A third set will be inserted with the  	| 
  |result.									   	|
  |parameters:									   	|
  |		set1 - pointer to set argument 1.				   	|
  |		set2 - pointer to set argument 2.   				   	|
  |		result - pointer to set to be inserted with subtraction result.    	|
  |										   	|
  |NOTE: the same set can be passed as any argument in the argument list.	   	|
*/
/**********************************************************************************************************************************************************************/
void symdiff_set(set *s1, set *s2, set *result);
/*|symdiff_set function provides the user with the option to perform the mathematical  	|
  |operation of sets subtraction on 2 sets. A third set will be inserted with the      	| 
  |result.									       	|
  |parameters:									       	|
  |		set1 - pointer to set argument 1.				       	|
  |		set2 - pointer to set argument 2.   				       	|
  |		result - pointer to set to be inserted with subtraction result.        	|
  |										       	|
  |NOTE: the same set can be passed as any argument in the argument list.	       	|
*/
/**********************************************************************************************************************************************************************/
int init_sets();
/*|create_set function allocates the needed memory space to create a new set	       	|
  |and returns 1 if not space for memory					       	|
*/
/**********************************************************************************************************************************************************************/
set *find_set(char *name) ;
/*|The function looks for an indication by the name of the group.			|
*/
/**********************************************************************************************************************************************************************/
void free_sets(set **sets, int num_sets);
/*|free_sets function frees up the space allocated to the arguments sets		| 
  |parameters:							        		|
  |		set_array - array of pointers.                          		|
  |		amount_sets;                                            		|
*/
/**********************************************************************************************************************************************************************/
void free_set(set *s);
/*|free_set function free up the space allocated to the argument set  			| 
  |parameters:							      			|
  |		set_array - array of pointers.                        			|
  |		amount_sets;                                          			|
*/

/**********************************************************************************************************************************************************************/
void stop(void);
/*|stop function provides the user with a way to terminate the set operations      	|
  |program.If the stop function is invoked, then the program will exit    	   	|
  |	successfully.								   	|
*/
/**********************************************************************************************************************************************************************/
