// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) 
{
   char userName[50];       // char array for username string
   
   scanf("%s", userName);   // take in user name
   
   // print output
   printf("Hello %s, and welcome to CS Online!\n", userName);

   return 0;
}