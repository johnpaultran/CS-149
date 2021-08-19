// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

// sorts array using bubble sort
void SortArray(int sortingList[], int numVals)
{
   int i, j; 
   for(i = 0; i < numVals - 1; i++)       
   {
      // Last i elements are already in place    
      for(j = 0; j < numVals - i - 1; j++) 
      {
         if (sortingList[j] > sortingList[j+1]) 
         { 
            int temp = sortingList[j];
            sortingList[j] = sortingList[j+1];
            sortingList[j+1] = temp;
         }
      }
   }
   // prints array
   for(int i = 0; i < numVals; i++)
   {
      printf("%d ", sortingList[i]);
   }
   printf("\n");
}

int main(void) 
{
   int numVals;
   scanf("%d", &numVals);
   
   // put numbers into array
   int sortingList[numVals];
   for(int i = 0; i < numVals; i++)
   {
      scanf("%d", &sortingList[i]);
   }

   SortArray(sortingList, numVals);

   return 0;
}