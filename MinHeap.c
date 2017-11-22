#include<stdio.h>    //�����ɾ�������ȿ����Ƿ�ջ�������������������������������������������������
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
    //�������ݸ���
    scanf("%d", &N);
    scanf("%d",&time);
    //���ն�
    H=BuildEmptyHeap(MAXSIZE);
    //�����ݲ���
    while(N--)
    {
        scanf("%d",&num);
        Insert(H,num);
    }
    //����Ҫ��ӡ��λ�ò���ӡ
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
    //�ж϶��Ƿ�����
    if(H->Size==H->Capacity)
        return;
    int i;
    for(i=++H->Size;H->element[i/2]>num;i/=2)
    {
        H->element[i]=H->element[i/2];

    }
    H->element[i]=num;

}
