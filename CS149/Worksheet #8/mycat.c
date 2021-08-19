// Shayanna Gatchalian & John Paul Tran
// given mycat file
#include "apue.h"

#define	BUFFSIZE	4096

int main(void) 
{
	int n;
	char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) 
    {
        if (write(STDOUT_FILENO, buf, n) != n) 
            err_sys("write error");
        // added print statement to write to stderr the number of bytes
        fprintf(stderr, "%d\n", n);
    }

    if (n < 0)
        err_sys("read error");
	exit(0);
}