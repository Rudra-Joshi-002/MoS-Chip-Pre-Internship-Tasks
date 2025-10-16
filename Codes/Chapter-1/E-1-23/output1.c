


#include<stdio.h>
#include<stdlib.h>
typedef enum{ 
  NORMAL,
  IN_LINE_COMMENT,
  IN_BLOCK_COMMENT,
  IN_STRING,
  IN_CHARCTER,
}State; 

int main(int argc, char *argv[])
{

    FILE *fp_ip, *fp_op; 
    int c,next_char;
    State state=NORMAL;

    if(argc!=3)
    {
        printf("Wrong Number of Arguments 1st go and learn how to give it\n");

        return 1;
    }
    
    
    
    fp_ip= fopen(argv[1],"r");

    if(fp_ip==NULL)
    {
        printf("Error In Opening input file terminating the program now\n");
        return 1;
    }

    
    
    fp_op=fopen(argv[2],"w");

    if(fp_op==NULL)
    {
        printf("Error In Opening output file terminating the program now\n");
        return 1;
    }

    while((c=fgetc(fp_ip))!=EOF)
    {
        

        if(state==NORMAL)
        {   
            printf("\nInside if\n");
            
            if(c=='/')
            {   
               printf("\n/ encountered\n");

               
               
               next_char=fgetc(fp_ip);
               
               if(next_char=='/')
               {
                   state=IN_LINE_COMMENT;
                   printf("\nState=Inline Comment\n");
               }

               else if(next_char=='*')
               {
                   state=IN_BLOCK_COMMENT;
                   printf("\nState=In Block Comment\n");
               }

               else 
               {    
                    printf("\nIt was a simple /\n"); 
                    fputc(c,fp_op);
                    ungetc(next_char,fp_ip);
               }


            }
            
            else if(c=='"')
            {
                printf("\nDouble Quotes Encountered Changing State\n");
                state=IN_STRING;
                fputc(c,fp_op);
            }

            else if(c=='\'')
            {
                printf("\nSingle Quotes Encountered Chaning the State /\n");
                state=IN_CHARCTER;
                fputc(c,fp_op);
            }
            //if state is normal and none of the character condition matches then
            else
            {   
                printf("\nState=Normal and No Special Condition Matches\n");
                fputc(c,fp_op);
            }

            printf("\nExiting IF\n");
        }

        else{
            
            printf("\nInside Else\n");
            //placing switch case statements to meet fsm type requirments
            switch (state)
            {
                //if state is normal then simply write to o/p file
                case NORMAL:
                    printf("\nInside NORMAL Case\n");
                    fputc(c,fp_op);
                    break;
            
                //if state is IN_LINE_COMMENT 
                case IN_LINE_COMMENT:
                    
                    printf("\nInside IN_LINE_COMMENT\n");
                    //loop while \n or EOF is not found while being in INLINE_COMMENT
                    while(c!='\n'&& c!=EOF)
                    {
                        c=fgetc(fp_ip);
                    }

                    if(c=='\n')
                    {
                        fputc(c,fp_op);
                        state=NORMAL;
                    }
                    else
                    {
                        printf("\nEOF Encountered\n");
                        fclose(fp_ip);
                        fclose(fp_op);
                        return 0;
                    }

                    break; 
                //IF STATE IS IN_BLOCK COMMENT
                case IN_BLOCK_COMMENT:
                    
                    printf("\nInside IN_BLOCK_COMMENT\n");
                    //loop while */ are not found
                    
                    ungetc(c,fp_ip);

                    while((c=fgetc(fp_ip))!=EOF)
                    {
                        if(c=='*')
                        {
                            next_char=fgetc(fp_ip);

                            if(next_char=='/')
                                break;
                            else
                                ungetc(next_char,fp_ip);
                        }
                    }

                    if(c=='*' && next_char=='/')
                    {
                        state=NORMAL;
                    }
                    else
                    {
                        printf("\nEOF encountered\n");
                        fclose(fp_ip);
                        fclose(fp_op);
                        return 0;
                    }

                    break;
                
                 //if state is IN_STRING
                case IN_STRING:

                    printf("\nInside IN_STRING\n");

                    //while you find next set of double quotes

                    while(c!='"' && c!=EOF)
                    {
                        fputc(c,fp_op);
                        c=fgetc(fp_ip);
                    }

                    if(c=='"')
                    {
                        fputc(c,fp_op);
                        state=NORMAL;
                    }
                    else
                    {
                        printf("\nEOF Encountered\n");
                        fclose(fp_ip);
                        fclose(fp_op);
                        return 0;
                    }
                    
                    break;

                //if state is IN_CHARACTER
                case IN_CHARCTER:

                    //while find next single quote
                    printf("\nInside IN_CHARCTER\n");

                    while(c!='\'' && c!=EOF)
                    {
                        fputc(c,fp_op);
                        c=fgetc(fp_ip);
                    }

                    if(c=='\'')
                    {
                        fputc(c,fp_op);
                        state=NORMAL;
                    }
                    else
                    {
                        printf("\nEOF Encountered\n");
                        fclose(fp_ip);
                        fclose(fp_op);
                        return 0;
                    } 

                    break;
                    
           }

            printf("\nExiting Else\n");

        }

    }

    //file closing staments necessary book keeping required before that bear that in mind!!!!!
    fclose(fp_ip);
    fclose(fp_op);

    printf("\nInput file: %s modified successfully and stored in Output file: %s\n",argv[1],argv[2]);

    return 0;

}

