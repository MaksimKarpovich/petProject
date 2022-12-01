/**
  ******************************************************************************
  * @file    Drawing.c
  * @brief   This file provides code for drawing
  *          in console
  ******************************************************************************
  */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "main.h"
#include <sys/types.h>

#define BROWN "\033[07;38;05;94;48;05;94m"
#define WHITE "\033[01;38;05;15;48;05;15m"
#define GREEN "\033[07;38;05;107;48;05;107m"
#define YELLOW "\033[07;38;05;226;48;05;226m"
#define BLUE "\033[01;38;05;68;48;05;68m"
#define YELLOW_TOY "\033[07;38;05;107;48;05;226m"
#define BLUE_TOY "\033[07;38;05;107;48;05;21m"
#define BLUE_BACK_WHITE_LETTER "\033[01;38;05;15;48;05;68m"
#define BLUE_BACK_GREEN_LETTER "\033[01;38;05;107;48;05;68m"
#define DEFAULT "\033[0m"

static u_int16_t highestForeground[MAX_WIDTH] = {0, };

u_int16_t * getHighestForeground(void)
{
    return highestForeground;
}

static void setHighestForeground(u_int16_t horizont, u_int16_t vertical)
{
    if(highestForeground[horizont] < vertical)
        highestForeground[horizont] = vertical;
}

void drawPyramid(int size)
{
    int spaceNum = size - 1;
    int symbolNum = 1;

    for(int i = size; i > 0; i--)
    {
        for(int j = spaceNum; j > 0; j--)
        {
            printf(" ");
        }

        for(int j = symbolNum; j > 0; j--)
        {
            printf("#");
        }
        symbolNum += 2;
        spaceNum -= 1;
        printf("\r\n");
    }
}

static void drawHill(void)
{
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    UP((window.ws_row >> 2) + 1);
    int startCol = window.ws_col >> 1, stopCol = (window.ws_col >> 1) + (window.ws_col >> 2);
    for(int i = 0; i < (window.ws_row >> 2); i++)
    {

        for(int j = 0; j < window.ws_col - 1; j++) {
            if(j == startCol + 1) {
                printf(BLUE_BACK_WHITE_LETTER);
                printf("\u25e2");
                printf(WHITE);
            }
            if(((j > startCol))&&((j < stopCol)||((i > (window.ws_row >> 3)))))
                printf("#");
            else
                RIGHT(1);
            if((j == stopCol)&&(i <= (window.ws_row >> 3)))
            {
                LEFT(1);
                printf(BLUE_BACK_WHITE_LETTER);
                printf("\u25e3");
                printf(WHITE);
            }
        }
        startCol -= window.ws_col / 39;
        stopCol += window.ws_col / 29;
        printf("\r\n");
    }

    for(int i = 0; i < window.ws_col; i++)
        printf("#");
    printf("\r\n");

    for(int i = 0; i < window.ws_col; i++)
        printf("#");
    printf("\r\n");

    PGDN();
    printf(DEFAULT);
}

void drawSnowGround(void)
{
    printf(WHITE);

    drawHill();
}

void drawBlueBackground(void)
{
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

    printf(BLUE);
    for(int j = 0; j < window.ws_row; j++) {
        for(int i = 0; i < window.ws_col; i++)
            printf("#");

        printf("\r\n");
    }
    PGDN();
}

void drawTree(u_int16_t horizont, u_int16_t vertical)
{
    u_int16_t highestPoint[23] = {4,5,7,9,11,13,15,17,19,21,24,25,24,21,19,17,15,13,11,9,7,5,4};
    for(int i = 0; i < 23; i++)
        setHighestForeground(horizont + i, vertical + highestPoint[i]);
    int upNum = 0;

    RIGHT(9 + horizont);
    UP(vertical);
    upNum += vertical;

//    printf(BROWN);
    for(int i = 0; i < 5; i++)
        printf("#");

    LEFT(5);
    UP(1);
    upNum++;
    for(int i = 0; i < 5; i++)
        printf("#");

    LEFT(6);
    UP(1);
    upNum++;
    for(int i = 0; i < 7; i++)
        printf("#");

    LEFT(13);
    UP(1);
    upNum++;

    int greenWidth = 19;
    LEFT(2);
//    printf(BLUE_BACK_GREEN_LETTER);
    printf("\u25e4");
//    printf(GREEN);
    printf("#");
    for(int greenHight = 0; greenHight < 19; greenHight++)
    {
        if(greenHight != 0) {
            LEFT(1);
//            printf(BLUE_BACK_GREEN_LETTER);
            printf("\u25e4");
        }

        for(int i = 0; i < greenWidth; i++) {
//            printf(GREEN);
            printf("#");
        }

        if(greenHight != 0) {
//            printf(BLUE_BACK_GREEN_LETTER);
            printf("\u25e5");
            LEFT(1);
        } else
        {
//            printf(GREEN);
            printf("#");
//            printf(BLUE_BACK_GREEN_LETTER);
            printf("\u25e5");
            LEFT(2);
        }


        if(greenHight % 2 == 0)
            LEFT(greenWidth);
        else
        {
            greenWidth -= 2;
            LEFT(greenWidth + 1);
        }

        UP(1);
        upNum++;
    }

    DOWN(upNum);

    PGDN();
    printf(DEFAULT);
}

void printTreeToy(void)
{
    static int num = 0;
    if(num % 2 == 0)
        printf(BLUE_TOY);
    else
        printf(YELLOW_TOY);

    printf("0");
    num++;
}

void decorateTree(u_int16_t horizont, u_int16_t vertical)
{
    int upNum = 0;

    UP(3 + vertical);
    upNum += 3 + vertical;

    RIGHT(horizont + 16);

    printTreeToy();

    UP(1);
    upNum++;

    LEFT(9);

    printTreeToy();

    UP(1);
    upNum++;

    LEFT(6);

    printTreeToy();
    RIGHT(1);
    printTreeToy();

    UP(1);
    upNum++;

    RIGHT(13);
    printTreeToy();

    UP(1);
    upNum++;

    LEFT(9);
    printTreeToy();
    RIGHT(2);
    printTreeToy();

    UP(1);
    upNum++;

    LEFT(7);
    printTreeToy();

    UP(1);
    upNum++;

    RIGHT(6);
    printTreeToy();

    UP(1);
    upNum++;

    printTreeToy();

    UP(1);
    upNum++;

    LEFT(10);
    printTreeToy();

    UP(1);
    upNum++;

    LEFT(2);
    printTreeToy();
    RIGHT(4);
    printTreeToy();

    UP(1);
    upNum++;

    LEFT(3);
    printTreeToy();

    UP(2);
    upNum += 2;

    LEFT(2);
    printTreeToy();

    UP(2);
    upNum += 2;

    RIGHT(2);
    printTreeToy();

    UP(1);
    upNum++;

    RIGHT(1);
    printTreeToy();

    UP(1);
    upNum++;

    LEFT(4);
    printTreeToy();

    UP(3);
    upNum += 3;

//    printf(YELLOW);
    printf(DEFAULT);
    printf("0");

    UP(1);
    upNum++;

    LEFT(2);
    printf("0");
    printf("0");
    printf("0");

    UP(1);
    upNum++;

    LEFT(2);
    printf("0");

    DOWN(upNum);

    PGDN();
    printf(DEFAULT);
}
