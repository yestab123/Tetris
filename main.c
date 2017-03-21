/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //Sleep()
#include <conio.h> //kbhit()

#include "core.h"

#include "grade.h"
#include "mark.h"
#include "print.h"
#include "trans.h"
#include "screen.h"
#include "ranking_list.h"
#include "queue.h"

extern Queue Q;
extern float dropTIME;

int STATUS = 0; //GAME STATUS MARK
int MARK;
int MARK_LINE;
int FORECAST;
int FORECAST_ARRAY[4][4];
int PAUSE=0;//PAUSE status mark;
int testnum=0;
int setCOLOR=0;//blocks with color;1=red,2=blue,3=green,4=yellow,0=;
int setCOLORfore=0;
int downCOLOR=0;
HANDLE setHandleaa;//¾ä±úÉùÃ÷
clock_t clockNow,clockLast;//remeber two time.

int screen_a[24][12]={0};
int h[4][4]={{0,0,0,0},
             {1,0,0,0},
             {1,0,0,0},
             {1,1,0,0}};//L

int c[4][4]={{0,0,0,0},
             {0,1,0,0},
             {1,1,0,0},
             {1,0,0,0}};//2

int f[4][4]={{0,0,0,0},
             {0,1,0,0},
             {0,1,0,0},
             {1,1,0,0}};//F-L

int e[4][4]={{0,0,0,0},
             {0,0,0,0},
             {0,1,0,0},
             {1,1,1,0}};//3

int o[4][4]={{0,0,0,0},
             {0,0,0,0},
             {1,1,0,0},
             {1,1,0,0}};//0

int p[4][4]={{0,0,0,0},
             {1,0,0,0},
             {1,1,0,0},
             {0,1,0,0}};//F-2

int t[4][4]={{1,0,0,0},
             {1,0,0,0},
             {1,0,0,0},
             {1,0,0,0}};


int gameover_judge()
{
    int i=0;
    int check=0;
    for(;i<12;i++)
    {
        if((screen_a[4][i])>STAY)
        {
            check=1;
            break;
        }
    }
    if(check==1)
    {
        STATUS=1;
        GAMEOVER_PRINT();
        return 1;
    }
    else return 0;


}



void r_insert()
{
    int ii,jj,kk,mm;
    int make;
    make=FORECAST;
    srand((unsigned)time(0));
    downCOLOR=setCOLOR;
    setCOLOR=setCOLORfore;
    FORECAST=rand()%7;
    setCOLORfore=rand()%COLORNUM;
    drawFORECAST();
    if(make==1)
    {

    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=h[kk][mm];
        }
    }

    }
    else if(make==2)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=c[kk][mm];
        }
    }
    }
    else if(make==3)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=f[kk][mm];
        }
    }
    }
    else if(make==4)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=e[kk][mm];
        }
    }
    }
        else if(make==5)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=o[kk][mm];
        }
    }
    }
        else if(make==6)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=p[kk][mm];
        }
    }
    }
        else if(make==0)
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=t[kk][mm];
        }
    }
    }
    else
    {
    for(ii=0,kk=0;ii<4;ii++,kk++)
    {
        for(jj=4,mm=0;jj<8;jj++,mm++)
        {
            screen_a[ii][jj]=h[kk][mm];
        }
    }
    }
    MARK=CROSS_MAX();
    MARK_LINE=ROW_MIN();
}
//====================================================
int r_move_test()//testing the next step
{
    int i,j,k;
    char aa;
    MARK=CROSS_MAX();
    j=MARK;
    if(MARK==23)
    {
        i=0;
        while(i<3){
                    if(kbhit())
            {

                aa=getch();
                if(aa=='a'||aa=='A'||aa==75)
                        MOVE_LEFT();
                else if(aa=='d'||aa=='D'||aa==77)
                        MOVE_RIGHT();
                else if(aa=='w'||aa=='W'||aa==72)
                        go();
            }Sleep(70);
            i++;}
        return 1;
    }
    for(k=0;k<4;k++,j--)
    {
        for(i=0;i<12;i++)
        {
            if((screen_a[j][i]==DOWN)&&(screen_a[j+1][i]>STAY))
            {
                        i=0;
                        if(testnum==0)
                        {
                while(i<4){
                    if(kbhit())
            {

                aa=getch();
                if(aa=='a'||aa=='A'||aa==75)
                        MOVE_LEFT();
                else if(aa=='d'||aa=='D'||aa==77)
                        MOVE_RIGHT();
                else if(aa=='w'||aa=='W'||aa==72)
                        go();
            }Sleep(70);
            i++;}testnum=1;}
            else return 1;
            return r_move_test();}
        }
    }

    return 0;

}

int r_move()
{
    int i,j,k,m;
    if(r_move_test()==1)
        {
            return 1;
        }

        for(i=MARK;i>=MARK-3;i--)
        {
                for(j=0;j<12;j++)
            {
                if(screen_a[i][j]==DOWN)
                {
                        screen_a[i+1][j]=screen_a[i][j];
                        screen_a[i][j]=0;

                }
            }
        }
        MARK=CROSS_MAX();
    setXY(0,0);
    testnum=0;
    printf_full();

}


void r_move_soon()
{
    int i,j,k,m;

    while(MARK<23)
    {
        if(r_move_test()==1)
        {
            MARK=200;
        }
        else{
        for(i=MARK;i>=MARK-3;i--)
        {
                for(j=0;j<12;j++)
            {
                if(screen_a[i][j]==DOWN)
                {
                        screen_a[i+1][j]=screen_a[i][j];
                        screen_a[i][j]=0;

                }
            }
        }
        }
        MARK++;
    }
    setXY(0,0);
    printf_full();
}
//=========================================

//Control Part.......
int MOVE_LEFT_TEST()
{
    int i,j,k;
    MARK_LINE=ROW_MIN();
    if(MARK_LINE==0)
        return 1;
    k=MARK_LINE;
    for(j=0;j<4;k++,j++)
    {
        for(i=0;i<24;i++)
        {
            if((screen_a[i][k]==DOWN)&&(screen_a[i][k-1]>STAY))
                return 1;
        }
    }
    return 0;
}


int MOVE_LEFT()
{
    int i,j;
    if((MOVE_LEFT_TEST()==1)||(MARK_LINE==0))
        return 0;
    for(i=MARK_LINE;i<MARK_LINE+4;i++)
    {
        for(j=0;j<24;j++)
        {
            if(screen_a[j][i]==DOWN)
            {
                screen_a[j][i-1]=DOWN;
                screen_a[j][i]=0;
            }
        }
    }
    MARK_LINE--;
    setXY(0,0);
    printf_full();
    Sleep(FLUSHTIME);

}


int MOVE_RIGHT_TEST()
{
    int i,j,k;
    if(ROW_MAX()==11)
        return 1;
    k=ROW_MAX();
    for(i=0;i<4;i++,k--)
    {
        for(j=0;j<24;j++)
        {
            if(screen_a[j][k]==DOWN&&screen_a[j][k+1]>STAY)
                return 1;
        }
    }
    return 0;
}//Test can it move to right

int MOVE_RIGHT_SIDE_TEST()
{
    int i,j,k;
    k=ROW_MAX();
    if(k==11)
        return 0;
    else
        return 1;

}//Test is it touch the right side?

int MOVE_RIGHT()
{
    int i,j,k;
    int t=ROW_MAX();
    int m=ROW_MIN();
    if((MOVE_RIGHT_TEST()==1)||(MOVE_RIGHT_SIDE_TEST()==0))
    {
        return 0;
    }
    for(;t>=m;t--)
    {
        for(j=0;j<24;j++)
        {
            if(screen_a[j][t]==DOWN)
            {
                screen_a[j][t+1]=DOWN;
                screen_a[j][t]=0;
            }
        }
    }
    printf_full();
    Sleep(FLUSHTIME);
}
///////////@>@

int KEY_CATCH()
{
    char aa;
    char bb;
    int m=0;
    int i,j;
    clock_t clockNow,clockLast;//remeber two time.
    while(r_move_test()!=1)
    {
        if(PAUSE==0)
        {

            if(kbhit())
            {

                aa=getch();
                if(aa=='a'||aa=='A'||aa==75)
                        MOVE_LEFT();
                else if(aa=='d'||aa=='D'||aa==77)
                        MOVE_RIGHT();
                else if(aa=='s'||aa=='S'||aa==80)
                        r_move();
                else if(aa=='w'||aa=='W'||aa==72)
                        go();
                else if(aa==' ')
                        r_move_soon();
                else if(aa=='p'||aa=='P')
                {
                    PAUSE=1;
                    setXY(30,7);
                    printf("Game Pause!");
                    setXY(30,8);
                    printf("Enter any key");
                    setXY(30,9);
                    printf("to continue!");
                }
            }
            clockNow = clock();
            if (clockNow - clockLast > dropTIME * CLOCKS_PER_SEC)//if twice time max 0.45s ,down;
            {
                clockLast = clockNow;
                r_move();  // ·½¿éÍùÏÂÒÆ
            }
        }
        else if(kbhit())
        {
            bb=getch();
            PAUSE=0;
        }

    }

    for(i=0;i<24;i++)
        for(j=0;j<12;j++)
        {
            if(screen_a[i][j]==DOWN)
            {
                screen_a[i][j]=setCOLOR+3;
            }

        }
}

int main()
{
	int i,j,k,m;
	InitQueue(&Q);//
    setHandleaa=GetStdHandle(STD_OUTPUT_HANDLE);//Get stdin handle
    SetConsoleTitleA("Tetris Ver:1.0");//set title
    system("cls");
    GAMECHOICE();
    return 0;

}
