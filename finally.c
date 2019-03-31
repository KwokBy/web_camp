#include "D:\calcul\finally.h"
#include <stdio.h>
#include <stdlib.h>

double InitStack(Stack *S)
{
    S->top = NULL;
    S->count = 0;

    return OK;
}


double EmptyStack(Stack *S)
{
    return (S->count == 0) ? OK : ERROR;
}


double Push(Stack *S, int e)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;

    return OK;
}


double GetTop(Stack *S)
{
    if (NULL == S->top)
    {
        return ERROR;
    }

    return (S->top->data);
}


int Priority(char s)
{
    switch(s)
    {
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default :
            return 0;
    }
}


double Pop(Stack *S)
{
    double e;

    if (NULL == S->top)
    {
        return ERROR;
    }

    Node *p = S->top;
    e = p->data;
    S->top = p->next;
    free(p);
    S->count--;

    return e;
}

