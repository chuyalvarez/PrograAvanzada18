#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X0;
    int Y0;
    int downY;
    int downX;
    int upY;
    int upX;
    scanf("%d%d", &X0, &Y0);
    downY=0;
    downX=0;
    upX=W;
    upY=H;
    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if(bombDir[0]=='U'||bombDir[0]=='D'){
            if(bombDir[0]=='U'){
                upY=Y0;
                Y0=Y0-((Y0-downY)/2);
            }else if (bombDir[0]=='D'){
                downY=Y0;
                Y0=Y0+((upY-Y0)/2);
            }
            if(bombDir[1]=='L'){
                upX=X0;
                X0=X0-((X0-downX)/2);
            }else if (bombDir[1]=='R'){
                downX=X0;
                X0=X0+((upX-X0)/2);
            }
        }else{
           if(bombDir[0]=='L'){
                upX=X0;
                X0=X0-1-((X0-downX)/2);
            }else if (bombDir[0]=='R'){
                downX=X0;
                X0=X0+((upX-X0)/2);
            }
        }


        // the location of the next window Batman should jump to.
        printf("%d %d\n",X0,Y0);
    }

    return 0;
}
