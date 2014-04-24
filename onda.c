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
  //Declaraciòn de constantes
  int n_points=1000;
  float xmin=0.0;
  float xmax=1.0;
  float deltax=(xmax-xmin)/n_points;
  float deltat=0.005;
  
  //Declaraciòn de arreglos
  float *x;
  float *u_initial;
  float *u_present;
  float *u_past;
  float *u_future;

  //Condiciones iniciales y de frontera
  x=get_memory(n_points);
  u_initial=get_memory(n_points);
  u_past=get_memory(n_points);
  u_present=get_memory(n_points);
  u_future=get_memory(n_points);

  x[0]=0.0;

  u_initial[0]=0.0;
  u_initial[n_points-1]=0.0;

  u_past[0]=0.0;
  u_past[n_points-1]=0.0;

  u_present[0]=0.0;
  u_present[n_points-1]=0.0;

  u_future[0]=0.0;
  u_future[n_points-1]=0.0;


  return 0;
}
