/**
  ******************************************************************************
  * @file    main.h
  * @brief   This file contains all the function prototypes for
  *          the main.c file
  ******************************************************************************
  */

#define UP(num) for(int i = 0; i < num; i++) printf("\033[A")
#define DOWN(num) for(int i = 0; i < num; i++) printf("\033[B")
#define RIGHT(num) for(int i = 0; i < num; i++) printf("\033[C")
#define LEFT(num) for(int i = 0; i < num; i++) printf("\033[D")
#define HOME() printf("\033[H")
#define END() printf("\033[F")
#define PGUP() printf("\033[I")
#define PGDN() printf("\033[G")

#define MAX_HIGHT 200
#define MAX_WIDTH 200

