#include<stdio.h>
#include<string.h>   
#include<stdlib.h> 

#define VARIABLE 0

#define MAXSIZE 513  

#define ON 0
#define OFF -1

#define STEP1_INPUT 0
#define STEP2_INPUT 1
#define STEP3_INPUT 2
#define STEP4_INPUT 3

#define NUMBER_STEP_INPUT 4

#define NUMBER_TITELE 0

#define NUMBER_FUNCTIONS_FOR_CHECK_INPUT 4
#define CONVERSION_FUNCTION 3
#define FUNCTION_FOR_INPUT_STRING 0



   								     /*|Function :|*/
void printTitle (int numbertitel);                                   /*|1.Function <printTitle>      to print headers for input.|*/
void printError (int error_number);                                  /*|2.Function <printError>      to print error type.|*/
int checkemptyInput (char *str, int error_number);                   /*|3.Function <checkemptyInput> checks if the array is not empty .|*/
int checkNegative (char *str, int error_number);                     /*|4.Function <chekNegative>    checks that input is not negative.|*/
int checkInteger (char *str, int error_number);                      /*|5.Function <chekInteger>     checks that input is type integer.|*/
int checkIntsize (char *str, int error_number);                      /*|6.Function <chekIntsize>     checks that input size.|*/
int checkBounse (int longstirng, size_t len, int index1, int index2);/*|7.Function <chekBounse>      checks that pointers not out of bounds.|*/
int my_bcmp (const void *b1, const void *b2, size_t len);            /*|8.Function <my_bcmp>         cheks compares memory segments byte by byte.|*/
int matala12(char *str,size_t len,char *b1,char *b2,int index1,int index2,int lengs,int error_number);

 

/**********************************************************************************************************************************************************************/
                                                                             /*|Main function of my_bcmp:|*/
                                                                             /*|Variables are declared in the main function, and the 'matala12' function is|*/       
                                                                             /*|called,after the completion of the 'matala' function, the program ends|*/


                                                                                                                                                                         
                                                                 
int main ()
{ char str[MAXSIZE];
  size_t len=VARIABLE;
  char *b1=VARIABLE, *b2=VARIABLE;								
  int index1=VARIABLE, index2=VARIABLE, lengs=VARIABLE;
  int error_number = VARIABLE;

matala12( str, len, b1, b2,index1, index2,lengs, error_number);
return OFF;
}
  
/**********************************************************************************************************************************************************************/

int matala12(char *str,size_t len,char *b1,char *b2,int index1,int index2,int lengs,int error_number)
{printf("Variable filling format:\n1.Without white letters before entering.\n2.Positive integer value.\n3.Not empty variables.\n4.In case of incorrect input, the program will give an error and finish the program.\n5.To end the input, you can press enter or 'ctrl D'.\n<***************************************************************************************************************************************************>\n");

int (*operation[ NUMBER_FUNCTIONS_FOR_CHECK_INPUT]) (char *str, int wrong) ={checkemptyInput, checkNegative,checkInteger, checkIntsize};
for (int i = 0; i < NUMBER_STEP_INPUT; i++)
    {
     printTitle (i);
     if (i < STEP4_INPUT)                                                    /*|In function  matala12, an array of function pointers was created to check the input |*/
      {                                                                      /*|data.If the input data was entered correctly then a function call will be made|*/
       for (int j = 0; j < NUMBER_FUNCTIONS_FOR_CHECK_INPUT; j++)            /*|to check that the pointer is not out of bounds,after that, the 'my_bcmp' function |*/
        {               					             /*|will becalled, which will check the memory cells bit by bit and a message will be |*/ 
	  if (operation[j] (str, error_number++) == OFF)                     /*|displayed on the screen with the result.|*/
          return OFF;                                                        
         }                                                                   
                  switch (i)                                                 
		  {
		  case STEP1_INPUT:
		    len = operation[CONVERSION_FUNCTION] (str, error_number);    /*|Part of the code, after checking the input data, assigns|*/
                                                                                 /*|the corresponding variables to the following values/*/
		    break;
		  case STEP2_INPUT:
		    index1 = operation[CONVERSION_FUNCTION] (str, error_number);
		    break;
		  case STEP3_INPUT:
		    index2 = operation[CONVERSION_FUNCTION] (str, error_number);
		    break;
                  }
        }
	else if (operation[FUNCTION_FOR_INPUT_STRING] (str, error_number++) != OFF)  /*|Part of the input and string validation code|*/
	lengs = strlen (str);
      }
  printf("YOUR INPUT IS:%u,%d,%d,%s",len,index1,index2,str);

  if ((checkBounse (lengs, len, index1, index2))==ON)
    {
      b1 = str + index1;
      b2 = str + index2;
    }
  else
    return OFF;

  int result_bcmp=my_bcmp (b1, b2, len);                                                  /*|Part of the code for the result of function my_bcmp.|*/
  if (result_bcmp != ON)
    {
      printf ("TWO MEMORY SRGMENTS DO NOT CONTAIN IDENICAL CONTENT AND RETURN RESULT IS %d\n",result_bcmp);
      return OFF;
    }
  else
    printf ("TWO MEMORY SRGMENTS CONTAIN IDENICAL CONTENT AND RETURN RESULT IS %d\n",result_bcmp);
return ON;
}
/**********************************************************************************************************************************************************************/
void printTitle (int numbertitel)
{
  char static *seetitle[] =
    { "\nEnter number of bytes to be compared:",                       /*|Header printing function|*/
      "\nEnter first pointer :",
      "\nEnter second pointer :", "\nEnter your string:\n" 
    };
  printf ("%s", seetitle[numbertitel]);
}
/**********************************************************************************************************************************************************************/
void printError (int error_number)
{
  char static *seerror[] =
    { "WRONG:LEN NUMBER IS NOT ENTER\n",
      "WRONG:LEN IS NEGATIVE\n",
      "WRONG:LEN IS NOT INTEGER\n",
      "WRONG:LENGTH  BIGGEST OF MAX SIZE(512)\n",
      "WRONG:FIRST POINTER IS NOT ENTER\n",
      "WRONG:FIRST POINTER IS NEGATIVE\n", 
      "WRONG:FIRST POINTE IS NOT INTEGER\n",                               /*|Error type print function|*/
      "WRONG:FIRST POINTER  BIGGEST OF MAX SIZE(512)\n",
      "WRONG:SECOND POINTER IS NOT ENTER\n",
      "WRONG:SECONF POINTER IS NEGATIVE\n",
      "WRONG:SECOND POINTE IS NOT INTEGER\n",
      "WRONG:SECOND POINTER  BIGGEST OF MAX SIZE(512)\n",
      "WRONG:YOUR STRING IS EMPTY"
   };
  printf ("%s", seerror[error_number]);
}
/**********************************************************************************************************************************************************************/
int checkemptyInput (char *str, int error_number)
{
  if ((fgets (str, MAXSIZE, stdin) == NULL) || str[0] == '\n')
    {
       printError(error_number);                                       
      return OFF;
    }

return ON;
}
/**********************************************************************************************************************************************************************/
int checkNegative (char *str, int error_number)
{
  if (*str == '-')
    {
      printError(error_number);
      return OFF;
    }
  return ON;
}
/**********************************************************************************************************************************************************************/
int checkInteger (char *str, int error_number)
{
  while (*str != '\n' && *str != '\0')
    {
      if (*str < '0' || *str > '9')
	{
	  printError (error_number);
	  return OFF;
	}
      ++str;
    }
  return ON;
}
/**********************************************************************************************************************************************************************/
int checkIntsize (char *str, int error_number)
{
  int number = atoi (str);
  if (number > MAXSIZE)
    {
      printError (error_number);
      return OFF;
    }
  return number;
}
/**********************************************************************************************************************************************************************/
int checkBounse (int longstirng, size_t len, int index1, int index2)
{
  if (longstirng < index1 + len)
    {
      printf ("WRONG:INDEX1 OUT OF BOUNDS");
      return OFF;
    }
  if (longstirng < index2 + len)
    {
      printf ("WRONG:INDEX2 OUT OF BOUNDS");
      return OFF;
    }
  return ON;
}
/**********************************************************************************************************************************************************************/
int my_bcmp (const void *b1, const void *b2, size_t len)
{
  if (!len)
    return ON;

  while (--len && *(char *) b1 == *(char *) b2)
    {
      ++*(char *) b1;
      ++*(char *) b2;

    }
  return ((*(unsigned char *) b1) - *((unsigned char *) b2));
}

