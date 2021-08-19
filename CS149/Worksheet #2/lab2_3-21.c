// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   int x;
   int y;
   int z;
   int smallest;
   
   // get user inputs
   scanf("%d", &x);
   scanf("%d", &y);
   scanf("%d", &z);
   
   // get smallest value from inputs
   smallest = x;
   if(smallest > y)
      smallest = y;
   if(smallest > z)
      smallest = z;
      
   // print result
   printf("%d\n", smallest);

   return 0;
}