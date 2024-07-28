//Program that prints the last n lines of input file using command-line (formatting: ./<program name> -<last n lines to print> <filename>)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //for isdigit() check

#define DEFAULT_LINES 10
#define MAX_LINE_LEN 1000   //MAX_LINE_LEN * MAXLINES= total number of charac. support
#define MAXLINES 1000

char* lineptr[MAXLINES]; // pointers to text's lines

int readlines(FILE *fp, char *lineptr[], int maxlines, char storage[]);
void writelines(char *lineptr[], int nlines, int last_n_lines);
char* alloc(int);
int get_line(FILE* fp, char* s, int lim);

int main(int argc, char* argv[])
{

    int nlines;  //number of lines read
    int lines_to_print = DEFAULT_LINES;
    char line_storage[MAXLINES * MAX_LINE_LEN];
    FILE* fp;
    fp = stdin; //if no file specified

    for (int i = 1; i < argc; i++)  
    {
        if (argv[i][0] == '-' && isdigit(argv[i][1]))
            lines_to_print = atoi(argv[i] + 1);

        else 
        {
            fp = fopen(argv[i], "r");
            
            if (fp == NULL) 
            {
                perror("fopen");
                return 1;
            }
        }
    }

    if ((nlines = readlines(fp, lineptr, MAXLINES, line_storage)) >= 0)     //take in file input
    {
        writelines(lineptr, nlines, lines_to_print);   //changes argument type based on # tot. lines

        if (fp != stdin) //close file if not standard input file
        {
            fclose(fp);
        }
        return 0;
    } 
    
    else 
    {
        printf("error: input too small\n");
        return 1;
    }
}

//put line into arrays
int get_line (FILE* fp, char* s, int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = fgetc(fp)) != EOF && c != '\n'; ++i)    //read each line from file (splitup @ newlines)
        s[i] = c;

    if (c == '\n') 
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

//dynami mem. for line storage
char *alloc(int n)
{
    return (char*) malloc(n * sizeof(char));
}

//process input lines into dynamic mem.
int readlines(FILE *fp, char *lineptr[], int maxlines, char storage[])
{
    int len, nlines;
    char line[MAX_LINE_LEN];
    char* p = storage;

    nlines = 0;
    while ((len = get_line(fp, line, MAX_LINE_LEN)) > 0) 
    {
        if (nlines >= maxlines || (p + len + 1 > storage + MAXLINES * MAX_LINE_LEN))
            return -1;
        
        char *line_storage = alloc(len + 1); // +1 for null terminator (dynamic alloc.)
       
        if (line_storage == NULL)  //storage full
        {
            perror("alloc");
            return -1;
        }

        strcpy(line_storage, line);
        lineptr[nlines++] = line_storage;
    }
    return nlines;
}

//write output lines
void writelines(char *lineptr[], int nlines, int last_n_lines)
{
    //nlines is total lines read

    int index_start= nlines - last_n_lines;

    if(index_start < 0)
        printf("error: invalid input parameters");

    
    else
    {   
        for (int i= index_start; i < nlines; i++)
            printf("%s\n", lineptr[i]);
    }
}
