#ifndef _RANKING_HEADER
#define _RANKING_HEADER

struct Data
{
	 int score;
	 char name[20];

}player[11]={0,"player?"},list[11]={0,"player?"};

int rank();
int write(int n);
int save();
int show();
int TOP();

#endif
