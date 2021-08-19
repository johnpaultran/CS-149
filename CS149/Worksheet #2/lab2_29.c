// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <math.h>

int main(void) {
   double x;
   double y;
   double z;
   
   // get user input
   scanf("%lf", &x);
   scanf("%lf", &y);
   scanf("%lf", &z);

   // x to the power of z
   double a = pow(x, z);
   
   // x to the power of (y to the power of 2)
   double b = y * y;
   b = pow(x, b);
   
   // absolute value of y
   double c = fabs(y);
   
   // square root of (xy to the power of z)
   double d = x * y;
   d = pow(d, z);
   d = sqrt(d);
   
   //print result
   printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a, b, c, d);

   return 0;
}
