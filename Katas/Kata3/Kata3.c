#include <stdio.h>
#include <string.h>

int judgeCircle(char* moves) {
    int y=0;
    int x=0;
    for (int i=0;i < strlen(moves);i++){
        if (moves[i]=='U'){
            y++;
        }else if (moves[i]=='D'){
            y--;
        }else if (moves[i]=='R'){
            x++;
        }else if (moves[i]=='L'){
            x--;
        }
        //printf("y = %d,x = %d,%c\n",y,x,moves[i] );
    }
    if (x==0 && y==0){
      return 1;
    }
    return 0;
}

int main (){
  char *moves = "UDRL";
  judgeCircle(moves);
  return 0;
}
