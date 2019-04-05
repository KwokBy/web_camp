#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define OK    1
#define ERROR 0
struct node
{
    double data;
    struct node *next;
};

typedef struct node Node;

struct stack
{
    Node *top;
    int count;
};

typedef struct stack Stack;

double InitStack(Stack *S);
double EmptyStack(Stack *S);
double Push(Stack *S, int e);
double Pop(Stack *S);
double GetTop(Stack *S);
int Priority(char s);

#endif // STACK_H_INCLUDED

