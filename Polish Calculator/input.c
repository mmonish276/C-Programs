//functions for input gathering & parsing
#include "calc.h"

void ungets(char s[])
{
    int j;
    for (j = 0; s[j] != '\0'; j++) //loops thru until length of string found
        ;

    int i;
    
    for (i = j -1; i >= 0; i--)
    {
        ungetch(s[i]);
    }
}

int getch(void) // get a (possibly pushed-back) character
{
    if (bufp > 0) 
    {
        //buffer has chars --> return most recently pushed-back char
        return buf[--bufp];
    } 
    
    else 
    {
        //read new character from standard input
        return getchar();
    }
}

void ungetch(int c) // push into input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    
    else 
    {
        buf[bufp++] = c; // Store the character (including EOF) in the buffer
    }
}

int get_line(char buf[], int max) // replaces getch() and unget() for simple functions (use as necessary)
{
    int c;
    int i = 0;
    while (i < max - 1 && (c = getchar()) != EOF && c != '\n') {
        buf[i++] = c;
    }
    if (c == '\n') {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return (c == EOF) ? EOF : 0;
}
