

#include<stdio.h>

#define MAXLINE 100

int getLine(char [],int);

int main()
{
    int last_blank_tab,col,line_len,col_limit;

    char ip[MAXLINE];

    last_blank_tab=col=line_len=0;

    col_limit=30; 

     while((line_len=(getLine(ip,MAXLINE)))>0)
     {

        printf("\nThe Entered Line has %d Characters\n",line_len);

        printf("\nNow replacing the entered line with appropriate folded or warped lines gives:\n\n");

        int i=0;

        while(col<line_len)
        {
            for(i=col ; i<col+col_limit && i<line_len ;i++)
            {
                if(ip[i]==' ' || ip[i]=='\t')
                    last_blank_tab=i;
            }

            if(last_blank_tab!=0)
            {
                

                int j=col;

                while(ip[j]==' ' || ip[j]=='\t')
                    j++;

                
                
                
                while(j<last_blank_tab)
                    putchar(ip[j++]);

                
                col=last_blank_tab+1;
                last_blank_tab=0;

            }
            
            else
            {
                for(i=col ; i<col+col_limit && i<line_len ; i++)
                    putchar(ip[i]);

                col=i;
            }

            putchar('\n');

        
        }

        break;

     }

     printf("\nThank you that's all this program has already wasted maybe 6hrs of my day but yes at last proper output is there");

    
    return 0;
}



int getLine(char ip[],int lim)
{
    int i,c;

    for(i=0; i<lim-1 && (c=(getchar()))!= EOF && c!='\n' ; i++)
    {
        ip[i]=c;
    }

    if(c=='\n') 
    {
        ip[i++]='\n';
        ip[i]='\0';
        return i;
    }

    else 
    {
        ip[i]='\0';
    }

    return i;

}
ÿ