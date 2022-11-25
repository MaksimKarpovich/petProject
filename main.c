#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <time.h>
#include "Drawing.h"

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
    drawTree();

    decorateTree();
    printf("\033[A");
    printf("\r\n");
    while(1);
//    system("clear");
}
