// Shayanna Gatchalian & John Paul Tran
// Assignment #3
// 3.19.2021

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_NAME_NUM 25                            // constant for file name size

int main(int argc, char** argv) 
{
    // check for correct number of arguments in cmd line
    if (argc != 2) 
    {
        printf("Please use ./proc_manager cmdfile to run code\n");
        return -1;
    }

    char message[250];                              // .err/.out message
    char * cmdfile = argv[1];                       // variable for cmdfile
    int cmdNum = 0;                                 // int to record number of commands

    // read from cmdfile
    FILE * fp = fopen(cmdfile, "r");
    if (fp == NULL) 
    {
        printf("Error: File is null\n");
        exit(1);
    }

    char * line = NULL;                             // points to line in cmdfile
    size_t size = 0;                                // size of line cmdfile
    ssize_t read;                                   // variable used to read from file

    char words[25][25];                             // 2D array to hold items from each line
    int i, j, token;                                // variables to iterate through loops/arrays
    
    // read by line
    while ((read = getline(&line, &size, fp)) != -1) 
    {
        line[read - 1] = '\0';                      // remove trailing \n
        cmdNum++;                                   // increment number of rows

        for (i = 0; i < 20; i++)                    // initialize 2D array with 0's
        {
            for (j = 0; j < 20; j++) 
            {
                words[i][j] = 0;
            }
        }

        j = 0;                                      // counter for for-loop
        token = 0;                                  // counter for each word in line

        // tokenize the items in each line and place into 2D array
        for(i = 0; i <= (strlen(line)); i++)
        {
            if(line[i] == ' '|| line[i] == '\0')
            {
                words[token][j] = '\0';             // append null char to end of word
                token++;                            // increment to next word
                j = 0;                              // intialize index to 0
            }
            else
            {
                words[token][j] = line[i];          // copy word to 2D array
                j++;                                // increment column of array
            }
        }

        // fork
        pid_t p = fork();
        
        if (p < 0) 
        {
            fprintf(stderr, "Fork failed");         // fork fails, exit
            return 1;
        }

        // child process
        if (p == 0) 
        {
            char *buf2[token + 1];                  // create new buf2

            for (i = 0; i < token; i++) 
            {
                buf2[i] = words[i];                 // initialize with values of words
            }

            buf2[token] = NULL;                     // set last element to NULL to avoid error

            char pidOutFile[FILE_NAME_NUM];         // create .out and .err files
            char pidErrFile[FILE_NAME_NUM];
            sprintf(pidOutFile, "%d.out", getpid());
            sprintf(pidErrFile, "%d.err", getpid());

            int fd1 = -1;
            int fd2 = -1;
            
            // open .out files  
            while (fd1 < 0)                                          
            {
                fd1 = open(pidOutFile, O_RDWR | O_APPEND);
                usleep(1000);                   
            }
            
            // open .err files
            while (fd2 < 0)                          
            {
                fd2 = open(pidErrFile, O_RDWR | O_APPEND);
                usleep(1000); 
            }

            dup2(fd1, 1);                           // make file handle 1 (stdout) go to a file PID.out + handle 2 (stderr) go to a file PID.err for pid PID
            dup2(fd2, 2);

            //execute
            if (execvp(buf2[0], buf2) < 0) 
            {     
                perror(buf2[0]);                    // failed
                exit(2);
            }
            exit(0);
        }

        // parent process
        if (p > 0) 
        {
            char pidOutFile[FILE_NAME_NUM];         // create .out and .err files
            char pidErrFile[FILE_NAME_NUM];
            sprintf(pidOutFile, "%d.out", p);
            sprintf(pidErrFile, "%d.err", p);
            
            int fd = open(pidOutFile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR|S_IWUSR);    // open .out and .err files
            open(pidErrFile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR|S_IWUSR);
            
            sprintf(message, "Starting command %d: child %d pid of parent %d\n", cmdNum, p, getpid());  // create message for each command
            
            write(fd, message, strlen(message));    // write constructed message to .out file
        }
    }

    fclose(fp);                                     // close file reader

    if (line) 
    {
        free(line);                                 // deallocate allocated memory
    }

    int status;                                     // status of the child process
    pid_t p;

    // wait for the child process to exit
    while ((p = wait(&status)) >= 0) 
    {
        if (p > 0) 
        {
            char pidErrFile[FILE_NAME_NUM];         // create .out and .err files
            char pidOutFile[FILE_NAME_NUM];
            snprintf(pidErrFile, FILE_NAME_NUM, "%d.err", p);
            snprintf(pidOutFile, FILE_NAME_NUM, "%d.out", p);

            int fd = open(pidOutFile, O_RDWR | O_APPEND);   // open .out and .err files
            
            sprintf(message, "Finished child %d pid of parent %d\n\n", p, getpid());    // create message

            write(fd, message, strlen(message));           // write constructed message to .out file

            fd = open(pidErrFile, O_RDWR | O_APPEND);

            // normal exit
            if (WIFEXITED(status)) 
            {
                sprintf(message, "Exited with exitcode = %d\n\n", WEXITSTATUS(status)); // receive exitcode
                write(fd, message, strlen(message));                                    // write to file
            } 
            // kill by user
            else if (WIFSIGNALED(status))
            {
                sprintf(message, "Killed with signal %d\n\n", WTERMSIG(status));        // receive signal
                write(fd, message, strlen(message));                                    // write to file
            }
        }
    }

    return 0;
}