#include<stdio.h>
#define MAX 80
 void cutStr(char str[]){ 
 int i=0,j=0,chek=1;
 for(i=0;str[i]!='\0';i++)
{
 if(((str[i]>='a'&& str[i]<='z')||(str[i]>='A'&& str[i+1]<='Z')) && str[i]+1==str[i+1])
 {               
  chek++;/*The variable counts the number of elements goes in sequence*/            
  if(chek==3) /* If there are 3 elements in the squence,the second element is replaced by"-".*/      
     str[i]='-';
  }
   else /*If the sequence has ended or it does not exit the counter becomes 1 .*/               
       chek=1;
   if(!((chek>3) && str[i]+1==str[i+1])) /*If the are more than 3 elements in the sequence ,delete all elements between "-" and the sequence .*/  
      str[j++]=str[i];
 }
  str[j]='\0'; /*cut off the tail*/  
  
}

int  main()
{
  char str[MAX];
  printf("Enter your String please\n");
  if ((fgets(str,MAX,stdin))==NULL||str[0]=='\n')/*check if there ia an array */
  printf("Wrong");
  else {
  printf("Your String is ==> %s",str);
  cutStr(str);
  printf("\nYour String after cut is==>%s\n",str);}
return 0;
}
 
