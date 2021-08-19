// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   int userInput;
   int max = 0;
   int sum = 0;
   int count = 0;
   int flag = 1;  // flag for while loop
   
   while(flag == 1)
   {
      scanf("%d ", &userInput);  // get user input
      if(userInput < 0)          // breaks out of loop if negative input
         break;
      else if(userInput > max)   // check for max
         max = userInput;
      count++;                   // increment count
      sum += userInput;          // add userInput to sum for average calculation
   }
   
   int avg = sum / count;        // calculate average
   printf("%d %d\n", max, avg);  // print result

   return 0;
}