#include<stdio.h>         //链表实现的队列
#include<stdlib.h>

typedef struct Node* PtrToNode;
struct Node{
    int num;
    PtrToNode next;
};
typedef PtrToNode Position;
struct QNode{
    Position front,rear;
    int MaxSize;
};
typedef struct QNode* Queue;

Queue CreateQueue(int MaxSize);
int Isfull(Queue Q);
int IsEmpty(Queue Q);
void Enqueue(Queue Q,int num);
int Dequeue(Queue Q);

int main(void)
{
    int N,num;
    Queue Q;
    scanf("%d", &N);
    Q=CreateQueue(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        Enqueue(Q,num);
    }
    printf("%d\n",Dequeue(Q));
    while(scanf("%d",&num))
    {
        switch(num)
        {
        case 1:
            printf("%d\n",Isfull(Q));
            break;
        case 2:
            printf("%d\n",IsEmpty(Q));
            break;
        case 3:
            printf("%d\n",Dequeue(Q));
            break;
        default:
            Enqueue(Q,num);
            break;
        }
    }
    return 0;
}

Queue CreateQueue(int MaxSize)
{
    Queue Q=malloc(sizeof(struct QNode));
    Q->MaxSize=MaxSize;
    Q->rear=NULL;
    Q->front=NULL;

}

int Isfull(Queue Q)
{
    int count=0;
    Position temp=Q->front;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    if(count==Q->MaxSize)
        return 1;
    else
        return 0;
}

int IsEmpty(Queue Q)
{
    if(Q->front!=NULL)
        return 0;
    else
        return 1;
}
void Enqueue(Queue Q, int num)
{
    if(Isfull(Q))
    {
        printf("队列已满！\n");
        return;
    }
    if(IsEmpty(Q))
    {
        PtrToNode NewNode=malloc(sizeof(struct Node));
        NewNode->num=num;
        NewNode->next=NULL;
        Q->front=NewNode;
        Q->rear=NewNode;
    }
    else
    {
        PtrToNode NewNode=malloc(sizeof(struct Node));
        NewNode->num=num;
        NewNode->next=NULL;
        Q->rear->next=NewNode;
        Q->rear=NewNode;
    }
}

int Dequeue(Queue Q)
{
    Position P;
    int returnnum;
    if(IsEmpty(Q))
    {
        printf("队列已空！\n");
        return 0;
    }
    if(Q->front==Q->rear)
    {
        P=Q->front;
        returnnum=P->num;
        Q->front=Q->rear=NULL;

    }
    else
    {
        P=Q->front;
        returnnum=P->num;
        Q->front=P->next;
    }
    free(P);
    return returnnum;

}
