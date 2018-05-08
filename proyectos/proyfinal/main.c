#include <stdio.h>
#include <stdlib.h>

#define lim 100005

long infoarr[5*lim][3];
char check[5*lim];

void initialize(long i, long s, long len){
    if(s == len){
        infoarr[i][0] = 1;
        infoarr[i][1] = 0;
        infoarr[i][2] = 0;
        check[i] = 0;
    }
    else{
        initialize(2*i+1, s, (s+len)/2);
        initialize(2*i+2, (s+len)/2 + 1, len);
        infoarr[i][0] = infoarr[2*i+1][0] + infoarr[2*i+2][0];
        infoarr[i][1] = infoarr[2*i+1][1] + infoarr[2*i+2][1];
        infoarr[i][2] = infoarr[2*i+1][2] + infoarr[2*i+2][2];
        check[i] = 0;
    }
}

void update(long s, long e, long i, long start, long end){
    long temp;

    if(check[i] != 0){
        if(check[i] == 1){
            temp = infoarr[i][2];
            infoarr[i][2] = infoarr[i][1];
            infoarr[i][1] = infoarr[i][0];
            infoarr[i][0] = temp;
        }else{
            temp = infoarr[i][2];
            infoarr[i][2] = infoarr[i][0];
            infoarr[i][0] = infoarr[i][1];
            infoarr[i][1] = temp;
        }
        if(s != e){
            check[2*i+1] = (check[2*i+1] + check[i])%3;
            check[2*i+2] = (check[2*i+2] + check[i])%3;
        }
        check[i] = 0;
    }

    if(s > end || e < start){

    }else if(start <= s && e <= end){
        temp = infoarr[i][2];
        infoarr[i][2] = infoarr[i][1];
        infoarr[i][1] = infoarr[i][0];
        infoarr[i][0] = temp;
        check[i] = 0;
        if(s != e){
            check[2*i+1] = (check[2*i+1] + 1)%3;
            check[2*i+2] = (check[2*i+2] + 1)%3;
        }

    }else{
        update(s, (s+e)/2, 2*i+1, start, end);
        update((s+e)/2 + 1, e, 2*i+2, start, end);
        infoarr[i][0] = infoarr[2*i+1][0] + infoarr[2*i+2][0];
        infoarr[i][1] = infoarr[2*i+1][1] + infoarr[2*i+2][1];
        infoarr[i][2] = infoarr[2*i+1][2] + infoarr[2*i+2][2];
      
    }
}

long divisible(long s, long e, long i, long start, long end){
    long temp;

    if(check[i] != 0){
        if(check[i] == 1){
            temp = infoarr[i][2];
            infoarr[i][2] = infoarr[i][1];
            infoarr[i][1] = infoarr[i][0];
            infoarr[i][0] = temp;
        }else{
            temp = infoarr[i][2];
            infoarr[i][2] = infoarr[i][0];
            infoarr[i][0] = infoarr[i][1];
            infoarr[i][1] = temp;
        }
        if(s != e){
            check[2*i+1] = (check[2*i+1] + check[i])%3;
            check[2*i+2] = (check[2*i+2] + check[i])%3;
        }
        check[i] = 0;
    }

    if(s > end || e < start){
        return 0;
    }else if(s >= start && e <= end){
        return infoarr[i][0];
    }else{
        return divisible(s, (s+e)/2, 2*i+1, start, end) + divisible((s+e)/2 + 1, e, 2*i+2, start, end);
    }
}

int main(void){
    long i, length, queries, start, end;
    int type;

    scanf("%ld %ld", &length, &queries);
    initialize(0, 0, length-1);
    while(queries--){
        scanf("%d %ld %ld", &type, &start, &end);
        if(type == 0){
            update(0, length-1, 0, start, end);
        }else{
            printf("%ld\n", divisible(0, length-1, 0, start, end));
        }
    }
    return 0;
  }
