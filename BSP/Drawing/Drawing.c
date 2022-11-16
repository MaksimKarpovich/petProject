/**
  ******************************************************************************
  * @file    Drawing.c
  * @brief   This file provides code for drawing
  *          in console
  ******************************************************************************
  */

#include <stdio.h>

#define UP(num) for(int i = 0; i < num; i++) printf("\033[A")
#define DOWN(num) for(int i = 0; i < num; i++) printf("\033[B")
#define RIGHT(num) for(int i = 0; i < num; i++) printf("\033[C")
#define LEFT(num) for(int i = 0; i < num; i++) printf("\033[D")
#define HOME() printf("\033[H")
#define END() printf("\033[F")
#define PGUP() printf("\033[I")
#define PGDN() printf("\033[G")

#define BROWN "\033[07;38;05;94;48;05;94m"
#define GREEN "\033[07;38;05;107;48;05;107m"
#define YELLOW "\033[07;38;05;226;48;05;226m"
#define YELLOW_TOY "\033[07;38;05;107;48;05;226m"
#define BLUE_TOY "\033[07;38;05;107;48;05;21m"
#define DEFAULT "\033[0m"

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

void drawTree(void)
{
    int upNum = 0;

    RIGHT(8);

    printf(BROWN);
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

    printf(GREEN);
    int greenWidth = 19;
    for(int greenHight = 0; greenHight < 19; greenHight++)
    {
        for(int i = 0; i < greenWidth; i++)
            printf("#");

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
void decorateTree(void)
{
    int upNum = 0;

    UP(3);
    upNum += 3;

    RIGHT(15);

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

    UP(2);
    upNum += 2;

    printf(YELLOW);
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
