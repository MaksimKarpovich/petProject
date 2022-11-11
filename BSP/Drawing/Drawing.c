/**
  ******************************************************************************
  * @file    Drawing.c
  * @brief   This file provides code for drawing
  *          in console
  ******************************************************************************
  */

#include <stdio.h>

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

void drawChristmasTree(int size)
{

}
