/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "mark.h"

extern int screen_a[24][12];

/*


int   a[20][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,1,0,0,0,0,0,0},
				{0,0,0,0,0,1,0,0,0,0,0,0},
				{0,0,0,0,0,1,1,0,0,0,0,0},
				{0,0,0,1,1,1,1,1,1,1,1,0},
				{0,0,0,1,0,1,1,1,0,0,0,0},
				{0,0,0,0,0,1,1,0,0,0,0,0},
				{0,0,0,0,0,1,1,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,0,0,0,0}};

void printf_full()
{
    int i,j;
    for(i=0;i<20;i++)
	{
		for(j=0;j<12;j++)
		{
			if(a[i][j]==0)
				printf("¡õ");
			else
				printf("¡ö");
		}
		printf("\n");

	}
}
*/
int CROSS_MAX()//Under
{
	int i,j;
	int imax;
	int x=0;
	for(i=23;i>=0;i--)
		{
		for(j=0;j<12;j++)
			{
			if(screen_a[i][j]==DOWN)
			{imax=i;
			x=1;
			break;}
			}
			if(x==1)break;
		}
		return(imax);
}

int CROSS_MIN()//Top
{
	int i,j;
	int imin;
	int x=0;
	for(i=0;i<24;i++)
	{
		for(j=0;j<12;j++)
			{
			if(screen_a[i][j]==DOWN)
			{imin=i;
			x=1;
			break;}
			}
			if(x==1)break;
	}
}

int ROW_MAX()//RIGHT
{

	int i,j;
	int jmax;
	int x=0;
	for(j=11;j>=0;j--)
		{
		 for(i=23;i>=0;i--)
			{
			if(screen_a[i][j]==DOWN)
			 {jmax=j;
			 x=1;
			 break;}
			 }
			 if(x==1)break;
		}
		return(jmax);
}

int ROW_MIN()//LEFT
{
	int i,j;
		int jmin;
	int x=0;
	for(j=0;j<12;j++)
	{
		for(i=0;i<24;i++)
		 {
		 if(screen_a[i][j]==DOWN)
		 {jmin=j;
		 x=1;
		 break;}
		 }
		 if(x==1)break;
	}
	return (jmin);

}
/*
int main ()
 {
	int A,B,C,D;
	 printf_full();
	 A=I_MAX();
	 C=I_MIN();
	 D=J_MAX();
	  B=J_MIN();
	 printf("\nimax=%d        imin=%d        jmax=%d        jmin=%d\n",A,C,D,B);

}*/
