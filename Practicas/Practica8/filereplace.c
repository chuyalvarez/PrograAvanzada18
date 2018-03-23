#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define printDebug(...) do{\
  char *isDebug; \
  isDebug = getenv("DEBUG"); \
  if(isDebug != NULL && !strcasecmp(isDebug, "y")){ \
    fprintf(stderr, __VA_ARGS__); \
  } \
}while(0)


int main() {
  char *fileName = "input.txt";
  FILE *input;
  char *search = "mundo";
  char *replace ="MUNDOMUNDO";
  char *word[255];
  int character;
  long searchPos;

  while(1){
    fscanf(input,"%s",word);
    if feof(input){
      break;
    }
    if (strcmp(word,search)==0){
      printDebug ("Found %s\n",word);
      fseek(input,-1*strlen(search));
      searchPos = ftell(input);
      printDebug("searchPos %ld\n",searchPos);
      while(ftell(input)!= searchPos){
        character = fgetc(input);
        fputc(character,stdin);
      }
    }
  }
}
