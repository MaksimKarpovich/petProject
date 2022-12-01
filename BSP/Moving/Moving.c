/**
  ******************************************************************************
  * @file    Moving.c
  * @brief   This file provides code for drawing
  *          moving items in console
  ******************************************************************************
  */

#include <stdio.h>
#include <sys/types.h>
#include "main.h"
#include "Drawing.h"


#define BLUE_BACK_WHITE_LETTER "\033[01;38;05;15;48;05;68m"
#define BLUE "\033[01;38;05;68;48;05;68m"

void fallingSnowflake(u_int64_t tactNum)
{
    static int height = 44;
    static int position = 50;

    if((tactNum % 1000) == 0)
    {
        if(height != 0)
        {
            RIGHT(position + 1);
            UP(height);
            printf(BLUE);
            printf("#");
            DOWN(1);
            LEFT(1);
            printf(BLUE_BACK_WHITE_LETTER);
            printf("*");
            DOWN(height - 1);
            height--;
        }
    }
    PGDN();
}
