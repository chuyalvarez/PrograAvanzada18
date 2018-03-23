#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{

    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        scanf("%d%d%d%d%d%d", &x, &y, &nextCheckpointX, &nextCheckpointY, &nextCheckpointDist, &nextCheckpointAngle);
        int opponentX;
        int opponentY;

        scanf("%d%d", &opponentX, &opponentY);
        int thrust;


        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"

        //double opDist;
        //opDist=sqrt(pow(opponentX-x,2)+pow(opponentY-y,2));
        fprintf(stderr, "dist: %d \n",nextCheckpointAngle);
        if(nextCheckpointAngle > 60 || nextCheckpointAngle < -60){
            thrust=40;
        }else if (nextCheckpointAngle > 80 || nextCheckpointAngle < -80){
            thrust = 0;
        }else if(nextCheckpointDist<1500){
            thrust=50;
        }else if(nextCheckpointDist<1000){
            thrust=30;
        }else{
            thrust = 100;
        }
       /* if(opDist<5000&&nextCheckpointDist>1000){
            printf("%d %d 100\n", opponentX, opponentY);
        }else{
            if (nextCheckpointAngle==0&&nextCheckpointDist>10000){
                printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            }else{
                printf("%d %d %d\n", nextCheckpointX, nextCheckpointY,thrust);
            }
        }*/

        if (nextCheckpointAngle==0&&nextCheckpointDist>10000){
                printf("%d %d BOOST\n", nextCheckpointX, nextCheckpointY);
            }else{
                printf("%d %d %d\n", nextCheckpointX, nextCheckpointY,thrust);
            }
    }

    return 0;
}
