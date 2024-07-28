//Low-level pointer-utilizing program to compare whether 2 strings are the same or not

#include <stdio.h>
#define MAX 100

int string_compare(char *, char *);

int main()
{
    char string1[MAX];  //declare as char[] due to malloc() requirement for char*
    char string2[MAX];
        
    printf("String 1: ");
    fgets(string1,MAX,stdin);

    printf("String 2: ");
    fgets(string2,MAX,stdin);

    int comp_index= string_compare(string1, string2);

    (comp_index < 0 || comp_index > 0) ? printf("Comparison Index: %i. String 1 & 2 are different\n", comp_index) : printf("String 1 & 2 are same\n"); 
}

int string_compare(char *s, char *t)
{
    char* start= s;
    char* comp_start = t;
    int c;

    while(*s != '\0')
        s++;
    char* end= s;

    printf("end: %s",end);

    while(*t != '\0')
        t++;
    char* comp_end = t; 

    if ((end - start) != (comp_end- comp_start))   //different sizes handling
    {
        for (s= start, t= comp_start; *s != '\0' && *t != '\0'; )
        {
                if (*s != *t)
                    return (*s > *t) ? 1 : -1;

                else
                {   
                    s++;
                    t++;
                }
        }
        if (*s == '\0' && *t != '\0')      //check positioning @ end (ie. (s) is prefix of (t) or vice versa)
            return -1;

        else if (*s != '\0' && *t == '\0')
            return 1;
                    
        else
            return 0;
    }

    else   //same size handling
    {
        for (s= start, t= comp_start; *t != '\0' && *s != '\0'; s++, t++)
        {
            if(*s == *t)
                ;

            else if (*s > *t)
                return 1; 

            else
                return -1;
        }

        if (*s == '\0' && *t == '\0')
            return 0;
    }
}
