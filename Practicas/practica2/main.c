#include <stdio.h>
#include "operation.h"
#include "messages.h"
#include <string.h>

#define LANG ESP;

typedef struct {
char *operationName;
int(operation *) (int, int);
} operation;

int main() {
  char operation[100];
  int operatorOne,operatorTwo;
  char *lang;
  char **messages;

  if(!strcmp(lang,"ENG")){
    *messages=*message_ENG;
  }else if (!strcmp(lang,"ESP"){
    *messages=*message_ESP;
  }

  printf(messages[0]);
  scanf("%s",operation);
  scanf("%d %d",&operatorOne,&operatorTwo);

  if(!strcmp(operation,"add")){
    printf("%s %d\n",messages[1], add(operatorOne,operatorTwo) );
  }else if(!strcmp(operation,"substract")){
    printf("%s %d\n",messages[1], substract(operatorOne,operatorTwo) );
  }

  return 0;
}
