// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

// function to return the largest of three input values
int LargestNumber(int userNum1, int userNum2, int userNum3)
{
   int largest;   // variable to hold largest number
   
   // first input is largest
   if (userNum1 >= userNum2 && userNum1 >= userNum3)
   {
      largest = userNum1;
   }
   
   // second input is largest
   if (userNum2 >= userNum1 && userNum2 >= userNum3)
   {
      largest = userNum2;
   }
   
   // third input is largest
   if (userNum3 >= userNum1 && userNum3 >= userNum2)
   {
      largest = userNum3;
   }
      
   return largest;   // return result
}

// function to return the smallest of three input values
int SmallestNumber(int userNum1, int userNum2, int userNum3)
{
   int smallest;  // variable to hold smallest number
   
   // first input is smallest
   if (userNum1 <= userNum2 && userNum1 <= userNum3)
   {
      smallest = userNum1;
   }
   
   // second input is smallest
   if (userNum2 <= userNum1 && userNum2 <= userNum3)
   {
      smallest = userNum2;
   }
   
   // third input is smallest
   if (userNum3 <= userNum1 && userNum3 <= userNum2)
   {
      smallest = userNum3;
   }
   
   return smallest;  // return results
}

int main(void) 
{
   // variables for user inputs
   int userNum1;
   int userNum2;
   int userNum3;

   // take in user inputs
   scanf("%d%d%d", &userNum1, &userNum2, &userNum3);
   
   // call to functions to get largest and smallest number of inputs
   int largest = LargestNumber(userNum1, userNum2, userNum3);
   int smallest = SmallestNumber(userNum1, userNum2, userNum3);
   
   // print results
   printf("largest: %d\n", largest);
   printf("smallest: %d\n", smallest);

   return 0;
}