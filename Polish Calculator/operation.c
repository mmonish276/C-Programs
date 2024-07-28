//math operations parsing function
#include "calc.h"

//get numeric vals for functions/operands themselves
int getop(char s[])
{
    int i, c;

    // Skip whitespace
    while ((c = getch()) == ' ' || c == '\t')
        ;
    s[0] = c;
    s[1] = '\0';

    if (c == EOF)
        return EOF;

    // numbers handling (ie. arguments)
    if (isdigit(c) || c == '.') 
    {
        if (isdigit(c))
            i = 0;
            while (isdigit(s[++i] = c = getch()))
                ;

        if (c == '.')
            while (isdigit(s[++i] = c = getch()))
                ;

        s[i] = '\0';

        if (c != EOF)
            ungetch(c);

        return NUMBER;
    }

    // functions handling
    if (isalpha(c)) 
    {
        i = 0;
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if ((strcmp(s, "sin") == 0) || (strcmp(s, "exp") == 0) || (strcmp(s, "pow") == 0)) 
        {
            return FUNCTION;
        }
        ungetch(c);
        return s[0];
    }

    // operators handling
    if (c == '\n' || strchr("+-*/%dscp", c))
        return c;

    return c; // Return operator or other characters
}
