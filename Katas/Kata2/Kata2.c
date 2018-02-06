#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lastrepetition(int i,int pSize,char* s){
  int c=0;
  int last=0;
  int repeated=1;
  for(int j=i;j<pSize;j++){
    c = s[j];
    if (last==c){
      repeated++;
    }else{
      if(repeated>2){
        return 0;
      }
      repeated=1;
    }
    last=c;
  }
  return 1;
}

int strongPasswordChecker(char* s) {

int pSize = strlen(s);
int upper = 1;
int lower = 1;
int digit = 1;
int c=0;
int changes = 0;
int last = 0;
int repeated = 1;
int buffer = 0;
int nbuff = 0;
int replacebuff = 0;

if (pSize < 3){
  return 6-pSize;
}

if(pSize>20){
  changes += pSize-20;
  printf("excess change= %d\n",pSize-20);
  buffer = pSize-20;
}


for (int i = 0;i < pSize;i++){
  c = s[i];
  if(c > 64 && c < 91){
    upper = 0;
  }
  if(c > 96 && c < 123){
    lower = 0;
  }
  if(c > 47 && c < 58){
    digit = 0;
  }

  if (last==c){
    repeated++;
  }else{

    if(repeated>2){
      if(repeated-buffer>2){
        if(lastrepetition(i,pSize,s)){
          repeated-=buffer;
          buffer=0;
        }else if (repeated%3==0&&repeated>4){
          repeated-=1;
          buffer-=1;
        }
        changes+=repeated/3;
        printf("repetition change= %d\n",repeated/3);
        replacebuff+=repeated/3;

      }else if(repeated-buffer<3){
        nbuff=repeated-2;
        buffer-=nbuff;
      }


    }
    repeated=1;
  }
  last = c;
}
if(repeated>2){
  if(repeated-buffer>2){
    repeated-=buffer;
    changes+=repeated/3;
    printf("repetition change= %d\n",repeated/3);
    replacebuff+=repeated/3;
    buffer=0;
  }else if(repeated-buffer<3){
    nbuff=repeated-2;
    buffer-=nbuff;
  }
  repeated=1;
}

if (upper&&replacebuff<1){
  changes++;
  printf("upper change\n");
}else if(upper){
  replacebuff--;
}
if (lower&&replacebuff<1){
  changes++;
  printf("lower change\n");
}else if (lower){
  replacebuff--;

}
if (digit&&replacebuff<1){
  changes++;
  printf("digit change\n");
}else if (digit){
  replacebuff--;
}

if(pSize>2 && pSize<6){
  if(pSize+changes<6){
    changes+=6-(pSize+changes);
  }
}

return changes;
}

int main() {

  char *password = "AAAAAABBBBBB123456789a";
  //printf("%s\n",password );

  int res = strongPasswordChecker(password);

  printf("changes = %d\n", res );
  /* code */
  return 0;
}
