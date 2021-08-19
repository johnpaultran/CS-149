// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>

// function to convert miles to track laps
double MilesToLaps(double userMiles)
{
   double laps;               // variable to hold lap conversion
   
   laps = userMiles / 0.25;   // calculation
   return laps;               // return result
}

int main(void) 
{
   // variables for miles input and result
   double userMiles;
   double laps;
   
   // take in miles from user
   scanf("%lf", &userMiles);
   
   // call to MilesToLaps function for conversion
   laps = MilesToLaps(userMiles);
   
   // print result
   printf("%0.2lf\n", laps);

   return 0;
}