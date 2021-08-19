// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 9;
   int userValues[NUM_ELEMENTS];           // Set of data specified by the user

   int userInput;                          // user integer input
   int count = 0;                          // # of values in array
   
   scanf("%d", &userInput);
   while(userInput > 0)                    // while user input is positive
   {
      if(count > 9)                        // if user inputs > 9 numbers, print "Too many numbers"
      {
         printf("Too many numbers\n");
         break;
      }   
      if(userInput < 0)                    // if user input is negative, break from loop
         break;
      else
      {
         userValues[count] = userInput;
         count++;                          // else, increment # of user inputs
      }
      scanf("%d", &userInput);             // get user input
   }
   
   int middleValue = userValues[count/2];       // calculate middle value
   
   if(count <= 9)
      printf("Middle item: %d\n", middleValue);    // print middle value

   return 0;
}