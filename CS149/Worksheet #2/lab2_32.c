// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

int main(void) 
{
   // given
   int currentPrice;
   int lastMonthsPrice;
   
   // take in inputs
   scanf("%d", &currentPrice);
   scanf("%d", &lastMonthsPrice);
   
   // calculate changed price and mortgage
   int changedPrice = currentPrice - lastMonthsPrice;
   float estimatedMonthlyMortgage = (currentPrice * 0.051) / 12;
   
   // print results
   printf("This house is $%d. The change is $%d since last month.\n", currentPrice, changedPrice);
   printf("The estimated monthly mortgage is $%lf.\n", estimatedMonthlyMortgage);

   return 0;
}