#include <assert.h>
#include <stdio.h>
#include "operation.h"

int add(int a, int b){
  long c =  a + b;

  assert(c< 2147483647 && c> -2147483647);
  return a+b;
}

int substract(int a, int b){
  long c =  a - b;

  assert(c< 2147483647 && c> -2147483647);
  return a-b;
}
