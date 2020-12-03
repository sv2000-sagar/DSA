//  Circular Queue
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node * lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node * *Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node));
}

void enqueue(struct Queue *q,struct Node * x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node * x=NULL;

    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
        return q.front==q.rear;
}

void display(struct Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}

