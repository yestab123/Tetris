/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */

#ifndef _CORE_HEADER_
#define _CORE_HEADER_

// VERSION 1.0

#define STAY 2 //the block stop
#define DOWN 1 // which block is moving
#define FLUSHTIME 100//Drop time 500ms;
#define KEYTIME 10//Next Key Time 50ms;
#define STARTTIME 10//the time for the new block to move first;
#define WAITINGTIME 20//the time waiting for next block 1500ms
#define GAMEOVER_WAITINGTIME 1200
#define COLORNUM 5;

//Function in main.c
void r_insert();
int gameover_judge();
int printf_full();
void r_insert();
int r_move_test();
int r_move();
void r_move_soon();
int MOVE_LEFT_TEST();
int MOVE_LEFT();
int MOVE_RIGHT_TEST();
int MOVE_RIGHT_SIDE_TEST();
int MOVE_RIGHT();
int KEY_CATCH();
void drawFrame();
////////////////////////

//grade.c/////
//#define	CLOCKS_PER_SEC	((clock_t)1000)//time//它用来表示一秒钟会有多少个时钟计时单元


#endif
