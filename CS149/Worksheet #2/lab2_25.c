// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   int userNum;
   int x;
   
   // take in inputs
   scanf("%d", &userNum);
   scanf("%d", &x);

   // divide by x and print result x3
   userNum /= x;
   printf("%d ", userNum);
   userNum /= x;
   printf("%d ", userNum);
   userNum /= x;
   printf("%d\n", userNum);
   
   return 0;
}