#ifndef _QUEUE_HEADER_
#define _QUEUE_HEADER_


//////queue.c///
#define OK 1;
#define ERROR 0;


typedef struct Queue_DATA_s
{
  int MARK;
  struct Queue_DATA *next;
}Queue_DATA,*Queue_POINT;

typedef struct Queue_s
{
  Queue_POINT front;
  Queue_POINT rear;
}Queue;


int InitQueue(Queue *Q);
int EnQueue(Queue *Q,int e);
int DeQueue(Queue *Q,int *e);
int QueueEmpty(Queue Q);

#endif
