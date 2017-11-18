#include<stdio.h>
#include"library.h"
typedef struct Node* ptrtoNode;
typedef ptrtoNode List;
struct Node{
    int num;
    ptrtoNode next;
};
List ReadList(void);

int main(void)
{
    ReadList();
    return 0;
}
