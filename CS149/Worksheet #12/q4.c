// Shayanna Gatchalian & John Paul Tran

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // allocate memory using malloc()
    char *line = (char *) malloc(sizeof(char) * 21); // Allocate space for a string of 20 chars + NULL
    printf("Enter a string:\n");
    scanf("%s", line);
    printf("Entered string: %s\n", line);
    // forget to free it (allocated memory using malloc()) before exiting
    return 0;
}