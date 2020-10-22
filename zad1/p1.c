#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    float s=0;
    if(argc==1)
    {
        printf("Nie podano ani jednej liczby\n");
    }
        else
        {
            
            for(int i = 1; i<argc; i++)
            {
                 s += atof(argv[i]);
            }
        printf("%f\n",s);
        }
             
    
    return 0;
}
