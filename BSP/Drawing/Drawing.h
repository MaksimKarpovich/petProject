/**
  ******************************************************************************
  * @file    Drawing.h
  * @brief   This file contains all the function prototypes for
  *          the Drawing.c file
  ******************************************************************************
  */

#include <sys/types.h>

u_int16_t * getHighestForeground(void);

void drawPyramid(int size);

void drawBlueBackground(void);

void drawTree(u_int16_t horizont, u_int16_t vertical);

void decorateTree(u_int16_t horizont, u_int16_t vertical);

void drawSnowGround(void);
