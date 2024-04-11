#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left,*right;
}NODE ;

NODE *createnode(int item)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

NODE* insertbst(NODE *root,int item)
{
    NODE* temp=createnode(item);

    if(root==NULL)
    return temp;

    else
    {
        if(item<root->data)
        root->left=insertbst(root->left,item);

        else
        root->right=insertbst(root->right,item);
    }

    return root;
}

NODE* inordersuccessor(NODE* root)
{
    NODE* curr=root;
    while(curr->left!=NULL)
    curr=curr->left;

    return curr;
}

NODE *delete(NODE *root,int key)
{
    NODE* temp;
    if(root==NULL)
    return NULL;

    if(key<root->data)
    root->left=delete(root->left,key);

    else if(key>root->data)
    root->right=delete(root->right,key);

    else{
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;

        }

        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;

        }

        temp=inordersuccessor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;

}

void inorder(NODE* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main()
{int ch,item;
NODE *root=NULL;
    for(;;)
    {
        printf("\nChoice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nItem:");
            scanf("%d",&item);
            root=insertbst(root,item);
            break;
            case 2:
            printf("\nKey:");
            scanf("%d",&item);
            root=delete(root,item);
            break;
            case 3:
            inorder(root);
            break;
            default:
            exit(0);
            
        }

    }
}