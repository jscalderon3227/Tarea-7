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
  int i;
  int j;
  int n_points=1000;
  float xmin=0.0;
  float xmax=1.0;
  float deltax=(xmax-xmin)/n_points;
  float deltat=0.005;
  float c=1.0;
  float r=c*deltat/deltax;

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
  
  //Resolvemos la condicion inicial
  for(i=1;i<n_points;i++)
    {
      x[i]=x[i-1]+deltax;
      u_initial[i]=exp(((x[i]-0.3)*(x[i]-0.3))/0.01);
    }

  //Resolvemos el primer paso pues es necesario
  for(i=1;n_points-1;i++)
    {
      u_future[i]=u_initial[i]+(pow(r,2)/2.0)*(u_initial[i+1]-2.0*u_initial[i]+u_initial[i-1]);
    }
  //Refrescamos los vectores de la funciòn para variarla en el tiempo
  copy(u_initial,u_past);
  copy(u_future,u_present);
  return 0;
}

