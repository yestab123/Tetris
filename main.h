#define STAY 2 //the block stop
#define DOWN 1 // which block is moving
int FLUSHTIME=100;//Drop time 500ms;
int KEYTIME=10;//Next Key Time 50ms;
int STARTTIME=10;//the time for the new block to move first;
int WAITINGTIME=20;//the time waiting for next block 1500ms
int GAMEOVER_WAITINGTIME=1200;
int STATUS=0;//GAME STATUS MARK;
int MARK;// 200 that anything is done.
int MARK_LINE;
int FORECAST;
int FORECAST_ARRAY[4][4];
int PAUSE=0;//PAUSE status mark;
int testnum=0;
int setCOLOR=0;//blocks with color;1=red,2=blue,3=green,4=yellow,0=;
int setCOLORfore=0;
int COLORNUM=5;
int downCOLOR=0;
int queue_mark;//mark miss queue
HANDLE setHandleaa;//句柄声明
COORD setCOORD;//定位结构体
clock_t clockNow,clockLast;//remeber two time.


//Function in main.c
void setXY(int,int);
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
#define	CLOCKS_PER_SEC	((clock_t)1000)//time//它用来表示一秒钟会有多少个时钟计时单元
int LEVEL=1;
int GRADE=0;
float dropTIME=0.57F;
float oneTIME=0.57F;//Level time;
float twoTIME=0.51F;
float threeTIME=0.47F;
float fourTIME=0.42F;
float fiveTIME=0.39F;
float sixTIME=0.30F;

/////////////


//////queue.c///
#define OK 1;
//#define ERROR 0;


typedef struct Queue_DATA
{
    int MARK;
    struct Queue_DATA *next;
}Queue_DATA,*Queue_POINT;

typedef struct Queue
{
    Queue_POINT front;
    Queue_POINT rear;
}Queue;

Queue Q;

///////////////////////////////////


int a[24][12]={0};
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


