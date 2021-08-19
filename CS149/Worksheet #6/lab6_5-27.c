// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <string.h>

int main(void) 
{
   char input[50];                     // variable to hold input phrase
   int isPalindrome = 1;               // variable to hold t(1) or f(0) of palindrome
   
   fgets(input, 50, stdin);            // get input from user
   input[strlen(input)] = '\0';        // append null char to end of input
   
   // variables to iterate through front and back of input
   int i = 0; 
   int j = strlen(input) - 1;
   
   // while front and back pointers have not crossed
   while (i < j) 
   {
      // ignore spaces
      if (input[i] == ' ') 
      {
         i++;
         continue;
      }
      // ignore spaces
      if (input[j] == ' ') 
      {
         j--;
         continue;
      }
      // if current indexes do not match, set to false
      if (input[i] != input[j]) 
      {
         isPalindrome = 0;
         break;
      }
      // iterate to next indexes
      i++;
      j--;
   }
   
   // print correct result
   if (isPalindrome) 
   {
      printf("palindrome: %s\n", input);
   } 
   else 
   {
      printf("not a palindrome: %s\n", input);
   }
   
   return 0;
}