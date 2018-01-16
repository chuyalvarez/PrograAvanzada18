#include <stdlib.h>
#include <stdio.h>

int main() {
  int a=4;
  int j;
  int *p;
  float f = 7.5;
  long max= 2147483647;

  int b= a+f;
  float c = a*f;

  int arreglo[5] = {0,2};

  long int d = max * max;

  p=arreglo;
  for(int i=0;i<5;i++){
    *p=67;
    p++;
  }

  *(arreglo+1)=250;
  p = &a;
  *p = 7;
  p++;
  *p=8;

  p=arreglo;
  for(int i=0;i<5;i++){
    *p=67;
    p++;
  }

  printf("p= %p,a= %d,j= %d, b= %d,d= %ld\n",p,a,j,b,d );
  printf("f= %f,c=%f,arreglo[1]= %d\n",f,c,arreglo[1] );
  return 0;
}
