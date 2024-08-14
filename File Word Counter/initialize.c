#include "blueprint.h"

void initialize_word_list(void)  //size alloc.
{
    word_list = malloc(word_list_size * sizeof(struct distinct_words*));    //word_list alloc.
    
    if (word_list == NULL)
        printf("error: couldnt allocate memory\n");

    for (int i = 0; i < word_list_size; i++) 
    {
        word_list[i] = malloc(sizeof(struct distinct_words));

        if (word_list[i] == NULL)
            printf("error: couldnt allocate memory\n");
        
        word_list[i]->word = NULL; //AKA: keep empty
        word_list[i]->occurences = 0; // initialize
    }
}
