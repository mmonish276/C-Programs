#include "blueprint.h"

void print_order(void)
{
    for (int i = 0; i < word_count; i++)
    {
        struct distinct_words* word_info = word_list[i];
        printf("%s: Count ", word_info-> word); //print word itself
        printf("%d", word_info->occurences);    //print occurences tied to word
        printf("\n");
        printf("\n");
    }
}
