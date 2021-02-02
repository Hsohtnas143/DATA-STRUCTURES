#include<stdio.h>
struct stack{
    int max;
    char a[100];
    int top;
};
int priority(struct stack *s)
{
    if(s->top == 0)
    {
        return 0;
    }
    else if(s->a[s->top - 1] == '(')
    {
        return 1;
    }
    else if(s->a[s->top - 1] == '+' || s->a[s->top - 1] == '-')
    {
        return 2;
    }
    else if(s->a[s->top - 1] == '*' || s->a[s->top - 1] == '/')
    {
        return 3;
    }
}
void push(int *val ,struct stack *s)
{
    s->a[s->top] = *val;
    s->top = s->top +1;

}
void popb(struct stack *s)
{
    while(s->a[s->top-1] != '(')
    {
        printf("%c",s->a[s->top-1]);
        s->top = s->top -1;
    }
    s->top = s->top -1;

}
void pop(struct stack *s)
{
    s->top = s->top-1;
    printf("%c",s->a[s->top]);
}
void main()
{
    struct stack s;
    s.top = 0;
    s.max = 100;
    char exp[100];
    scanf("%s",exp);
    char *val = exp;
    while(*(val)!='\0')
    {
        if(*(val) == '(')
        {
            push(val,&s);
            *(val++);
        }
        else if(*(val) == ')')
        {
            popb(&s);
            *(val++);
        }
        else if(*(val) == '+' || *(val) == '-')
        {
            while(1)
            {
                int x = priority(&s);
                if(x == 0 || x == 1)
                {
                    push(val,&s);
                    *(val++);
                    break;
                }
                else if( x == 2 || x == 3)
                {
                    pop(&s);
                }
            }
        }
        else if(*(val) == '*' || *(val) == '/')
        {
            while(1)
            {
                int x = priority(&s);
                if(x == 0 || x == 1 || x == 2)
                {
                    push(val,&s);
                    *(val++);
                    break;
                }
                else if(x == 3)
                {
                    pop(&s);
                }
            }
        }
        else
        {
            printf("%c",*(val));
            *(val++);
        }

    }
    while(s.top!=0)
    {
        pop(&s);
    }

}
