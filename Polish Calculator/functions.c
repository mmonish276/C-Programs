// functions outside math operations (ie. stack management)
#include "calc.h"

// push some value onto stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;

    else
        printf("error: stack full, can't push %g\n", f);
}

// pop + return top val. from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
   
    else 
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double peek(void)   //for finding out top val. on stack
{
    if (sp > 0)
        return val[sp - 1]; //top element (stack build= bottom --> top: LIFO)

    else 
    {
        printf("error: top stack element not found\n");
        return 0.0;
    }
}

void duplicate(void) //duplicate top element
{
    if (sp < MAXVAL - 1)
    {
        val[sp] = val[sp - 1]; 
        sp++;
    }

    else
        printf("error: full stack, no duplication possible\n");
}

void clear(void)
{
    sp = 0; //reset (new elements will overwrite each other @ this pos.--> empty stack)
}

void swap(void) //swap top 2 elements
{
    double swap_holder;
    if (sp >= 2 && sp < MAXVAL)
    {
        swap_holder= val[sp-1]; //top val (temporary var. )
        val[sp - 1]= val[sp - 2];
        val[sp - 2] = swap_holder;
    }

    else
        printf("error: stack has less than two elements, can't swap\n");
}
