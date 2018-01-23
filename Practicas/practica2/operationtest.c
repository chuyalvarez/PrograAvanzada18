#include <stdio.h>
#include "operation.h"

void printTestMessage(int condition, char *messagePassed, char *messageFailed){
  if (condition){
    printf(messagePassed);
  }else{
    printf(messageFailed);
  }
}

int testAddition(){
  int a = 36;
  int b = 2647;

  int result = add(a,b);
  int expected = a + b;

  return result==expected;
}

int testSubstraction(){
  int a = 36;
  int b = 2647;

  int result = substract(a,b);
  int expected = a - b;

  return result==expected;
}


int main (){
  printTestMessage(testAddition(),"add test passed\n","add test failed\n");
  printTestMessage(testSubstraction(),"substract test passed\n","substract test failed\n");
  return 0;
}
