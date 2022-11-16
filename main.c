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
//    drawPyramid(window.ws_row - 1);

    for(int i = 0; i < window.ws_row; i++)
    {
        printf ("\r\n");
    }
    drawTree();

    decorateTree();
//    printf("*");
    printf("\r\n");
//    printf ("window.ws_row = %d\r\n", window.ws_row);
//    printf ("window.ws_col = %d\r\n", window.ws_col);
//    system("clear");
}
