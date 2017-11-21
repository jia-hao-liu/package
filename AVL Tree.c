#include<stdio.h>
#include<stdlib.h>
#define Max(a,b) (((a)>(b))?(a):(b))

typedef struct AvlTreeNode* AvlTree;
typedef struct AvlTreeNode* Position;
struct AvlTreeNode{
        int element;
        AvlTree left;
        AvlTree right;
        int height;
};


int Height(AvlTree T);
AvlTree NewNode(int num);
AvlTree SingleRotationWithLeft(Position P);
AvlTree SingleRotationWithRight(Position P);
AvlTree DoubleRotationWithLeft(Position P);
AvlTree DoubleRotationWithRight(Position P);
AvlTree insert(AvlTree T,int num);

int main(void)
{
    int N,num;
    AvlTree T;

    scanf("%d",&N);
    scanf("%d",&num);
    T=NewNode(num);
    for(int i=1;i<N;i++)
    {
        scanf("%d",&num);
        T=insert(T,num);
    }
    //insert(T,5);
    printf("%d\n",T->element);
    return 0;

}

/*int Max(int a, int b){
    return a>b?a:b;
}*/
int Height(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->height;

}
AvlTree NewNode(int num)
{
    AvlTree T=(AvlTree)malloc(sizeof(struct AvlTreeNode));
    T->element=num;
    T->left=NULL;
    T->right=NULL;
    T->height=0;
    return T;
}

AvlTree SingleRotationWithLeft(Position P)
{
    Position temp=P->left;
    P->left=P->left->right;
    temp->right=P;
    P->height=Max(Height(P->left),Height(P->right))+1;
    temp->height=Max(Height(P->left),Height(P->right))+1;
    return temp;
}

AvlTree SingleRotationWithRight(Position P)
{
    Position temp=P->right;
    P->right=P->right->left;
    temp->left=P;
    P->height=Max(Height(P->left),Height(P->right))+1;
    temp->height=Max(Height(P->left),Height(P->right))+1;
    return temp;
}

AvlTree DoubleRotationWithLeft(Position P)
{
    Position temp=P->left->right;
    P->left->right=temp->left;
    temp->left=P->left;
    P->left=temp->right;
    temp->right=P;
    return temp;
}

AvlTree DoubleRotationWithRight(Position P)//̫�鷳
{
    Position temp=P->right->left;
    P->right->left=temp->right;
    temp->right=P->right;
    P->right=temp->left;
    temp->left=P;
    return temp;
}

AvlTree insert(AvlTree T, int num)
{
    if(T==NULL)
    {
        T=NewNode(num);
    }
    else
    {
        if(num>T->element)
        {
            T->right=insert(T->right,num);
            if(Height(T->right)-Height(T->left)==2)
                if(T->right->element>num)
                    T=DoubleRotationWithRight(T);
                else
                    T=SingleRotationWithRight(T);

        }
        else
        {
            T->left=insert(T->left,num);
            if(Height(T->left)-Height(T->right)==2)
                if(T->left->element<num)
                    T=DoubleRotationWithLeft(T);
                else
                    T=SingleRotationWithLeft(T);
        }
    }

    T->height=Max(Height(T->left),Height(T->right))+1;

    return T;
}
