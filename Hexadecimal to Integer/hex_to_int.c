//This program converts hexademical numbers preceeded by 0x or 0X to their equivalent integer values

#include <stdio.h>
#include <ctype.h>
#define MAX 100

int htoi (char hex_string[MAX]);

int main ()
{
    char hex[MAX];
    hex[MAX]= printf("Hexadecimal: ");
    scanf("%s", hex);
    
    int integer= htoi(hex);

    if (integer != 0)
    {
        printf("Integer: %d\n", integer);
    }
}

int htoi(char s[MAX])
{
    int i;
    int val = 0;
    
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))    //skip 0x or 0X @ start of hex (only meant as hexdec. ID)
    {
        i = 2;
        
        for (i; s[i] != '\0'; i++)
        {
            char s_updated= tolower(s[i]); // case != matters for digit vals

            if (isdigit(s_updated)) // if chars in s_updated array are bw 0 & 9
            {
                val= val * 16 + (s_updated - '0');
            }

            else if (s_updated >= 'a' && s_updated <= 'f')
            {
                val = val * 16 + (s_updated - 'a' + 10);
            }
            
            else
            {
                printf("Invalid char. encountered: Retry & Rerun\n");
                break;
            }
        }
    }

    else
    {
        printf("Invalid input: Rerun w/ correct usage '0x or 0X...'\n");
    }
    return val;
}
