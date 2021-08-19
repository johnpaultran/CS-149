// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

// function to convert integer to reverse binary using given algorithm
void IntegerToReverseBinary(int integerValue, char binaryValue[])
{
   char binary;   // char to hold binary values  
   int i = 0;     // variable to iterate through binaryValue array
   
   // calculate reverse binary and place into array
   while(integerValue > 0)
   {
      binary = '0' + (integerValue % 2);
      integerValue /= 2;
      binaryValue[i++] = binary;
   }
   
   // append null character to end of array
   binaryValue[i] = '\0';
}

// function to reverse number to the correct binary
void ReverseString(char inputString[], char reversedString[])
{
   // variable to iterate through char arrays and calculate length
   int j = 0;
   
   // while current index is not the null char, increment j
   while(inputString[j] != '\0')
   {
      j++;
   }
   
   // set length and reset
   int length = j;
   j = 0;
   
   // reverse binary for correct result
   for(int i = length - 1; i >= 0; i--)
   {
      reversedString[j++] = inputString[i];
   }
   
   // append null character to end of array
   reversedString[j] = '\0';
}

int main(void) 
{
   int integerValue;
   char inputString[20], reversedString[20];
   scanf("%d", &integerValue);
   
   // call functions to calculate binary number
   IntegerToReverseBinary(integerValue, inputString);
   ReverseString(inputString, reversedString);
   
   // print result
   printf("%s\n", reversedString);

   return 0;
}
