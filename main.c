#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "Drawing.h"

int main(int argc, char** argv)
{
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    printf ("\033[32m");
    drawPyramid(window.ws_row - 1);
    printf ("\033[0m");
}
