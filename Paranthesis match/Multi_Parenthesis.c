#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflowl Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// char stackTop(struct stack* sp){
//     return sp->arr[sp->top];
// }
int match (char a , char b){
    if (a== '{' && b=='}'){
        return 1;
    }
    if (a == '(' && b ==')'){
        return 1;
    }
    if (a == '[' && b ==']'){
        return 1;
    }
   return 0;
}
int paranthesisMatch(char *exp)
{
    // Create and initialize the Stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    // Loops
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] =='{' || exp[i] =='[')
        { push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] =='}' || exp[i] ==']' )
        { if (isEmpty(sp)){
            return 0;
        }
        popped_ch = pop(sp);
        if (!match (popped_ch , exp[i])){
            return 0;
        }
        }
    }

    // Condition
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
   // Enter you Expression
    char * exp = "((8){(9 - 8)})";  //"((8){(9 -] 8)})" Not balanced  
     
    // Check if stack is Empty
    if (paranthesisMatch(exp))
    {
        printf("The parenthesis is balanced ");
    }
    else
    {
        printf("The parenthesis is not balanced ");
    }

    return 0;
}