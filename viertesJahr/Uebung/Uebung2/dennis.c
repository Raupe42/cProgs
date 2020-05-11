#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int lauf=1;
    double erg=0;
    printf ("--%i--\n", argc);
    if(argc>2)
    {
      //  erg=atof(argv[argc-2])-atof(argv[argc-1]);
      //  printf ("argc --%f-- \n",erg);

        for (lauf;lauf<argc;lauf++)
        {
            if(lauf==1)
            {
                erg=atof(argv[lauf]);
                printf("--%f--\n",erg);
            }
            else
            {
                erg=erg-atof(argv[lauf]);
                 printf("--%f--\n",erg);
            }
            
        }
        
    }
    else
    {
        
        printf ("hure \n");
            
        
    }
    
    return 0;
}