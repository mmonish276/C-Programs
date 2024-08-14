#include "blueprint.h"

void readlines(FILE* fp, void (*process_line)(const char* line))
{
    char line[MAX_LINE_LEN];  //storage of line

    while (fgets(line, sizeof(line), fp)) 
        process_line(line); 
}
