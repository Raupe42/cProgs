#include <stdio.h>
#include <stdlib.h>

double main (int argc, char * argv [])
{
    double retVal;
    if (argc < 3)
    {
        printf("Layer 8 error!\n");
        return -1.0;
    }
    retVal = atof(argv[1]) / atof(argv[2]); //atof (aus stdlib): konvertierung char * zu float
    printf("= %g", retVal);
    return retVal;
}