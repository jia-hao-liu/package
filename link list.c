#include<stdio.h>       //这里的链表都是带有头结点的链表
#include<stdlib.h>

typedef struct Node* ptrtoNode;
typedef ptrtoNode List;
struct Node{
    int num;
    ptrtoNode next;
};
List ReadList(void);
void PrintList(List L);
List MergeOrderedList(List L1, List L2);

int main(void)
{
    List L,L1,L2;
    L1=ReadList();
    L2=ReadList();
    //PrintList(L1);
    L=MergeOrderedList(L1, L2);
    PrintList(L1);
    return 0;
}

List ReadList(void)
{
    int N;
    puts("Please input the number of your data:");
    scanf("%d", &N);
    List L,temp;
    L=malloc(sizeof(struct Node));
    temp=L;
    while(N--)
    {
        temp->next=malloc(sizeof(struct Node));
        scanf("%d", &temp->next->num);
        temp=temp->next;

    }
    temp->next=NULL;
    return L;

}

void PrintList(List L)
{
    List temp;
    temp=L;
    while(temp->next)
    {
      printf("%d ", temp->next->num);
      temp=temp->next;
    }
}
List MergeOrderedList(List L1, List L2)
{
  List temp1,temp2;
  temp1=L1;
  temp2=L2;

  while(temp1->next && temp2->next)
  {
    if(temp1->next->num>=temp2->next->num)
    {


        List temp=malloc(sizeof(struct Node));
        temp->num=temp2->next->num;
        temp->next=temp1->next;
        temp1->next=temp;
        temp1=temp1->next;
        temp2=temp2->next;
    }

    else if(temp1->next->num<temp2->next->num)
        temp1=temp1->next;


  }

  while(temp2->next)
  {
    temp1->next=temp2->next;
    temp2->next=NULL;
  }
  return L1;
}
