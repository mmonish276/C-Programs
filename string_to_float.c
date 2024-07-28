//Program for converting strings of numbers into floats w/ compatibility w/ scientific notation

#include <stdio.h>
#include <ctype.h>

#define MAX 100

double atof(char random_numstring[]);

int main()
{
    char number[MAX];
    printf("Number: ");
    scanf("%s", number);

    float converted= atof(number);

    printf("Converted to float: %lf\n", converted);
}

double atof(char s[])
{
    double val, decimal;
    float scientific = 1.0;

    int i, j, sign, sci_sign, exponent;
    
    for (i = 0; isspace(s[i]); i++) //ignore whitespace
        ;   //AKA: skip
    sign = (s[i] == '-') ? -1 : 1;
    
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++) //pre-decimal portion
        val = 10.0 * val + (s[i] - '0');
        
    if (s[i] == '.')
        i++;

    for (decimal = 1.0; isdigit(s[i]); i++)   //post-decimal portion
    {
        val = 10.0 * val + (s[i] - '0');
        decimal *= 10;
    }

    for (j= 0; (s[j] != '\0'); j++)    //sci-notation support of form (132.34e-4)
    {
        if (s[j] == 'E' || s[j] == 'e')
        {
            if (s[j+ 1] == '-') 
            sci_sign = -1;

            else
                sci_sign= 1;

            break;  //end loop when 'E'/'e' is found --> store that j val. for below
        }
    }
        int m;
        
        if (sci_sign == -1)
        {
            for (exponent = 0.0, m = j + 2; isdigit(s[m]) && (s[m] != '\0'); m++)   //check exponent for digits & find val.
                exponent = 10.0 * exponent + (s[m] - '0');  

            exponent *= sci_sign;   //add sign in for scientific exp. calc

            for (int k = 0; k > exponent; k--) 
                scientific /= 10;
        }
        
        else if (sci_sign== 1)
        {
            for (exponent = 0.0, m = j + 1; isdigit(s[m]) && (s[m] != '\0'); m++)
                exponent = 10.0 * exponent + (s[m] - '0'); 

            exponent *= sci_sign;

            for (int k = 0; k < exponent; k++) 
                scientific *= 10;
        }

    return (sign * val / decimal)* (scientific);
}
