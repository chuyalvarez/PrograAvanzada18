#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define printDebug(...) do{\
  char *isDebug; \
  isDebug = getenv("DEBUG"); \
  if(isDebug != NULL && !strcasecmp(isDebug, "y")){ \
    fprintf(stderr, __VA_ARGS__); \
  } \
}while(0)


int main(){
  int character;

  while(!feof(stdin)){
    character = fgetc(stdin);
    fputc(character, stdout);
    printDebug( "Error character %c \n", character);

  }
  return 0;
}
