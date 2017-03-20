#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ranking_list.h"

extern int GRADE;

//int ps=1;      //当前玩家分数
#define DEBUG 1
	//排序函数
int rank()
{
	 int n=1;
	 int i;
	  FILE* fp;
	 if((fp=fopen("data.dat","rb"))==NULL)
	 {
		 printf("Can't open show file!\n");
		 exit(0);
	 }for(i=0;i<10;i++)
        { //fseek(fp,sizeof(struct Data),0); 
            if(fread(&player[i],sizeof(struct Data),1,fp)!=1) 
                printf(" !!%d!! rank()File read error!\n",i+1);
        }
   fclose(fp);
	 while(player[n].score>=GRADE&&n<10)
       {
           n++;
       }
	 for(i=10;i>n;i--)
       {
           player[i]=player[i-1];
       }

	 /*if(n==11)
	 {
		 printf("Your score just two step from the rank of TOP 10,come on!\n\n");

	 }
	 else
	 {
		 printf("New record beater! Gelivable!!! \n\n");
	 }*/
	 return n;
}
	//录入函数
int write(int n)
{
    player[n].score=GRADE;
    /*printf("please sign your name and press Enter to end.\n");*/
    scanf("%s",player[n].name);
}

 /*交换函数
int exchang()
{
	 player[11]=player[n];
	 player[n]=player[p];
	 player[p]=player[11];
}
*/

	//玩家记录录入函数
int save()
{
    FILE* fp;
    int i;

    if((fp=fopen("data.dat","wb"))==NULL)
        {
            printf("Can't open save file!\n");
            return 0;
        }
    for(i=0;i<10;i++)
        {
            if(fwrite(&player[i],sizeof(struct Data),1,fp)!=1)
                printf("File write error!\n");
            //fseek(fp,i*sizeof(struct Data),0);
            return 0;
        }
    fclose(fp);


}

	//显示排行榜
int show()
{
	 int i=0;
	 FILE* fp;
	 system("cls");
	 if((fp=fopen("data.dat","rb"))==NULL)
	 {
		 printf("Can't open show file!\n");
		 exit(0);
	 }
	 printf("\t\t\tTop10 list\n");
	 printf("------------------------------------------------------------------\n");
	 printf("\t rank\t\tscore\t\tplayer\n");
	 printf("------------------------------------------------------------------\n");

	 while(i<10)
	 {  
	  fseek(fp,i*sizeof(struct Data),0);
	 if(fread(&player[i],sizeof(struct Data),1,fp)!=1)
	 printf(" !!%d!! show()File read error!",i+1);
		 printf("\t%4d.\t\t%5d\t\t%s\n",i+1,player[i].score,player[i].name);
		
		 i++;
	 }
	  fclose(fp);
	 printf("------------------------------------------------------------------\n");
	 printf("close after 5 seconds!");
Sleep(5000);
GAMECHOICE();
}

int TOP()
{
	 int n;
	 n=rank();
	 write(n);
	 save();


}
/*int main()
{
    TOP();
	show();
}
*/
