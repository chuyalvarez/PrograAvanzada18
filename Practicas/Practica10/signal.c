#include <stdio.h>
#include <stdio.h>

void receiveSignal(int sig){
  printf("HOLA MUNDO\n")
  printf("Recibi sennal%d\n", sig);
}

int main(int argc, char const *argv[]) {
  signal(SIGTERM, receiveSignal);
  while(1){

  }
  return 0;
}
