//This program uses recursion to reverse a string in place

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void reverse(int, int, char s[]);
int main()
{
    char string[MAX];
    int len;

    printf("String: ");
    scanf("%s", string);

    for (len = 0; string[len] != '\0' && len < MAX; len++)
        ;

    reverse(len, 0, string);
    printf("Reversed: %s\n", string);
}

void reverse(int length, int start, char s[])
{
    length = length - 1;

    if (start < length)
    {
        int first_char= s[start];
        s[start]= s[length];
        s[length]= first_char;
         
        start++;
        reverse(length, start, s);
    }
}
