#include <stdio.h>
#include "proyecto.h"

void printTestMessage(int condition, char *messagePassed, char *messageFailed){
  if (condition){
    printf(messagePassed);
  }else{
    printf(messageFailed);
  }
}

int testAddition(){
  int m = 2;
  int n = 4;


  int bricks[2][4]={{1,1,3,3},{2,2,4,4}};

  int res = brickArrangement(n,m,bricks);

  return result==1;
}



int main (){
  printTestMessage(testWall(),"brick test passed\n","brick test failed\n");
  return 0;
}
