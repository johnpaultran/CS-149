// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   // variables for manipulation
   int userNum;
   int userNum2;
   int squared;
   int cubed;
   int sum;
   int product;
   
   // take in integer
   printf("Enter integer:\n");
   scanf("%d", &userNum);
   
   // print out input
   printf("You entered: %d\n", userNum);
   
   // square and print output
   squared = userNum * userNum;
   printf("%d squared is %d\n", userNum, squared);
   
   // cube and print output
   cubed = userNum * userNum * userNum;
   printf("And %d cubed is %d!!\n", userNum, cubed);
   
   // take in another integer
   printf("Enter another integer:\n");
   scanf("%d", &userNum2);
   
   // sum integers and print
   sum = userNum + userNum2;
   printf("%d + %d is %d\n", userNum, userNum2, sum);

   // multiply integers and print 
   product = userNum * userNum2;
   printf("%d * %d is %d\n", userNum, userNum2, product);
   
   return 0;
}
