// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <string.h>

// function that returns the number of times the input character appears in the input string
int CountCharacters(char userChar, char* userString) 
{
   int count = 0;    // variable to hold count of given char
   
   // iterate through string
   for(int i = 0; userString[i] != '\0'; i++)   
   {
      // if match, increment count
      if(userString[i] == userChar)
      {
         count++;
      }
   }
   return count;     // return count
}

int main(void) 
{
   // variables for user input
   char userChar;
   char userString[50];
   
   // get user input
   scanf("%c", &userChar);
   scanf("%s", userString);
   
   // print result
   printf("%d\n", CountCharacters(userChar, userString));
   return 0;
}