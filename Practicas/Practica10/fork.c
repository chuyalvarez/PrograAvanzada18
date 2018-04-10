#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int pid;

  pid = fork();

  if(pid == 0 ){
    //execl("path", "name", (char *)0)
    printf("Soy el proceso hijo\n");
  } else {
    printf("Soy el proceso padre \n");
  }

  return 0;
}
