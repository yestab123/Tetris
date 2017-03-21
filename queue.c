/*
 * CopyRight (c) yestab123, shuzi, ZDJ
 * University course assignments at 2013
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "queue.h"

Queue Q;

//mark the remove line... with <queue.h>
int InitQueue(Queue *Q)
{
    (*Q).front=(*Q).rear=(Queue_POINT)malloc(sizeof(Queue_DATA));
    if(!(*Q).front)exit(0);
    (*Q).front->next=NULL;
    return OK;
}

int EnQueue(Queue *Q,int e)
{
    Queue_POINT p;
    p=(Queue_POINT)malloc(sizeof(Queue_DATA));
    if(!p)exit(0);
    p->MARK=e;
    p->next=NULL;
    (*Q).rear->next=p;
    (*Q).rear=p;
}

int DeQueue(Queue *Q,int *e)
{
    Queue_POINT p;
    if((*Q).rear==(*Q).front)return 0;
    p=(*Q).front->next;
    (*e)=p->MARK;
    (*Q).front->next=p->next;
    if((*Q).rear==p)(*Q).rear=(*Q).front;
    free(p);
    return OK;
}

int QueueEmpty(Queue Q)
{
    if ((Q.rear)==(Q.front))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*
int main()
{
    Queue Q;
    int i=0;
    int j=0;
    int e;
    InitQueue(&Q);
    while(i<3)
    {

    printf("Please Enter:");
    scanf("%d",&e);
    EnQueue(&Q,e);
    i++;
    }
    i=QueueEmpty(Q);

printf("\n\ni=%d",i);
    while(j<2)
    {
        e=0;
        DeQueue(&Q,&e);
        printf("\n\n%d",e);
        j++;
    }
    i=QueueEmpty(Q);
printf("\n\ni=%d",i);

    return 0;
}*/












