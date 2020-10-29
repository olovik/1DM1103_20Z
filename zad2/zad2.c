#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>





int main(int argc, char*argv[])
{
    int h;
    int w;
    int p;
    int q; 
    
    FILE *fin;
    fin= fopen("A.txt", "r"); //macierz
    fscanf(fin, "%d", &h);
    fscanf(fin, "%d", &w);
    float macierz[h][w];
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            fscanf(fin, "%f", &macierz[i][j]);
        }
    }

    fin= fopen("x.txt", "r"); //wektor
    
    fscanf(fin, "%d", &p);
    fscanf(fin, "%d", &q);
    float wektor[p]; 
    for(int i=0; i<p; i++)
        {
            fscanf(fin, "%f", &wektor[i]);
        }
  //  for(int i=0; i<h;i++)
    //    {
      //      for(int j=0;j<q;j++)
 //               wynik[i][j]=0;
   //     }
   printf("(%d) [", h);  
    for(int i=0;i<h; i++)
        {
            float suma = 0;
            for(int j=0;j<w;j++)
            {
                suma += macierz[i][j]*wektor[j];
            }
            printf("%1.1f ", suma);
        }
        printf("]\n");
        return 0;
}