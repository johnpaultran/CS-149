// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 20;         // Number of input integers
   int userVals[NUM_ELEMENTS];          // Array to hold the user's input integers
   int numValues;                       // number of values user inputs
   int i;                               // i counter for loop
   
   scanf("%d ", &numValues);            // user's 1st input is # inputs that will follow
   
   for(i = 0; i < numValues; i++)       // gets array of user inputted integers
   {
      scanf("%d", &userVals[i]);
   }
   
   for(i = numValues - 1; i >= 0; i--)  // prints reverse order of user inputs
   {
      printf("%d,", userVals[i]); 
   }

   printf("\n");

   return 0;
}