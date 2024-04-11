#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct stack
{
    int top;
    char data[200];
};

typedef struct stack STACK;

void push(STACK*s,char item)
{
    s->data[++(s->top)]=item;
}

char pop(STACK*s)
{
    return s->data[(s->top)--];
}

int preced(char sym)
{
    switch(sym)
    {
        case '^':
        return 5;
        case '*':
        case '/':
        return 3;
        case '+':
        case '-':
        return 1;
    }
}

void infixtopostfix(STACK* s, char infix[])
{
    int i,j=0;
    char sym,del,postfix[200];

    for(i=0;infix[i];i++)
    {
        sym=infix[i];

        if(isalnum(sym))
        postfix[j++]=sym;

        else{
            switch(sym)
            {
                case '(':
                push(s,sym);
                break;

                case ')':
                del=pop(s);
                while(del!=')')
                {
                    postfix[j++]=del;
                    del=pop(s);
                }
                break;

                case '^':
                case '*':
                case '/':
                case '+':
                case '-':
                if(s->top==-1||s->data[s->top]=='(')
                push(s,sym);
                else{
                    while( preced(s->data[s->top])>=preced(sym) && s->top!=-1 && s->data[s->top]!='(')
                    postfix[j++]=pop(s);

                    push(s,sym);

                }
                break;
            }
        }
    }

    while(s->top!=-1)
    postfix[j++]=pop(s);

    postfix[j]='\0';

    printf("%s",postfix);
}
int main()
{
    STACK s;
    s.top=-1;
    char infix[200];
    printf("\nEnter:");
    scanf("%s",infix);
    infixtopostfix(&s,infix);
    return 0;
}