#include "blueprint.h"
#include <initialize.c>
#include <read.c>
#include <process.c>
#include <sort.c>
#include <add_word.c>
#include <compare.c>
#include <print.c>

int main(int argc, char* argv[])
{
    initialize_word_list();

    FILE* fp;
    fp = stdin; //if no file specified

    if (argc != 2)
    {
        printf("error: correct usage is ./<program_name> <filename>");
        return 1;
    }

    fp = fopen(argv[1], "r");   //override for READ ("r")
            
    if (fp == NULL) 
    {
        printf("open error");
        return 1;
    }

    //process
    readlines(fp, process_line);
    sort_by_freq(word_list, word_count);//freq. from HIGH to LOW
    print_order();

    fclose(fp); //prevent data leak

    //free mem.
    for (int i = 0; i < word_count; i++) 
    {
        free(word_list[i]->word); //free word
        free(word_list[i]);       // Free structure
    }
    free(word_list);
}
