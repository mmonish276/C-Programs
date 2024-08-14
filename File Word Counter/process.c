#include "blueprint.h"

void process_line(const char* line)
{
    char* line_copy = strdup(line); //to prevent editing of line itself
    
    if (line_copy == NULL)
        printf("error: line couldn't be processed");

    char *token = strtok(line_copy, " \t\n\r.,;:!?"); //split into words

    while (token != NULL)
    {
        add_word(token);
        token = strtok(NULL, " \t\n\r.,;:!?");  //get next token
    }

    free(line_copy);
}
