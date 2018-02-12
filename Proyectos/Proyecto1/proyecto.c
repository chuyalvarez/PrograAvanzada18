#include <stdio.h>
#include <stdlib.h>

int brickArrangement(int n,int m, int bricks[][m]){
  int bricknumber=1;
  int **result=(int**)malloc(n*m*sizeof(int));

  for(int i=0;i<m;i++){
      if(bricks[1][i]==bricks[1][i+1]){
        result[1][i]=bricknumber;
        result[2][i]=bricknumber;
        bricknumber++;
      }
      if(bricks[1][i]!=bricks[1][i+1]){
        result[1][i]=bricknumber;
        result[1][i+1]=bricknumber;
        bricknumber++;
        result[2][i]=bricknumber;
        result[2][i+1]=bricknumber;
        bricknumber++;
        i++;
      }
  }
  return int;
}

int main(int argc, char const *argv[]) {
  int n=2;
  int m=4;
  int bricks[2][4]={{1,1,3,3},{2,2,4,4}};

  int res = brickArrangement(n,m,bricks);


  return 0;
}
