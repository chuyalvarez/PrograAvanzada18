#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberChecker(char* s) {

  int pSize = strlen(s);
  int comma = 0;
  int period = 0;
  int e = 0;
  int c=0;
  int number=0;
  int space=0;
  int sign =0;
  int usesign =1;

  if (pSize<1){
    return 0;
  }
  for (int i = 0;i < pSize;i++){
    c = s[i];
    if(i<=3 && c == 44 ){
      comma = 1;
    }


    if (c==32 && (number || period || comma || e ||sign)){
      space =1;
    }
    if((c!=32) && space ){
      printf("num after space\n");
      return 0;
    }




    if(c < 48 || c > 57 ){
      if(!period && c == 46 && (i>0 || i<pSize-1)){
        period=1;
        usesign =0;
      }else if(!e && (c == 69 || c== 101) && (((s[i-1] > 47 && s[i-1] < 58) ||((s[i-2] > 47 && s[i-2] < 58) && s[i-1]==46) )&& (s[i+1] > 47 && s[i+1] < 58 || ((s[i+1]==43||s[i+1]==45)&&(s[i+2] > 47 && s[i+2] < 58)))) ){
        e=1;
        period=1;
        if(s[i+1]==45 || s[i+1]==43){
          printf("passing a sign\n");
            i++;
        }
      }else if(c==44 && comma){
        if(s[i+4]== 44 || s[i+4]== 69 || s[i+4]== 101 || s[i+4]== 46 || s[i+4]== '\0'){

        }else{
          printf("comma use\n");
          return 0;
        }

      }else if(c == 32){

      }else if((c==45 || c==43) && usesign){
          sign=1;
          usesign = 0;
      }else{
        printf("invalid char,pos = %d\n",i);
        return 0;
      }
    }else{
      number=1;
      usesign=0;
    }


  }

  if (number){
    return 1;
  }else{
    printf("no numbers\n");
    return 0;
  }

}

int main() {

  char *password = " -.7e+0435";
  //printf("%s\n",password );

  int res = numberChecker(password);

  printf("%s = %d\n",password, res );
  /* code */
  return 0;
}
