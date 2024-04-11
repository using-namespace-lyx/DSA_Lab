#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

NODE * enqueue(NODE *last,int item)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=item;
    
    if(last==NULL)
    {
        temp->next=temp;
        return temp;
    }

    temp->next=last->next;
    last->next=temp;
    return temp;
}

NODE *dequeue(NODE *last)
{
    if(last==NULL)
    return NULL;

    if(last->next==last)
    {
        printf("\n%d deleted",last->data);
        free(last);
        return NULL;
    }

    NODE *temp=last->next;
    last->next=temp->next;
    printf("\n%d deleted",temp->data);
    free(temp);
    return last;


}

void display(NODE * last)
{
    if(last==NULL)
    {
        printf("\nEmpty");
        return;
    }
    printf("\nContents\n");
    NODE *curr=last->next;
    while(curr!=last)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }

    printf("%d\t",curr->data);
}

int main()
{
    NODE *last=NULL;
    int item,ch;
    for(;;)
    {
        printf("\nChoice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nItem:");
            scanf("%d",&item);
            last=enqueue(last,item);
            break;
            case 2:
            last=dequeue(last);
            break;
            case 3:
            display(last);
            break;
            default:
            exit(0);
        }
    }
}