#include "blueprint.h"

void sort_by_freq(struct distinct_words* word_list[], int word_count)
{
    qsort(word_list, word_count, sizeof(struct distinct_words*), compare_freq);//stdlib.h
}
