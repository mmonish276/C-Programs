#include "blueprint.h"

int compare_freq(const void* element1, const void* element2)
{
    const struct distinct_words *word2 = *(const struct distinct_words**) element2;
    const struct distinct_words *word1 = *(const struct distinct_words **) element1; 

    //vals. to move position
    if (word2->occurences < word1->occurences) 
        return -1;
    
    else if (word2->occurences > word1->occurences) 
        return 1;
    
    else
        return 0;
}
