#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5

struct queue
{
    int front,rear;
    int items[QUEUESIZE];
    int count;
};
int empty(struct queue *pq)
{
    if(pq->count==0)
        return 1;
    else
        return 0;
}
void insert(struct queue *pq,int x)
{
    if(pq->count==QUEUESIZE)
    {
        printf("Queue overflow.Cannot insert\n");
        exit(1);
    }
    (pq->count)++;
    if(pq->rear==QUEUESIZE-1)
        pq->rear=0;
    else
        (pq->rear)++;;
    pq->items[pq->rear]=x;
}
int removes(struct queue *pq)
{
    int t;
    if (empty(pq))
    {
        printf("Queue overflow.Cannot\n");
        exit(1);
    }
    t=pq->items[pq->front];
    (pq->front)--;
    if(pq->front==QUEUESIZE-1)
        pq->front=0;
    else
        (pq->front)++;
    return  t;
}
void show(struct queue q)
{
    int i;
    printf("Queue from frontmost element is as shown:\n ");
    if(q.count!=0)
    {
        if(q.front<=q.rear)
            for(i=q.front;i<=q.rear;i++)
            printf("%d",q.items[i]);
        if(q.front>q.rear)
        {
            for(i=q.front;i<QUEUESIZE-1;i++)
                printf("%d",q.items[i]);
            for(i=0;i<q.rear;i++)
                printf("%d",q.items[i]);
        }
    }
}
void main()
{
    int x,ch;
    struct queue q;
    q.rear=-1;
    q.front=0;
    q.count=0;
    do
    {
        printf("\n Menu\n");
        printf("1:insert\n");
        printf("2:remove\n");
        printf("3:exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the no to be inserted:");
            scanf("%d",&x);
            insert(&q,x);
            show(q);
            break;

            case 2:
            x=removes(&q);
            printf("Element removed is %d\n",x);
            show(q);
            break;
            case 3:
            break;

        }
    }
    while(ch!=3);
}

