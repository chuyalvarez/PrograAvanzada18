#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

int passes(int *persons){
  int transactions,amount,exits,enters,temp;
  long id;
  char action[10];
  char *number=action+3;
  Stack ls,es;
  scanf(" %d",&transactions);
  while(getchar() != '\n');
  for (int j=0;j<transactions;j++){
      scanf(" %s",action);
      while(getchar() != '\n');
      id=strtol(number,NULL,10);
      //printf("%c\n",action[1]);
      if(((char)action[0])=='L'){
          if (id>0){
              if(persons[id]==-2){
                  persons[id]=0;
                  amount--;
              }else if(persons[id]==0){
                  temp=pop(es);
                  if (temp<persons[id]){
                      push(es,temp);
                      return -1;
                  }
              }else{
                  persons[id]=0;
                  amount--;
              }
          }else if(id==0){
                  push(ls,j);
          }
      }else if(((char)action[0])=='E'){
          if (id>0){
              if(persons[id]>0){
                  temp=pop(ls);
                  if(temp<persons[id]){
                    push(ls,temp);
                    return -1;
                  }
              }else{
                  persons[id]=j;
                  amount++;
              }
          }else if(id==0){
              push(es,j);
          }
      }

  }
  amount+=enters;
  amount-=exits;
  return amount;
}

int main() {
    int cases,persons[100],res;


    scanf(" %d",&cases);
    while(getchar() != '\n');
    for (int i=0;i<cases;i++){
        for(int k=0;k<100;k++){
            persons[k]=-2;
        }
        res = passes(persons);
        if (res<0){
          printf("CRIME TIME\n");
        }else{
          printf("%d\n",res );
        }
    }

  /* code */
  return 0;
}
