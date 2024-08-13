//Program to expand shorthand notations (ie. a-z or 1- 20)

#include <stdio.h>
#include <ctype.h>
#define MAX 100

void expand(char string1[MAX], char string2[MAX]);

int main()
{
    char input[MAX];
    printf("Input string range: ");
    scanf("%s", input); //some range of letters/digits

    char output[MAX];

    expand(input, output);

    printf("Expanded string: ");        //necessary b/c function returns void (alterative: char* to return entire array)
    for (int k = 0; output[k] != '\0'; k++) 
    {
        printf("%c", output[k]);
    }
    printf("\n");
}

void expand(char s1[], char s2[]) //   isupper(), islower(), isdigit() from <ctype.h>
{
   
    int i, j;

    char first_val;
    char last_val;
    
    for (i = 0, j = 0; s1[i] != '\0'; i++, j++) 
    {
        //checks lower, upper, & digits
        if (((islower(s1[i])) && (s1[i+1] == '-') && (s1[i+2] != '\0') && (islower(s1[i+2])) && (s1[i+2] > s1[i])) || 
        ((isupper(s1[i])) && (s1[i+1] == '-') && (s1[i+2] != '\0') && (isupper(s1[i+2])) && (s1[i+2] > s1[i])) || 
        ((isdigit(s1[i])) && (s1[i+1] == '-') && (s1[i+2] != '\0') && (isdigit(s1[i+2])) && (s1[i+2] > s1[i])))

        //already handles edge case of '-' in front (program skips over it until valid char found)

        {
            first_val = s1[i];
            last_val = s1[i+2];
            
            for (char c = first_val; c <= last_val; c++) 
            {
                s2[j++] = c;    //assign to s2[j], then +1
            }
            j--;    /*handles edge case of a-z0-9 
                    why?- ensures last value is placed at z w/ no post-increment 
                    --> loop restarts from (if) statement again for digits */
            i += 2;
        } 
        
        //purpose: handling a-b-c edge case
        else if ((islower(s1[i]) || isupper(s1[i])) && ((s1[i+1] == '-') && (s1[i+3] == '-')))
        {
            first_val = s1[i];
            last_val = s1[i+2];

            if (((islower(first_val)) && (islower(last_val)) && (last_val > first_val)) ||
            ((isupper(first_val)) && (isupper(last_val)) && (last_val > first_val)))
            {
                for (char c = first_val; c <= last_val; c++) 
                {
                    s2[j++] = c;
                }
                j--;    
                i += 2;
            
                while (s1[i]== '-')
                {
                    first_val = s1[i];
                    last_val = s1[i+2];

                    if (((islower(first_val)) && (islower(last_val)) && (last_val > first_val)) ||
                    ((isupper(first_val)) && (isupper(last_val)) && (last_val > first_val)))
                    {
                        for (char c = first_val; c <= last_val; c++) 
                        {
                            s2[++j] = c;
                        }
                        j--;    
                        i += 2;
                    }
                    else
                        break;
                }
            }

        } 
        else 
        {
            s2[j] = s1[i];
        }
    }
    s2[j] = '\0';  //array termination
}
