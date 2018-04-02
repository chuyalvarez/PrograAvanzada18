#include "Stack.h"

void push(Stack stack, int num){
    if(stack.top==(999)){

    }
    else{
    stack.top+=1;
    stack.stk[stack.top]= num;
    }
}

int pop(Stack stack){
    int num;
    if(stack.top==-1){
      num= 0;
    }
    else{
    num=stack.top;
    stack.stk[num]=0; //To delete top element from stack
    stack.top-=1;
    }
    return num;
}
