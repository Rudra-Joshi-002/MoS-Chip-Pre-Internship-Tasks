/*

Since the program for sorting lines given in the book is divided into mutliple functions
I've decided to split the programs across the files and all the necessary decelartions
and variable definations are provided here

*/

#define MAXLINES 5000 //define max number of lines that can be accepted as input
#define MAXLEN 1000 //define max length of each line that can be accepted as input

int readlines(char *lineptr[], int nlines, char *storage ,int storage_size);

void writelines(char *lineptr[], int nlines);

int charcmp(void *p1 , void *p2); //to handle all string comparision

void qsort(void *lineptr[], int left, int right, int (*comp) (void * ,void *)); //delcraing genric qsort prototype

int numcmp( void *s1 , void *s2); //numeric comparision function to handle numeric comaprision
