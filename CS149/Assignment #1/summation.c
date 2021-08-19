// Assignment #1 
// Shayanna Gatchalian & John Paul Tran
// 2.15.2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// main function to take in arguments from command line
int main(int argc, char *argv[]) 
{
    double n = 0;           // number to be read in from text file
    double summation = 0;   // summation to be returned

    // open file to read
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("range: cannot open file\n");
        exit(1);
    }

    char *str = argv[2];            // take in power to raise numbers from command line
    
    if(str == NULL)
    {
        printf("power value not inputted\n");
        exit(1);
    }

    double power = atoi(str);       // cast to double

    // read in integers from text file
    while(fscanf(fp, "%lf", &n) != EOF) 
    {
        n = pow(n, power);          // put n to power
        summation += n;             // add result to summation
    }

    printf("%0.2lf\n", summation);  // print summation
    fclose(fp);                     // close

    exit(0);
}