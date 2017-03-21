/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print.h"

int m,n,line_mark=0;

extern int MARK;
extern int MARK_LINE;
extern int screen_a[24][12];

//=======================================================
int find_mark()
{
	int i,j;
 for(i=0;i<24;i++)
		for(j=0;j<12;j++)
			if(screen_a[i][j]==1)
			{
				j=12;
				MARK=i;
			}


     for(i=23;i>=0;i--)
		for(j=0;j<12;j++)
			if(screen_a[j][i]==1)
			{
				MARK_LINE=i;
				break;
			}
}


//============================================================
void find_point()//找出转置时的中心点
{
	int i,j,s,t;
	for(i=0;i<12;i++)
		for(j=0;j<24;j++)
			if(screen_a[j][i]==1)

				if(screen_a[j+1][i]==1)
					if(screen_a[j+2][i]==1)
					{
						m =j;  n=i; i=13; j=24;}
					else
					{

						m= j; n=i+1;
						if(screen_a[m-1][n]==1)
							m=m-1;
						i=13; j=24;
					}
				else
				{
					for(s=11;s>=0;s--)
						for(t=0;t<24;t++)
							if(screen_a[t][s]==1)
							{
							//	if(s-i==3)
							//	{
							//		m=t; n=s-1; t=21; s=-1; break;
							//	}
								if(screen_a[t+1][s]==1)
									if(screen_a[t+2][s]==1)
									{
										m=t; n=s; t=24; s=-1; }
									else
									{
										m=t; n=s-1; t=24; s=-1; }
								else
								{
									if(screen_a[t-1][s-1]==1)
									{
										m=t-1; n=s-1;t=24; s=-1; }
									else
									{
										m= t;n=s-1 ; t=24; s=-1; }
								}
					i=13; j=24;
				}


}
	for(i=0;i<12;i++)//判断图形是否为直线，若为竖直线，line-mark=1，否则line-mark=2

		for(j=0;j<24;j++)
			if(screen_a[j][i]==1)

				if(j+3<24)
					if(screen_a[j+1][i]==1)
					{
						if(screen_a[j+2][i]==1)
							if(screen_a[j+3][i]==1)
							{
							m=j+2; n=i; line_mark=1 ; i=12;j=24 ; }
					}


				else
					if(i+3<12)
						if(screen_a[j][i+1]==1)
							if(screen_a[j][i+2]==1)
								if(screen_a[j][i+3]==1)
									{ m=j; n=i+2; line_mark=2; i=12;j=24 ;  }

}

//========================================================================

//======================================================================
int  try_trans()//判断转置后是否会遇到标记2的方块
{
	int i,j,s,t;
	int d[4][4]={0};
	if(line_mark==1)//竖直线
	{
		d[2][0]=d[2][1]=d[2][2]=d[2][3]=1;
		for(i=0,s=m-2;i<4;s++,i++)
			for(j=0,t=n-2;j<n;j++,t++)
				if(d[i][j]==1)
					if(screen_a[s][t]>=2)
						return 0;
	}

	if(line_mark==2)//横直线
	{

		d[0][2]=d[1][2]=d[2][2]=d[3][2]=1;
		for(i=0,s=m-2;i<4;s++,i++)
			for(j=0,t=n-2;j<4;j++,t++)
				if(d[i][j]==1)
					if(screen_a[s][t]>=2)
						return 0;
	}

    if(screen_a[m][n]==1&&screen_a[m+1][n]==1&&screen_a[m+2][n]==1&&screen_a[m+1][n-1]==1&&screen_a[m+2][n-1]>=2)
        return 0;


    if(screen_a[m][n]==1&&screen_a[m+1][n]==1&&screen_a[m+2][n]==1&&screen_a[m+1][n+1]==1&&screen_a[m+2][n+1]>=2)
        return 0;

	for(i=m,s=2;i<m+3;s--,i++)
		for(j=n-1,t=0;j<n+2;t++,j++)
			d[t][s]=screen_a[i][j];




			if(d[0][2]==1&&d[1][1]==1&&d[1][2]==1&&d[2][1]==1)
			{
				d[1][0]=d[2][0]=d[0][1]=1;
			    d[2][1]=d[0][2]=d[1][2]=0;

			}
			if(d[0][1]==1&&d[1][1]==1&&d[1][2]==1&&d[2][2]==1)
			{
				d[0][0]=d[1][0]=d[2][1]==1;
                d[1][2]=d[2][2]=d[0][1]=0;

			}

			if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[1][1]==1)
            {
                d[0][1]=d[1][1]=d[2][1]=d[1][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;

            }

            if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[2][1]==1)
            {
                d[0][1]=d[1][1]=d[2][1]=d[2][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;

            }

            if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[0][1]==1)

            {
                d[0][1]=d[1][1]=d[2][1]=d[0][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;
            }

	for(i=0,s=m,t=n-1;i<3;i++)
		for(j=0;j<3;j++)
		{

			if(d[i][j]==1)
				if(screen_a[m+i][t+j]>=2)
					return 0;

        }
	return 1;
}

//====================================================
int  cannot_trans()//不能转置，即不够空间转置
{

	if(line_mark==1)
		if(n<2||n>10)
			return 1;
	if(line_mark==2)
		if(m>23)
			return 1;
	if(n-1<0||n+1>=12)
		return 1;
	if(!try_trans())
		return 1;
	if(screen_a[m][n-1]==1&&screen_a[m][n]==1&&screen_a[m+1][n-1]==1&&screen_a[m+1][n]==1)
		return 1;


	return 0;
}


//=====================================================
int trans()//转置
{


		int i,j,s,t;


		int d[4][4]={0};
	//	if(c[][]==1&&c[][]==1&&c[][]==1&&c[][]==1)
			if(line_mark==1)
			{
				screen_a[m][n-2]=screen_a[m][n-1]=screen_a[m][n+1]=1;
				screen_a[m-2][n]=screen_a[m-1][n]=screen_a[m+1][n]=0;
				line_mark=0;
				find_mark();
				printf_full();
				return 1;
			}

			if(line_mark==2)
			{
				screen_a[m-2][n]=screen_a[m-1][n]=screen_a[m+1][n]=1;
				screen_a[m][n-2]=screen_a[m][n-1]=screen_a[m][n+1]=0;
				line_mark=0;
				find_mark();
				printf_full();
				return 1;
			}



			for(i=m,s=2;i<m+3;s--,i++)
			for(j=n-1,t=0;j<n+2;t++,j++)
                if(screen_a[i][j]<2)
				d[t][s]=screen_a[i][j];
	//	for(i=m-1,s=3;i<4;i++,s--)
	//		for(j=1,t=1;j<4;j++,t++)
	//			b[t][s]=c[i][j];


			if(d[0][2]==1&&d[1][1]==1&&d[1][2]==1&&d[2][1]==1)
			{
				d[1][0]=d[2][0]=d[0][1]=1;
			    d[2][1]=d[0][2]=d[1][2]=0;

			}
			if(d[0][1]==1&&d[1][1]==1&&d[1][2]==1&&d[2][2]==1)
			{
				d[0][0]=d[1][0]=d[2][1]=1;
                d[1][2]=d[2][2]=d[0][1]=0;

			}

			if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[1][1]==1)
            {
                d[0][1]=d[1][1]=d[2][1]=d[1][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;

            }

            if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[2][1]==1)
            {
                d[0][1]=d[1][1]=d[2][1]=d[2][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;

            }

            if(d[0][2]==1&&d[1][2]==1&&d[2][2]==1&&d[0][1]==1)

            {
                d[0][1]=d[1][1]=d[2][1]=d[0][0]=1;
                d[0][2]=d[1][2]=d[2][2]=0;
            }


			for(i=0,s=m;i<3;s++,i++)
				for(j=0,t=n-1;j<3;t++,j++)
                {
                if(d[i][j]==0)
                  if(screen_a[s][t]>=2)
                       continue;
                screen_a[s][t]=d[i][j];
                }
		//system("cls");
		find_mark();
		printf_full();
		return 1;



}

//====================================================================
int go()
{

//	printf_full();
	find_point();
	if(!cannot_trans())
		trans();
	return 0;
}



//////////////////////////////////////////////////////////////////////////////////////


