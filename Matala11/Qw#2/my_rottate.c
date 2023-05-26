#include<stdio.h>
#define SIZE sizeof(unsigned  int)*8
unsigned int my_rottate (unsigned int n,  int k)
{

return  k>0?(n>>k)|(n<<(SIZE-k)):(n<<-k)|(n>>(SIZE+k));


/*Do a normal shift to the left ot to the right while isolating "k" bits of the left or right,the return bitwise    OR shifted number whuth the isolated bits in the correct position*/
}
void dec2bin(unsigned int n)
{
 for(int i=0;i<SIZE;i++,n=n<<1) 
 {
  if(i%8==0) /*Space every eigth  */
  putchar(' ');
  putchar('0'+(n>>(SIZE-1)));/*Prints "0" or "1"*/
 }
}
int main ()
{
unsigned int n;
int k;
printf("Enter a number:\n");
scanf("%u",&n);
printf("%u",n);
printf("\nEnter a number of rottate :\n");
scanf("%d",&k);
printf("%d",k);

printf("\nThe number before shift:\nIn basis 10 is: %d\nIn basis 8 is: %o\nIn basis 16 is: %x\nIn basis 2 is:",n,n,n);
dec2bin(n);
if(k<0)
printf("\n\n Shift to the left on %d positions\n",-k);
else 
printf("\n\n Shift to the right on %d positions\n",k);
if(k==0)
printf("No Shift");



printf("\n The number  after shift :\nIn basis 10 is %u \nIn basis 8 is %o\nIn basis 16 is %0x\nIn basis 2 is :",my_rottate(n,k),my_rottate(n,k),my_rottate(n,k));
dec2bin(my_rottate(n,k));
printf(" \nFinish\n");
return 0;
}

