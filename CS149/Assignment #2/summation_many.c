// Assignment #2 
// Shayanna Gatchalian & John Paul Tran
// 3.3.2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

// main function to take in arguments from command line
int main(int argc, char *argv[]) 
{
    double total_summation = 0;

    // get power value from command line
    char *str = argv[argc - 1];         // gets last arg from command line, define as power value
    if(str == NULL) // if power value is not inputted
    {
        printf("power value not inputted\n");
        exit(1);
    }
    double power = atoi(str);                   // cast to double
    
    // for each file being read
    for (int i = 1; i < argc - 1; i++)
    {
        int fd1[2]; // pipe for sending power value to summation calculation
        int fd2[2]; // pipe for sending summation value to total summation calculation

        // open pipe
        if(pipe(fd1) == -1)
        {
            fprintf(stderr, "pipe 1 failed");
            return 1;
        }
        if(pipe(fd2) == -1)
        {
            fprintf(stderr, "pipe 2 failed");
            return 1;
        }
        pid_t p = fork();

        if(p < 0)
        {
            fprintf(stderr, "fork failed");
            return 1;
        }

        // parent process
        else if (p > 0)
        {   
            double summation;

            // close reading end of first pipe
            close(fd1[0]);

            // send power value to child process
            write(fd1[1], &power, sizeof(power));
            close(fd1[1]);   

            // wait for child to send back summation value for each txt file
            wait(NULL);

            // close writing end of second pipe
            close(fd2[1]);

            // read summation value from child process
            read(fd2[0], &summation, sizeof(summation));
            
            // add summation values
            total_summation += summation;
            close(fd2[0]);
        }

        // child process
        else
        {
            // close writing end of first pipe
            close(fd1[1]);

            double summation = 0.0;               // summation to be returned
            read(fd1[0], &power, sizeof(power));
            double exponent = power;
            
            // read from txt file
            FILE *fp = fopen(argv[i], "r");
            
            if (fp != NULL)                     // make sure file opened for reading
            {
                double n;                       // number to be read in from text file
                
                while (fscanf(fp, "%lf", &n) != EOF) {
                    n = pow(n, exponent);       // put n to power
                    summation += n;             // add result to summation
                }
            }
            
            // close file reader
            fclose(fp);

            // close reading ends of pipes
            close(fd1[0]);
            close(fd2[0]);
            
            // write to summation value to pipe 2
            write(fd2[1], &summation, sizeof(summation));
            close(fd2[1]);

            exit(0);
        }
    }

    printf("%0.2lf\n", total_summation);  // print summation
    return 0;
}