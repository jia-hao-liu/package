#include<stdio.h> //分离链接法实现散列表
#include<stdlib.h>

typedef struct LNode* PtrToLnode;
struct LNode{
    int num;
    int frequency;
    PtrToLnode next;

};
typedef PtrToLnode List;
typedef PtrToLnode Position;

typedef struct TableNode* HashTable;
struct TableNode{
    int TableSize;
    List Heads;
};

int NextPrime(int N);
int Hash(int N,int M);
HashTable CreateTable(int Size);
Position find(HashTable H, int num);
void insert(HashTable H, int num);

int main(void)
{
    Position P;
    int N,num,count=0,num_record;
    puts("Please input the number of your data:");
    scanf("%d",&N);
    HashTable H=CreateTable(N);
    puts("Please input your data:");
    for(int i=0;i<N;i++)
    {
        scanf("%d",&num);
        insert(H,num);
    }

    for(int i=0;i<H->TableSize;i++)
    {
        P=H->Heads[i].next;
        while(P)
        {
            if(P->frequency>count)
            {
                count=P->frequency;
                num_record=P->num;
            }
            P=P->next;

        }
    }
    printf("%d %d\n",count, num_record);

    return 0;

}

int NextPrime(int N)
{
    int i=0;
    while(i<N-1)
    {
        for( i=2;i<N;i++)
        {
            if(N%i==0)
                break;
        }
        N++;
    }
    return i;
}

int Hash(int N, int M)
{
    return N%M;
}
HashTable CreateTable(int Size)
{
    HashTable hash;
    hash=malloc(sizeof(struct TableNode));
    hash->TableSize=NextPrime(Size);
    hash->Heads=malloc(sizeof(struct LNode)*hash->TableSize);
    for(int i=0;i<hash->TableSize;i++)
    {
        hash->Heads[i].num=-1;
        hash->Heads[i].next=NULL;
        hash->Heads[i].frequency=0;
    }
    return hash;
}

Position find(HashTable H, int num)
{
    Position P;
    int index;
    index=Hash(num,H->TableSize);
    P=H->Heads[index].next;
    while(P && P->num!=num)
        P=P->next;
    return P;
}
void insert(HashTable H,int num)
{
    Position P,NewNode;
    int index;
    P=find(H,num);
    if(!P)
    {
        NewNode=malloc(sizeof(struct LNode));
        index=Hash(num,H->TableSize);
        NewNode->next=H->Heads[index].next;
        H->Heads[index].next=NewNode;
        NewNode->num=num;
        NewNode->frequency=1;
    }
    else
    {
        P->frequency++;
    }

}

