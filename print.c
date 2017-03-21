/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#include "screen.h"
#include "queue.h"
#include "print.h"
#include "ranking_list.h"
#include "core.h"

extern int STATUS;
extern int FORECAST;
extern int setCOLOR;
extern int setCOLORfore;
extern int queue_mark;
extern HANDLE setHandleaa;
extern int screen_a[24][12];
extern int FORECAST_ARRAY[4][4];
extern int LEVEL;
extern int GRADE;
extern int h[4][4];
extern int c[4][4];
extern int f[4][4];
extern int e[4][4];
extern int o[4][4];
extern int p[4][4];
extern int t[4][4];
extern Queue Q;

void GAMECHOICE()//make choice before start the game! instead 1.start game,2.rank lisk,3.exit
{
    int CHOICE=1;
    int cache=0;
    char getkey;
    system("cls");

    while(1)
    {
        if(cache==0){
           system("cls");
            setXY(28,6);
            printf("==Program Project Tetris==");
        }
        if(CHOICE!=cache)
        {

            if(CHOICE==1)
            {
            setXY(32,8);
            SetConsoleTextAttribute(setHandleaa,BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE| BACKGROUND_INTENSITY);
            printf("1.START GAME");
            setXY(32,9);
            SetConsoleTextAttribute(setHandleaa, 0x0F);
            printf("2.RANK LIST");
            setXY(32,10);
            printf("3.EXIT");
            }
            else if(CHOICE==2)
            {
            setXY(32,8);
            SetConsoleTextAttribute(setHandleaa,0x0F);
            printf("1.START GAME");
            setXY(32,9);
            SetConsoleTextAttribute(setHandleaa,BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE| BACKGROUND_INTENSITY);
            printf("2.RANK LIST");
            setXY(32,10);
            SetConsoleTextAttribute(setHandleaa,0x0F);
            printf("3.EXIT");
            }
            else if(CHOICE==3){
            setXY(32,8);
            SetConsoleTextAttribute(setHandleaa,0x0F);
            printf("1.START GAME");
            setXY(32,9);
            printf("2.RANK LIST");
            setXY(32,10);
            SetConsoleTextAttribute(setHandleaa,BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE| BACKGROUND_INTENSITY);
            printf("3.EXIT");
            }
            cache=CHOICE;
        }
        SetConsoleTextAttribute(setHandleaa,0x0F);
        if(kbhit())
        {
            getkey=getch();
            if(getkey==72||getkey=='w'||getkey=='W')
            {
                CHOICE--;
                if(CHOICE==0)
                {
                    CHOICE=3;
                }
            }
            else if(getkey==80||getkey=='s'||getkey=='S')
            {
                CHOICE++;
                if(CHOICE==4)
                {
                    CHOICE=1;
                }
            }
            else if(getkey=='\r'||getkey==10)
            {
                if(CHOICE==1)
                {
                    GAMESTART();
                }
                else if(CHOICE==2)
                {
                    show();

                }
                else if(CHOICE==3)
                {
                    exit(0);
                }
            }
            cache=0;

        }
    }
}

void GAMESTART()//include the recycle  running function when start the game.
{
    int i,j;
    STATUS=0;
    GRADE=0;
    LEVEL=1;
    for(i=0;i<24;i++)
        for(j=0;j<12;j++)
    {
        screen_a[i][j]=0;
    }
    system("cls");
    drawFrame();
    SetConsoleTextAttribute(setHandleaa, 0x0F);//set color
    drawLEFT();
    srand((unsigned)time(0));
    setCOLORfore=rand()%COLORNUM;//set the first random color
    FORECAST=rand()%7;//set the first random block
    drawFORECAST();
    setLEVEL();//set LEVEL=1;time=0.45F;
    while(STATUS==0)
    {
	r_insert();
    printf_full();
    Sleep(STARTTIME);
	KEY_CATCH();
	WIN_TEST();
	printf_full();
	Sleep(WAITINGTIME);
    gameover_judge();
    }
    /*TOP();
    show();*/
}

void GAMEOVER_PRINT()
{
    char NAME[20];
    setXY(28,5);
    printf("    GAME OVER    ");
    setXY(25,6);
    printf("You got %d",GRADE);
    setXY(25,7);
    printf("Please enter your name:");
    TOP();
    system("cls");
    show();
}






//print forecast block;
int drawFORECAST()
{//Print forecast block on console.
    int i,j;
    arrayFORECAST();
    for(i=0;i<4;i++)
    {
        setXY(58,2+i);
        for(j=0;j<4;j++)
        {
            if(FORECAST_ARRAY[i][j]==0)
                printf("%2s"," ");
			else
				          {
                if(setCOLORfore==0)
                {
                    SetConsoleTextAttribute(setHandleaa,FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLORfore==1)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED|FOREGROUND_INTENSITY);
                }
                else if(setCOLORfore==2)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLORfore==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                else if(setCOLORfore==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }

        }
    }
        for(i=0;i<5;i++)
    {
        setXY(54,2+i);
        printf("©§");
        setXY(64,2+i);
        printf("©§");
    }
    setXY(54,1);
    printf("©³©¥©¥©¥©¥©·");
    setXY(54,7);
    printf("©»©¥©¥©¥©¥©¿");
}

int arrayFORECAST()
{
    int i,j;
    if(FORECAST==1)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=h[i][j];
        }
    }
    else if(FORECAST==2)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=c[i][j];
        }
    }
    else if(FORECAST==3)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=f[i][j];
        }
    }
    else if(FORECAST==4)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=e[i][j];
        }
    }
    else if(FORECAST==5)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=o[i][j];
        }
    }
    else if(FORECAST==6)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=p[i][j];
        }
    }
    else if(FORECAST==0)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
        {
            FORECAST_ARRAY[i][j]=t[i][j];
        }
    }
}

int drawLEFT()
{
    setXY(6,2);
    printf("LEVEL:%d",LEVEL);
    setXY(6,3);
    printf("GRADE:%d",GRADE);//draw grade
    setXY(54,9);
    SetConsoleTextAttribute(setHandleaa,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    printf("KEY:      FIRST   SECOND");
    SetConsoleTextAttribute(setHandleaa,FOREGROUND_RED|FOREGROUND_INTENSITY);
    setXY(54,10);
    printf("PAUSE     [P] ");
    setXY(54,11);
    printf("Change    [W]     [¡ü]");
    setXY(54,12);
    printf("Left      [A]     [¡û]");
    setXY(54,13);
    printf("Right     [D]     [¡ú]");
    setXY(54,14);
    printf("Down      [S]     [¡ý]");
    setXY(54,15);
    printf("Soon      [ ]     [space]");
}


int printf_full_miss()
{
    int i,j;
    for(i=4;i<24;i++)
	{
        setXY(25,i-4);
		for(j=0;j<12;j++)
		{

			if((screen_a[i][j]==0 ))
				printf("%2s"," ");
			else if(screen_a[i][j]>STAY && test_queue_equal(i))
            {
                if(screen_a[i][j]==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_BLUE);
                }
                else if(screen_a[i][j]==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED);
                }
                else if(screen_a[i][j]==5)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE);
                }
                else if(screen_a[i][j]==6)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN);
                }
                else if(screen_a[i][j]==7)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }
            else if(screen_a[i][j]>STAY)
            {
                if(screen_a[i][j]==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==5)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==6)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==7)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }

            else if(screen_a[i][j]==DOWN)
            {
                if(setCOLOR==0)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==1)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==2)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }
		}
		printf("\n");
	}
}

int test_queue_equal(int a)///use with print_full_miss()
{
    int m=queue_mark;
    int i;
    while(m>0)
    {
        DeQueue(&Q,&i);
        EnQueue(&Q,i);
        if(a==i)
            return 1;
        m--;
    }
    return 0;
}

int printf_miss()
{
    int i=5;
     while(i>0){
     printf_full_miss();
     Sleep(50);
     printf_full();
     Sleep(50);
     i--;
     }
}

//Draw the frame
void drawFrame()
{
    int x,y;
    SetConsoleTextAttribute(setHandleaa, 0xF0);
    for(x=49,y=0;y<21;y++)//25//up25
    {
        setXY(x,y);
        printf("%2s"," ");
        printf("\n");
    }//Right
    for(x=25,y=20;x<=50;x++)
    {
        setXY(x,y);
        printf("%1s"," ");
        printf("\n");
    }//Under
    for(x=23,y=0;y<21;y++)
    {
        setXY(x,y);
        printf("%2s"," ");
        printf("\n");

    }//left
}

int printf_full()
{
    int i,j;
    for(i=4;i<24;i++)
	{
        setXY(25,i-4);
		for(j=0;j<12;j++)
		{

			if(screen_a[i][j]==0)
				printf("%2s"," ");
			else if(screen_a[i][j]>STAY)
            {
                if(screen_a[i][j]==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==5)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==6)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                else if(screen_a[i][j]==7)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }

            else if(screen_a[i][j]==DOWN)
            {
                if(setCOLOR==0)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==1)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==2)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==3)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                else if(setCOLOR==4)
                {
                    SetConsoleTextAttribute(setHandleaa, FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                }
                printf("¡ö");
                SetConsoleTextAttribute(setHandleaa, 0x0F);
            }
		}
		printf("\n");
	}
}



