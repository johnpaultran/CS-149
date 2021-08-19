// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 20;
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user

   int numValues;                       // number of values user inputs
   int threshold;                       // ceiling value
   int i;                               // i counter for loop
   
   scanf("%d ", &numValues);            // user's 1st input is # inputs that will follow
   
   for(i = 0; i < numValues; i++)       // gets array of user inputted integers
   {
      scanf("%d", &userValues[i]);
   }
   
   scanf("%d", &threshold);             // get threshold value from user
   
   for(i = 0; i < numValues; i++)       
   {
      if(userValues[i] <= threshold)
         printf("%d,", userValues[i]);  // print values that are <= threshold
   }

   printf("\n");

   return 0;
}