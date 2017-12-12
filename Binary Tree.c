#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* PtrToTreeNode;
struct TreeNode{
    int val;
    PtrToTreeNode left;
    PtrToTreeNode right;
};
typedef PtrToTreeNode Tree;



Tree BuildTree(int num)
{
    Tree T=malloc(sizeof(struct TreeNode));
    T->val=num;
    T->left=T->right=NULL;
    return T;
}

void Insert(Tree T, int num)
{
    if(!T->left)
    {
        T->left=malloc(sizeof(struct TreeNode));
        T->left->val=num;
        T->left->right=T->left->left=NULL;
    }
    else if(!T->right)
    {
        T->right=malloc(sizeof(struct TreeNode));
        T->right->val=num;
        T->right->right=T->right->left=NULL;

    }
    else
        Insert(T->left,num);

}
