#include<stdio.h>    //插入或删除操作先考虑是否空或满！！！！！！！！！！！！！！！！！！！！！！！
#include<stdlib.h>
#define MAXSIZE 100
#define MINDATA -1

typedef struct HeapNode* Heap;
struct HeapNode{
    int* element;
    int Capacity;
    int Size;

};

Heap BuildEmptyHeap(int MaxElements);
void Insert(Heap H,int num);

int main(void)
{
    int N,num,time,index;
    Heap H;
    //读入数据个数
    scanf("%d", &N);
    scanf("%d",&time);
    //建空堆
    H=BuildEmptyHeap(MAXSIZE);
    //将数据插入
    while(N--)
    {
        scanf("%d",&num);
        Insert(H,num);
    }
    //读入要打印的位置并打印
    while(time--)
    {
        scanf("%d", &index);
        for(int i=index;i>0;i/=2)
            printf("%d ",H->element[i]);
    }
    return 0;

}

Heap BuildEmptyHeap(int MaxElements)
{
    Heap H;
    H=(Heap)malloc(sizeof(struct HeapNode));
    H->element=(int)malloc(sizeof(int)*(MaxElements+1));
    H->Capacity=MaxElements;
    H->Size=0;
    H->element[0]=MINDATA;
    return H;
}

void Insert(Heap H,int num)
{
    //判断堆是否满了
    if(H->Size==H->Capacity)
        return;
    int i;
    for(i=++H->Size;H->element[i/2]>num;i/=2)
    {
        H->element[i]=H->element[i/2];

    }
    H->element[i]=num;

}
