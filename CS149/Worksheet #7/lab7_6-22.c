// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

// function to return two values in swapped order
void SwapValues(int* userVal1, int* userVal2)
{
   // swaps values pointed by userVal1 and userVal2
   int temp = *userVal1;
   *userVal1 = *userVal2;
   *userVal2 = temp;
}

int main(void) 
{
   // variables to hold user values
   int userVal1;
   int userVal2;

   // take in user values
   scanf("%d %d", &userVal1, &userVal2);
   
   // call to swap and print results
   SwapValues(&userVal1, &userVal2);
   printf("%d %d\n", userVal1, userVal2);

   return 0;
}