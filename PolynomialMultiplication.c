#include<stdio.h>
#include<stdlib.h>

struct node
{
    int co,po;
    struct node* next;
};

typedef struct node NODE;

NODE* insertend(NODE * start,int co,int po)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;

    if(start==NULL)
    return temp;

    NODE *curr=start;

    while(curr->next!=NULL)
    curr=curr->next;

    curr->next=temp;

    return start;
}

void display(NODE *start)
{
    if(start==NULL)
    printf("Empty");

    NODE * curr=start;

    while(curr->next!=NULL)
    {
        printf("%d*x^%d+",curr->co,curr->po);
        curr=curr->next;
    }
    printf("%d*x^%d",curr->co,curr->po);
}

NODE *addterm(NODE *res,int co,int po)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;

    if(res==NULL)
    return temp;

    NODE* curr=res;
    int flag=0;

    while(curr!=NULL)
    {
        if(curr->po==po)
        {
            curr->co+=co;
            flag=1;
        }

        curr=curr->next;
    }

    if(flag==0)
    {
        res=insertend(res,co,po);
    }

    return res;
}

NODE *multiply(NODE *poly1,NODE *poly2)
{
    NODE *first,*second,*res;
    first=second=res=NULL;

    for(first=poly1;first!=NULL;first=first->next)
    for(second=poly2;second!=NULL;second=second->next)
    res=addterm(res,first->co*second->co,first->po+second->po);

    return res;
}

int main()
{
    int i,n,co,po;
    NODE *first,*second,*res;
    first=second=res=NULL;

    printf("\nEnter number of terms in poly1:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("\nEnter co and po of term %d:",i);
        scanf("%d%d",&co,&po);
        first=insertend(first,co,po);
    }

    printf("\nEnter number of terms in poly2:");
    scanf("%d",&n);


    for(i=1;i<=n;i++)
    {
        printf("\nEnter co and po of term %d:",i);
        scanf("%d%d",&co,&po);
        second=insertend(second,co,po);
    }

    printf("\nPoly1\n");
    display(first);
    printf("\nPoly2\n");
    display(second);

    res=multiply(first,second);
    printf("\nRes\n");
    display(res);


}