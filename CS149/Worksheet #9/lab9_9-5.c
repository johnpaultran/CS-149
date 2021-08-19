// Shayanna Gatchalian & John Paul Tran
#include<stdio.h>
#include <string.h>

int main(void) 
{
   // variables to manipulate strings
   char input[50];
   char str1[50];
   char str2[50];
   
   while(1) 
   {
      printf("Enter input string:\n");    // prompt for user
      fgets(input, 50, stdin);            // get input
      
      // if input is q then break out of loop
      if(input[0] == 'q') 
      {
         break;
      }
      
      // parse through first string
      int i;
      for(i = 0; input[i] != ',' && input[i] != '\0'; i++) 
      {
         // skip spaces
         if(input[i] != ' ') 
         {
            str1[i] = input[i];
         }
      }
      
      str1[i] = '\0';   // append null char
      
      // check for comma in input string
      if(input[i] != ',') 
      {
         printf("Error: No comma in string.\n\n");
         continue;
      } 
      else 
      {
         // skip over comma/space if comma in input
         while(input[i] == ',' || input[i] == ' ') 
         {
            i++;
         }
      }
      
      // parse through second string
      int j;
      for(j = 0; input[i] != '\0'; j++, i++) 
      {
         str2[j] = input[i];
      }
      
      str2[j] = '\0'; // append null char
      
      // print results
      printf("First word: %s\n", str1);
      printf("Second word: %s\n", str2);
   }

   return 0;
}
