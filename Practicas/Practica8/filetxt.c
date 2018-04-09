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


int main() {

  char *fileName = "output.txt";
  FILE output;
  output=fopen(fileName,"a");
  printDebug("output = %p\n",output);
  do{
    character = fgetc(stdin);
    fputc(character,output);
  }while(feof());

  fclose(output);
  /* code */
  return 0;
  
}
