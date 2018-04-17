#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include "student.h"


int main(int argc, char const *argv[]) {
 char *fileName = "student.dat";
 int fd = open(fileName,D_RDWR);
 Student *pAvanzada = (Student *)mmap(NULL, 10*sizeof(Student),PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
 close(fd);

 printf("Student at 5\n");
 printf("%s\n",pAvanzada[5].firstName );

 munmap(pAvanzada,10*sizeof(Student));
 return 0;
}
