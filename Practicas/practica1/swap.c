#include <stdio.h>

int swap_no(int a,int b){
  int t;
  t = a;
  a = b;
  b = t;
}

int swap(int *a,int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int main() {
  int  j=27,k=34;

  swap_no(j,k);
  printf("j= %d,k = %d\n",j,k );
  swap(&j,&k);
  printf("j= %d,k = %d\n",j,k );

  return 0;
}
