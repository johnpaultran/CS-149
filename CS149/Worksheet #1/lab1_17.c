// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {
   int baseInt;
   int headInt;
   
   // take in input values
   scanf("%d", &baseInt);
   scanf("%d", &headInt);

   printf("    %d\n", headInt);                                                                             //    1
   printf("    %d%d\n", headInt, headInt);                                                                  //    11
   printf("%d%d%d%d", baseInt, baseInt, baseInt, baseInt); printf("%d%d%d\n", headInt, headInt, headInt);   //0000111
   printf("%d%d%d%d", baseInt, baseInt, baseInt, baseInt); printf("%d%d%d%d\n", headInt, headInt, headInt, headInt);    //00001111
   printf("%d%d%d%d", baseInt, baseInt, baseInt, baseInt); printf("%d%d%d\n", headInt, headInt, headInt);   //0000111
   printf("    %d%d\n", headInt, headInt);                                                                  //    11
   printf("    %d\n", headInt);                                                                             //    1
   
   return 0;
}
