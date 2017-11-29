#include<stdio.h> //链表实现的单向图
#include<stdlib.h>
#include<stdbool.h>
#define MaxVertex 100


bool visited[MaxVertex]={0};
typedef int Vertex;
typedef struct adjvNode* PtrToadjvNode;
struct adjvNode{
    Vertex Vindex;
    PtrToadjvNode next;
};
typedef struct ENode* Edge;
struct ENode{
    Vertex V1,V2;
};
struct VNode{
    PtrToadjvNode FirstEdge;
};
typedef struct VNode AdjList[MaxVertex];
typedef struct GraphNode* ListGraph;
struct GraphNode{
    int Nvertex;
    int Nedge;
    AdjList G;

};
void visit(Vertex V);
void DFS(ListGraph LG,Vertex V);
ListGraph BuildGraph(int Vertexnum);
void insertEdge(ListGraph LG, Edge E);

int main(void)
{
    int N,v1,v2;
    Edge E=malloc(sizeof(struct ENode));
    scanf("%d",&N);
    ListGraph LG=BuildGraph(N);
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&E->V1, &E->V2);
        insertEdge(LG,E);
    }
    while(1)
    {
        for(int i=0;i<100;i++)
            visited[i]=0;
        scanf("%d",&v1);
        DFS(LG,v1);
    }
    return 0;
}

ListGraph BuildGraph(int Vertexnum)
{
    ListGraph LG=malloc(sizeof(struct GraphNode));
    LG->Nvertex=Vertexnum;
    LG->Nedge=0;
    for(int i=0;i<Vertexnum;i++)
        LG->G[i].FirstEdge=NULL;

    return LG;
}

void insertEdge(ListGraph LG, Edge E)
{
    PtrToadjvNode NewNode=malloc(sizeof(struct adjvNode));
    NewNode->Vindex=E->V2;
    NewNode->next=LG->G[E->V1].FirstEdge;
    LG->G[E->V1].FirstEdge=NewNode;
}

int ifconnection(ListGraph LG, Vertex V1, Vertex V2)
{
    int flag;

    PtrToadjvNode temp;
    temp=LG->G[V1].FirstEdge;
    while(temp)
    {
        if(temp->Vindex==V2)
            flag=1;
        else
        {

                flag=ifconnection(LG,temp->Vindex,V2);
                temp=temp->next;
                if (flag==1)
                    return 1;
        }
    }
    temp=LG->G[V2].FirstEdge;
    while(temp)
    {
        if(temp->Vindex==V1)
            return 1;
        else
        {
            flag=ifconnection(LG,V1,temp->Vindex);
            temp=temp->next;
            if(flag==1)
                return 1;

        }
    }
    return 0;
}
void visit(Vertex V)
{
    printf("%d  ", V);
}
void DFS(ListGraph LG,Vertex V)
{
    PtrToadjvNode W;
    visit(V);
    visited[V]=true;
    for(W=LG->G[V].FirstEdge;W;W=W->next)
        if(!visited[W->Vindex])
            DFS(LG,W->Vindex);
}
