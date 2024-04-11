#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

struct stack
{
    int top;
    float data[20];
};
typedef struct stack STACK;

void push(STACK*s , float item)
{
    s->data[++(s->top)]=item;

}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}



float prefixeval(STACK *s,char prefix[])
{
    float op1,op2,res;
    char sym;
    int i;

    for(i=strlen(prefix)-1;i>=0;i--)
    {
        sym=prefix[i];

        if(isdigit(sym))
        {
            push(s,sym-'0');
        }

        else
        {
            op1=pop(s);
            op2=pop(s);

            switch(sym)
            {
                case '+':
                res=op1+op2;
                break;
                case '-':
                res=op1-op2;
                break;
                case '*':
                res=op1*op2;
                break;
                case '/':
                res=op1/op2;
                break;
                case '^':
                res=pow(op1,op2);
                break;

            }

            push(s,res);
        }

    }

    return pop(s);
}

int main()
{
    STACK s;
    s.top=-1;
    char prefix[20];
    printf("\nEnter:");
    scanf("%s",prefix);
    printf("%f",prefixeval(&s,prefix));
}