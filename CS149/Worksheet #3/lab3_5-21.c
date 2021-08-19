// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <string.h>

int main(void) {
   char words[20][20];                  // 2D string array of user inputted words
   int numWords;                        // number of values user inputs
   char searchCharacter;                // char being searched in each string
   int i;                               // i counter for loop
   
   scanf("%d ", &numWords);             // user's 1st input is # inputs that will follow
   
   for(i = 0; i < numWords; i++)        // gets array of user inputted integers
   {
      scanf("%s", words[i]);
   }
   
   scanf(" %c", &searchCharacter);       // get char to search from user
   
   for(i = 0; i < numWords; i++)         // loop to find searchCharacter in each word of array
   {
      for(int j = 0; j < strlen(words[i]); j++) //search each char of word
      {
         if(words[i][j] == searchCharacter)     //compare each char with searchCharacter
         {
            printf("%s,", words[i]);            //print words that contain searchCharacter
            break;
         }
      }
   }

   return 0;
}