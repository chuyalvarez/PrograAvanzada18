#include <stdio.h>
#include <omp.h>

int main(int argc, char const *argv[]) {
  int a[20000];
  int b[20000];
  int c[20000];

  #pragma omp parallel shared(a,b,c,chunk) private{
    #pragma omp for schedule(dynamic,chunk) nowait
    printf("Hello world\n" );
    tid = omp_get_thread_num();
    gid = tid;
  }

  return 0;
}
