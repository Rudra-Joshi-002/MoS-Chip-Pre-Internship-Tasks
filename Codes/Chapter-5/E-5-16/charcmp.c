/*
This file contains the definition of charcmp.
It compares two strings, checking global flags
for fold (case-insensitivity) and directory (letters/numbers/blanks only) options.
*/

#include <ctype.h>


//Get the global flags defined in main.c 

extern int fold;
extern int directory;

int charcmp(void *p1, void *p2)
{   
    //we cast the void* to char * so that we can use them
    char *s1 = (char *)p1;
    char *s2 = (char *)p2;
    char c1, c2; // To hold characters for comparison

    do {
        
        //if directory flag is set
        
        if (directory) {
            
            // Skip over any non-directory characters in s1
            
            while (*s1 != '\0' && !isalnum(*s1) && *s1 != ' ') {
                s1++;
            }
            
            // Skip over any non-directory characters in s2
            
            while (*s2 != '\0' && !isalnum(*s2) && *s2 != ' ') {
                s2++;
            }
        }
        
        //pass the directory chars found after parsing the loop in c1 &c2
        
        c1 = *s1;
        c2 = *s2;

        //if fold flag is set
        
        if (fold) {
            
            c1 = tolower(c1);
            c2 = tolower(c2);
        
        }
        
        // If characters are different, stop comparision and return the difference.
        
        if (c1 != c2) {
            
            return c1 - c2; // Return the difference
        
        }
        
        // If they were equal, then both c contains '\0', use that for equal strings
        if (c1 == '\0') {
            
            return 0;
        }


        // If characters were equal but not /0, advance pointers
        
        s1++;
        s2++;

    } while (1); // Loop continues until a return
}
