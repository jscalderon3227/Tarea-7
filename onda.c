#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Mètodo que copia un vector en otro

void copy(float *u_past, float *u_new, int n_points)
 {
   int i;
   for(i=0;i<n_points;i++)
     {
       u_new[i]=u_past[i];
     }
 }

// Mètodo que crea el espacio en memoria

float * get_memory(int n_points)
 {
    float * x;
    if(!(x = malloc(sizeof(float) * n_points)))
      {
        printf("problem with memory allocation");
        exit(1);
      }
    return x;
 }

//Mètodo principal

int main()
{

  return 0;
}
