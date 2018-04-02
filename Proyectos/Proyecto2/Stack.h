typedef struct bufferstack{
int stk[1000];
int top; // We will use it as pointer to top of the stack
} Stack;

void push(Stack stack, int num);
int pop(Stack stack);
