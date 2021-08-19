// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <string.h>

int main(void) 
{
   char input[50];   // char array to hold user input
   int length;       // variable to hold input length
   int flag = 0;     // flag for while loop
  
   while(flag == 0)
   {   
      // get user input
      fgets(input, sizeof(input), stdin);
   
      // if input is "done", break the loop
      if(strncmp(input, "Done", 4) == 0 || strncmp(input, "done", 4) == 0 || strncmp(input, "d", 1) == 0)
      {
         break;
      }
      
      length = strlen(input);   // calculate input length
      
      // reverse string & print result
      for(int i = length - 2; i >= 0; i--)
      {
         printf("%c", input[i]);
      }
      printf("\n");
   }

   return 0;
}