#include<stdio.h> //链表实现的单向图,双向图    深度优先搜索，广度优先搜索
#include<stdlib.h>
#include<stdbool.h>
#include"Queuestruct.h"
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
void BFS(ListGraph LG,Vertex V);
int IfEdge_double(ListGraph LG, Vertex V1, Vertex V2);
ListGraph BuildGraph(int Vertexnum);
void insertEdge_single(ListGraph LG, Edge E);
void insertEdge_double(ListGraph LG,Edge E);

int main(void)
{
    int N,v1;
    Edge E=malloc(sizeof(struct ENode));
    scanf("%d",&N);
    ListGraph LG=BuildGraph(N);
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&E->V1, &E->V2);
        insertEdge_double(LG,E);
    }
    while(1)
    {
        for(int i=0;i<100;i++)
            visited[i]=0;
        scanf("%d",&v1);
        BFS(LG,v1);
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

void insertEdge_single(ListGraph LG, Edge E)
{
    PtrToadjvNode NewNode=malloc(sizeof(struct adjvNode));
    NewNode->Vindex=E->V2;
    NewNode->next=LG->G[E->V1].FirstEdge;
    LG->G[E->V1].FirstEdge=NewNode;
}
void insertEdge_double(ListGraph LG, Edge E)
{
    PtrToadjvNode NewNode=malloc(sizeof(struct adjvNode));
    NewNode->Vindex=E->V2;
    NewNode->next=LG->G[E->V1].FirstEdge;
    LG->G[E->V1].FirstEdge=NewNode;
    PtrToadjvNode NewNode2 =malloc(sizeof(struct adjvNode));
    NewNode2->Vindex=E->V1;
    NewNode2->next=LG->G[E->V2].FirstEdge;
    LG->G[E->V2].FirstEdge=NewNode2;

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
int IfEdge_double(ListGraph LG, Vertex V1,Vertex V2)
{
    PtrToadjvNode temp=LG->G[V1].FirstEdge;
    while(temp)
    {
        if(temp->Vindex==V2)
            return 1;
        temp=temp->next;
    }
    return 0;
}
void BFS(ListGraph LG, Vertex V)
{
    Queue Q=CreateQueue(LG->Nvertex);
    PtrToadjvNode W;
    Enqueue(Q,V);
    visit(V);
    visited[V]=true;
    while(!IsEmpty(Q))
    {
        V=Dequeue(Q);
        for(W=LG->G[V].FirstEdge;W && !visited[W->Vindex];W=W->next)
        {
            Enqueue(Q,W->Vindex);
            visit(W->Vindex);
            visited[W->Vindex]=true;
        }
    }
}
