// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) {

   int input;        // variable for input
   int binary[20];   // array to hold binary conversion values
   int i;
   
   // take in user input
   scanf("%d",&input);
   
   // conversion from decimal to binary
   for(i = 0; input > 0; i++)
   {
      binary[i] = input % 2 ; // insert reminder into array
      input= input / 2;       // divide by two for next iteration
   }
   
   int temp = i;  // store max i value for next loop
   
   // print results in reverse order
   for(i = 0; i < temp; i++)
      printf("%d", binary[i]);

   // exit
   return 0;
}
