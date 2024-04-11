#include<stdio.h>
#include<stdlib.h>

void heapify(int a[10],int n)
{
    int i,j,k,v,flag=0;

    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];

        while(!flag && 2*k<=n)
        {
            j=2*k;

            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }
            }

            if(v>=a[j])
            flag=1;

            else{
                a[k]=a[j];
                k=j;
            }
        }

        a[k]=v;
        flag=0;
    }
}

int main()
{
    int i,n,a[10],ch;

    
    for(;;)
    {
        printf("\n1.Create heap\n2.Extract max\n3.Exit\nRead choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter n:");
            scanf("%d",&n);

            printf("\nEnter elements\n");
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);

            heapify(a,n);

            printf("\nAfter heapify\n");

            for(i=1;i<=n;i++)
            printf("%d\t",a[i]);

            break;

            case 2:

            printf("\nMax element:%d",a[1]);

            if(n>=1)
            {
                a[1]=a[n];
                n--;

                if(n!=0)
                {
                    heapify(a,n);
                    printf("\nElements after re construction of heap\n");
                    for(i=1;i<=n;i++)
                    printf("%d\t",a[i]);

                }
                else
                printf("\nNo heap can be reconstructed");
            }

            break;

            default:
            exit(0);
        }
    }
}