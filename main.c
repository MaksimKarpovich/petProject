#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include "Drawing.h"
#include "Moving.h"
#include "main.h"

__attribute__((weak)) void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int main(int argc, char** argv)
{
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    if(window.ws_col == 0)
        return 0;
    drawBlueBackground();
    drawSnowGround();
//    UP(window.ws_row / 24);
//    RIGHT(window.ws_col / 30);
    drawTree(1, 1);
//    RIGHT(window.ws_col / 30);
    decorateTree(1, 1);
    LEFT(1);
    printf("\033[A");
    printf("\r\n");
    u_int64_t tactNum = 0;
    clock_t now,then;
    while(1)
    {
        now = then = clock();


//        printf("1\n");

//        fallingSnowflake(tactNum);



        tactNum++;
//        if((now-then) < CLOCKS_PER_SEC/1000)
//        {
//            printf("Error: time functions run longer than %ld milliseconds", CLOCKS_PER_SEC/1000);
//            exit(1);
//        }
        while((now-then) < CLOCKS_PER_SEC/1000)
            now = clock();

    }
//    system("clear");
}
