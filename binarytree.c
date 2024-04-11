#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

typedef struct node NODE;

NODE *createnode(int item)
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

void insertleft(NODE *root,int item)
{
    root->left=createnode(item);
    if(item==-1)
    root->left=NULL;
}

void insertright(NODE *root,int item)
{
    root->right=createnode(item);
    if(item==-1)
    root->right=NULL;
}

NODE* create_binary_tree(NODE* root)
{
    int item;
    printf("\nEnter root node value:");
    scanf("%d",&item);
    root=createnode(item);

    NODE* curr=root;

    printf("\nLevel 1:");
    printf("\nL:");
    scanf("%d",&item);
    insertleft(root,item);
    printf("R:");
    scanf("%d",&item);
    insertright(root,item);

    printf("\nLevel 2:");
    curr=root->left;
    printf("\nLL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("LR:");
    scanf("%d",&item);
    insertright(curr,item);

    curr=root->right;
    printf("\nRL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("RR:");
    scanf("%d",&item);
    insertright(curr,item);

    printf("\nLevel 3:");
    curr=root->left->left;
    printf("\nLLL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("LLR:");
    scanf("%d",&item);
    insertright(curr,item);

    curr=root->left->right;
    printf("\nLRL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("LRR:");
    scanf("%d",&item);
    insertright(curr,item);

    curr=root->right->left;
    printf("\nRLL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("RLR:");
    scanf("%d",&item);
    insertright(curr,item);

    curr=root->right->right;
    printf("\nRRL:");
    scanf("%d",&item);
    insertleft(curr,item);
    printf("RRR:");
    scanf("%d",&item);
    insertright(curr,item);

    return root;
}



void inorder(NODE*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int countnodes(NODE *root)
{
    if(root==NULL)
    return 0;
    else
    return (countnodes(root->left)+countnodes(root->right)+1);
}

int countleaf(NODE* root)
{
    if(root==0)
    return 0;
    else if(root->left==NULL && root->right==NULL)
    return 1;
    else 
    return countleaf(root->left)+countleaf(root->right);
}

int countnonleaf(NODE* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    return 0;

    else
    return countnonleaf(root->left)+countnonleaf(root->right)+1;
}

int height(NODE *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int h1,h2;
        h1=height(root->left);
        h2=height(root->right);

        return(h1>h2?h1+1:h2+1);
    }
}

int main()
{
    NODE *root=NULL;
   root=create_binary_tree(root);

    inorder(root);
   
    printf("\nLeaf:%d",countleaf(root));
     printf("\nLNON eaf:%d",countnonleaf(root));
      printf("\nnodes:%d",countnodes(root));
       printf("\nheight:%d",height(root));
}