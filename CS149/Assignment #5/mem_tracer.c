// Shayanna Gatchalian & John Paul Tran
// Assignment #5
// 4.19.2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>

// TRACE_NODE_STRUCT is a linked list of
// pointers to function identifiers
// TRACE_TOP is the head of the list is the top of the stack
struct TRACE_NODE_STRUCT {
  char* functionID;                // ptr to function identifier (a function name)
  int index;                       // index of node
  struct TRACE_NODE_STRUCT* next;  // ptr to next frama
};
typedef struct TRACE_NODE_STRUCT TRACE_NODE;
static TRACE_NODE* TRACE_TOP = NULL;       // ptr to the top of the stack

/* --------------------------------*/
/* function PUSH_TRACE */
/* The purpose of this stack is to trace the sequence of function calls,
just like the stack in your computer would do. The "global" string denotes the start of the 
function call trace */
void PUSH_TRACE(char* p)          // push p on the stack
{
  TRACE_NODE* tnode;
  static char glob[]="global";

  if (TRACE_TOP==NULL) {

    // initialize the stack with "global" identifier
    TRACE_TOP=(TRACE_NODE*) malloc(sizeof(TRACE_NODE));

    // no recovery needed if allocation failed, this is only
    // used in debugging, not in production
    if (TRACE_TOP==NULL) {
      printf("PUSH_TRACE: memory allocation error\n");
      exit(1);
    }

    TRACE_TOP->functionID = glob;
    TRACE_TOP->next=NULL;
  }

  // create the node for p
  tnode = (TRACE_NODE*) malloc(sizeof(TRACE_NODE));

  // no recovery needed if allocation failed, this is only
  // used in debugging, not in production
  if (tnode==NULL) {
    printf("PUSH_TRACE: memory allocation error\n");
    exit(1);
  }

  tnode->functionID=p;
  tnode->next = TRACE_TOP;  // insert fnode as the first in the list
  TRACE_TOP=tnode;          // point TRACE_TOP to the first node

}/*end PUSH_TRACE*/

/* --------------------------------*/
/* function POP_TRACE */
/* Pop a function call from the stack */
void POP_TRACE()    // remove the op of the stack
{
  TRACE_NODE* tnode;
  tnode = TRACE_TOP;
  TRACE_TOP = tnode->next;
  free(tnode);

}/*end POP_TRACE*/



/* ---------------------------------------------- */
/* function PRINT_TRACE prints out the sequence of function calls that are on the stack at this instance */
/* For example, it returns a string that looks like: global:funcA:funcB:funcC. */
/* Printing the function call sequence the other way around is also ok: funcC:funcB:funcA:global */
char* PRINT_TRACE()
{
  int depth = 50; //A max of 50 levels in the stack will be combined in a string for printing out.
  int i, length, j;
  TRACE_NODE* tnode;
  static char buf[100];

  if (TRACE_TOP==NULL) {     // stack not initialized yet, so we are
    strcpy(buf,"global");   // still in the `global' area
    return buf;
  }

  /* peek at the depth(50) top entries on the stack, but do not
     go over 100 chars and do not go over the bottom of the
     stack */

  sprintf(buf,"%s",TRACE_TOP->functionID);
  length = strlen(buf);                  // length of the string so far
  for(i=1, tnode=TRACE_TOP->next;
                        tnode!=NULL && i < depth;
                                  i++,tnode=tnode->next) {
    j = strlen(tnode->functionID);             // length of what we want to add
    if (length+j+1 < 100) {              // total length is ok
      sprintf(buf+length,":%s",tnode->functionID);
      length += j+1;
    }else                                // it would be too long
      break;
  }
  return buf;
} /*end PRINT_TRACE*/

// -----------------------------------------
// function REALLOC calls realloc
// TODO REALLOC should also print info about memory usage.
// For instance, example of print out:
// "File tracemem.c, line X, function F reallocated the memory segment at address A to a new size S"
// Information about the function F should be printed by printing the stack (use PRINT_TRACE)
void* REALLOC(void* p,int t,char* file,int line)
{
  // given
	p = realloc(p,t);
  
  // our code
  printf("File %s, line %d, function %s reallocated the memory segment at address %p to a new size %d\n", file, line, PRINT_TRACE(), p, t);
	return p;
}

// -------------------------------------------
// function MALLOC calls malloc
// TODO MALLOC should also print info about memory usage.
// For instance, example of print out:
// "File tracemem.c, line X, function F allocated new memory segment at address A to size S"
// Information about the function F should be printed by printing the stack (use PRINT_TRACE)
void* MALLOC(int t,char* file,int line)
{
  // given
	void* p;
	p = malloc(t);

  // our code
  printf("File %s, line %d, function %s allocated new memory segment at address %p to size %d\n", file, line, PRINT_TRACE(), p, t);
	return p;
}

// ----------------------------------------------
// function FREE calls free
// TODO FREE should also print info about memory usage.
// For instance, example of print out:
// "File tracemem.c, line X, function F deallocated the memory segment at address A"
// Information about the function F should be printed by printing the stack (use PRINT_TRACE)
void FREE(void* p,char* file,int line)
{
  // given
	free(p);

  // our code
  printf("File %s, line %d, function %s deallocated the memory segment at address %p\n", file, line, PRINT_TRACE(), p);
}

#define realloc(a,b) REALLOC(a,b,__FILE__,__LINE__)
#define malloc(a) MALLOC(a,__FILE__,__LINE__)
#define free(a) FREE(a,__FILE__,__LINE__)


// -----------------------------------------
// function add_column will add an extra column to a 2d array of ints.
// This function is intended to demonstrate how memory usage tracing of realloc is done
// Returns the number of new columns (updated)
int add_column(int** array,int rows,int columns)
{
	PUSH_TRACE("add_column");
	int i;

	for(i=0; i<rows; i++) {
	 array[i]=(int*) realloc(array[i],sizeof(int)*(columns+1));
	 array[i][columns]=10*i+columns;
	}
	POP_TRACE();
        return (columns+1);
}// end add_column


// // ------------------------------------------
// // function make_extend_array
// // Example of how the memory trace is done
// // This function is intended to demonstrate how memory usage tracing of malloc and free is done
// void make_extend_array()
// {
//        PUSH_TRACE("make_extend_array");
// 	int i, j;
//         int **array;
//         int ROW = 4;
//         int COL = 3;

//         //make array
// 	array = (int**) malloc(sizeof(int*)*4);  // 4 rows
// 	for(i=0; i<ROW; i++) {
// 	 array[i]=(int*) malloc(sizeof(int)*3);  // 3 columns
// 	 for(j=0; j<COL; j++)
// 	  array[i][j]=10*i+j;
// 	}

//         //display array
// 	for(i=0; i<ROW; i++)
// 	 for(j=0; j<COL; j++)
// 	  printf("array[%d][%d]=%d\n",i,j,array[i][j]);

// 	// and a new column
// 	int NEWCOL = add_column(array,ROW,COL);

// 	// now display the array again
//         for(i=0; i<ROW; i++)
// 	 for(j=0; j<NEWCOL; j++)
// 	  printf("array[%d][%d]=%d\n",i,j,array[i][j]);

// 	 //now deallocate it
// 	 for(i=0; i<ROW; i++)
// 		 free((void*)array[i]);
// 	 free((void*)array);

// 	 POP_TRACE();
//          return;
// }//end make_extend_array

// our own defined functions (based on make_extend_array)
#define ROW 3
#define COLUMN 4

// function to create array memory using malloc and initial its size 
void createArray(char ***arr, int row, int col) 
{
  PUSH_TRACE("createArray");                              
  char **array;                                           // size = 3 x 4 (predefined)
  array = (char **) malloc(sizeof(char *) * row);         // initialize rows
  for (int i = 0; i < row; i++)
  {
      array[i] = (char *) malloc(sizeof(char) * col);     // initialize columns
  }
  POP_TRACE();                                          
  *arr = array;                                           // assign array to arr pointer
  POP_TRACE();                                          
}

// function to print the array
void printArray(char **arr, int row) 
{
  PUSH_TRACE("printArray");                              
  for (int i = 0; i < row; i++)                           // for each row...
  {
    printf("array[%d] = %s\n", i, arr[i]);                // ...print its contents
  }
  POP_TRACE();                                     
}

// add node to linked list
void addNode(TRACE_NODE **head, TRACE_NODE *node)
{
  PUSH_TRACE("addNode");
  if (*head == NULL)                                      // if head is null...
  {
    *head = node;                                         // ...new node becomes head
  }
  else                                                    // else, iterate through linked list...
  { 
      TRACE_NODE *current = *head;
      while (current->next != NULL) current = current->next; 
      current->next = node;                               // ...and insert new node at end of linked list
  }
  POP_TRACE();
}

// create a new node and store each line from file
void createNode(TRACE_NODE **head, char *line, int index) 
{
  PUSH_TRACE("createNode");                               
  TRACE_NODE *node = (TRACE_NODE *) malloc(sizeof(TRACE_NODE));
  node->functionID = (char *) malloc(strlen(line) + 1);
  strncpy(node->functionID, line, strlen(line) + 1);
  node->index = index;
  node->next = NULL;
  POP_TRACE();     
  addNode(head, node);                                       
}

// recursively prints all nodes in linked list
void printNode(TRACE_NODE *node) 
{
    PUSH_TRACE("printNode");                                // print all except for last node in linked list
    if (node != NULL) {                                     // if node is detected...
        printf("array[%d] = %s\n", node->index, node->functionID); // ... print node
        printNode(node->next);                             // recurse (until end of linked list have been reached)
    }
    POP_TRACE();                                            
}

// delete nodes in linked list
void deallocateList(TRACE_NODE **head) 
{
    PUSH_TRACE("deallocateList");
    TRACE_NODE *current = *head;                            // node to delete
    while (current != NULL)                                 // while current node is not NULL
    {                                                     
        TRACE_NODE *temp = current->next;                   // keep track of next node
        free(current->functionID);                        
        free(current);                                      // delete current node
        current = temp;                                     // set next node as current node
    }
    POP_TRACE();
}

// main function
int main(int argc, char *argv[])
{
  // given
  PUSH_TRACE("main");
  
  // create out file using dup2
  int fdout = open("memtrace.out", O_RDWR | O_CREAT | O_APPEND, 0777);
  dup2(fdout, 1);
 
  char **arr;                                               // array to initialize
  createArray(&arr, ROW, COLUMN);                           // create memory array through malloc with size ROW x COLUMN

  // variables used to read file
  ssize_t read;
  size_t length;
  char *line = NULL;

  // check for correct input when running program
  if (argc != 2) 
  {
    printf("Please use ./mem_tracer cmdfile to run code\n");//error message
    return -1;
  }

  char * cmdfile = argv[1];                                 // variable for cmdfile

  // read from cmdfile
  FILE * fp = fopen(cmdfile, "r");
  if (fp == NULL) 
  {
    printf("Error: File is null\n");
    exit(1);
  }

  // fill in array with lines from file
  int row = 0;                                              // row iterator variable
  while ((read = getline(&line, &length, fp)) >= 0) 
  {
    row++;                                                  // increment row when line is read
    
    if (line[strlen(line) - 1] == '\n')                     // replace newline with null char
    {
      line[strlen(line) - 1] = '\0';
    }

    int col = strlen(line) + 1;                             // retrieve column length

    if (ROW < row)                                          // if condition for row expansion...
    { 
      arr = (char **) realloc(arr, sizeof(char *) * row);   // ... reallocate rows...
      arr[row - 1] = (char *) malloc(sizeof(char) * col);   // ... and allocate columns
    }
    if (COLUMN < col)                                       // if condition for column expansion...
    {
      arr[row - 1] = (char *) realloc(arr[row - 1], sizeof(char) * col); // ... reallocate columns
    }

    strncpy(arr[row - 1], line, col);                       // copy current line to array
  }

  fclose(fp);                                               // close file
  if (line) 
  {
    free(line);                                             // deallocate line
  }

  printArray(arr, row);                                     // print out array
  
  TRACE_NODE *head = NULL;                                  // make linked list (start with head node)
  for (int i = 0; i < row; i++)
  {
      createNode(&head, arr[i], i);                         // create node and add to linked list with corresponding command from array
  }

  printNode(head);                                          // print linked list
  deallocateList(&head);                                    // deallocate list

  for (int i = 0; i < row; i++)
  {
    free(arr[i]);                                           // deallocate rows
  }
  free(arr);                                                // deallocate columns

  close(fdout);                                             // close the file

  //given
  POP_TRACE();
  return(0);
}