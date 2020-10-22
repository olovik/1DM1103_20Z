#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("Wartość %f do kwadratu to %f\n", atof(argv[1]), atof(argv[1])*atof(argv[1]));
             
    
    return 0;
}