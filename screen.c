#include <stdio.h>
#include <windows.h>
#include <conio.h>

COORD setCOORD;//定位结构体

extern HANDLE setHandleaa;

void setXY(int x,int y)
{
    setCOORD.X=x;
    setCOORD.Y=y;
    SetConsoleCursorPosition(setHandleaa,setCOORD);
}
