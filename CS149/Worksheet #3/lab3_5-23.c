// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <limits.h>

int main(void) {
   int numValues;                                        // # values in array
   
   scanf("%d", &numValues);                              // get user input for numValues
   
   int nums[numValues];                                  // number array
   
   for(int i = 0; i < numValues; i++)                    // get user inputs for number array
   {
      scanf("%d", &nums[i]);
   }
   
   int smallest = INT_MAX;                               // smallest value initialized as 1st value in array
   int secondSmallest = INT_MAX;                         // second smallest value initialized as 2nd value in array
   
   for(int i = 0; i < numValues; i++)                    // iterate number array to search smallest and second smallest array
   {
      if(nums[i] < smallest)                             // if current # < smallest value, update smallest/second smallest values
      {
         int temp = smallest;
         smallest = nums[i];
         secondSmallest = temp;
      }
      else if(nums[i] < secondSmallest)                  // if smallest < current # < second smallest value, update second smallest values
      {
         secondSmallest = nums[i];
      }
   }
   
   printf("%d and %d\n", smallest, secondSmallest);        // print smallest and second smallest values

   return 0;
}