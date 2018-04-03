#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char input[1015];
  char *words;
  int lines;
  FILE *testFile;
  testFile = fopen("input.txt", "r");

  if (testFile) {
    words = fgets(input, sizeof(input), testFile);
    lines = atoi(words);

    for (int i = 0; i < lines; i++){
      char  *exits[100];
      words = fgets(input, sizeof(input), testFile);
      words = strtok(words, "\n");

      int j=0;
      int count = 0;
      exits[j] = strtok(words," ");
      while(exits[j]!=NULL)
      {
        count++;
        exits[++j] = strtok(NULL," ");
      }

      if(count==1){
        printf("%s",exits[0]);
      }else if (count>1){
        for(int k = count-1; k>=0; k--){
          printf("%s ", exits[k]);
        }
      }else{
        printf("inavlid input");
      }
      printf("\n");

    }

  }
}
