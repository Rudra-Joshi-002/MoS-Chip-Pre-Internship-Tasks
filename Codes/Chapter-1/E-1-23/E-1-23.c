//Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
//handle quoted strings and character constants properly. C comments don't nest.

#include<stdio.h>
#include<stdlib.h>

#define NORMAL 0
#define SEEN_SLASH 1
#define IN_LINE_COMMENT 2
#define IN_BLOCK_COMMENT 3
#define IN_STRING 4
#define IN_CHARCTER 5

int state=NORMAL; //to describe state of line being read

int main(int argc, char *argv[])
{

    FILE *fp_ip, *fp_op; //define file pointers for input and output
    int c,next_char;

    if(argc!=3)
    {
        printf("Wrong Number of Arguments 1st go and learn how to give it\n");

        return 1;
    }
    
    //try to open input file with comments in read mode
    
    fp_ip= fopen(argv[1],"r");

    if(fp_ip==NULL)
    {
        printf("Error In Opening input file terminating the program now\n");
        return 1;
    }
    
    //try to open output file with write mode
    
    fp_op=fopen(argv[2],"w");

    if(fp_op==NULL)
    {
        printf("Error In Opening output file terminating the program now\n");
        return 1;
    }

    while((c=fgetc(fp_ip))!=EOF)
    {
        //CHECK FOR OCCURENCE OF '//'
        if(c=='/' && state==NORMAL)
        {
            next_char=fgetc(fp_ip);

            if(next_char=='/')
            {
                state=IN_LINE_COMMENT;
                
                //keep on moving until new line character is obtained for a inline comment
                while((c=fgetc(fp_ip))!='\n');
               
               //when end of inline comment seen make a new line in op file
               fputc(c,fp_op);


            }

            else if(next_char=='*')
            {
                state=IN_BLOCK_COMMENT;

                //now transverse until */ is not found in the i/p file
                
                while(c!='*' && next_char!='/')
                {
                    while(((c=fgetc(fp_ip)!='*')));

                    next_char=fgetc(fp_ip);
                }

 
                c=fgetc(fp_ip);

                fputc(c,fp_op);

            }

           state=NORMAL; 
        }

        //CHECK FOR OCCURNCE OF STRINGS " "

        else if(c=='"' && state==NORMAL)
        {   
            state=IN_STRING;
            
            fputc(c,fp_op); //put first " occurence in o/p file
            //now continue putting contents in double quotes until you see'em again
            
            while((c=fgetc(fp_ip))!='"')
                fputc(c,fp_op);
            
            fputc(c,fp_op); //to put the ending double quote in o/p file

            state=NORMAL;
        }

        //CHECK FOR OCCURENCE OF CHARACTER LITERALS ' '
        
        else if(c=='\'' && state==NORMAL)
        {
            state=IN_CHARCTER;

            fputc(c,fp_op); // put 1st ' in o/p file

            //now continue putting content in single quote until you see another one again

            while((c=fgetc(fp_ip))!='\'')
                fputc(c,fp_op);

            fputc(c,fp_op); //to putb the ending single quote in o/p file
            
            state=NORMAL;
        }

        //if none of ladder conditions are true and state==normal simply put c in o/p file

        else if(state==NORMAL)
        {
            fputc(c,fp_op);

        }
            
    }

    //finally at occurence of EOF put that in o/p file as well
    
    fputc(c,fp_op);

    
    //file closing staments necessary book keeping required before that bear that in mind!!!!!
    fclose(fp_ip);
    fclose(fp_op);

    printf("\nInput file: %s modified successfully and stored in Output file: %s\n",argv[1],argv[2]);

    return 0;

}

