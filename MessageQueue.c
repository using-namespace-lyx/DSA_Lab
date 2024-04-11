#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct queue
{
    int r,f;
    char data[5][20];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q,char item[])
{
    if(q->f==(q->r+1)%SIZE)
    {
        printf("\nFull");
    }
    else
    {
        q->r=(q->r+1)%SIZE;
        strcpy(q->data[q->r],item);

        if(q->f==-1)
        q->f=0;

    }
}

char* dequeue(QUEUE *q)
{
    if(q->f==-1)
    {
        printf("\nEmpty");
        return NULL;
    }

    char* del=q->data[q->f];

    if(q->f==q->r)
    q->f=q->r=-1;

    else
    q->f=(q->f+1)%SIZE;

    return del;
}

void display(QUEUE q)
{
    if(q.f==-1)
    printf("\nEmpty");

    else
    {
        int i;
        for(i=q.f;i!=q.r;i=(i+1)%SIZE)
        printf("%s\n",q.data[i]);
        printf("%s\n",q.data[i]);

    }
}

int main()
{
    QUEUE q;
    q.r=q.f=-1;
    char* del;
    int ch;
    char item[20];

    for(;;)
    {
        printf("\nChoice:");
        scanf("%d",&ch);
        getchar();

        switch(ch)
        {
            case 1:
            printf("\nItem:");
            gets(item);
            
            enqueue(&q,item);
            break;
            case 2:
            del=dequeue(&q);
            if(del!=NULL)
            printf("%s deleted",del);
            break;
            case 3:
            display(q);
            break;
        }
    }

}