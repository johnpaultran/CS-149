// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {

   int numValues;          // variable for number of values
   int intValues[20];      // array to hold values
   int low;                // lower range
   int high;               // upper range
   int i;                  // variable for loop iteration

   scanf("%d",&numValues); // take in number of values
   
   // scan values into array
   for(i = 0; i < numValues; i++)
   {
      scanf("%d", &intValues[i]);
   }
   
   // scan lower and upper bounds of range
   scanf("%d %d", &low, &high);

   // print values in range
   for(i = 0; i < numValues; i++)
   {
      if(intValues[i] >= low && intValues[i] <= high)
         printf("%d,", intValues[i]);
   }
   printf("\n");
   
   return 0;
}