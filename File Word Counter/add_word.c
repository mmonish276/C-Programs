#include "blueprint.h"

void add_word(char* token)  //token = word
{
    for (int i = 0; i < word_count; i++)
    {
        if (strcmp(word_list[i]-> word, token) == 0) 
        {
            word_list[i]-> occurences++; // if word exists
            return;
        }
    }
    
    if (word_count >= word_list_size)   //ensure enough buffer room for new input
    {
        word_list_size *= 2;
        struct distinct_words** new_word_list = realloc(word_list, word_list_size * sizeof(struct distinct_words*));

        if(new_word_list == NULL)
        {
            printf("error: no room for further word alloc.\n");
        }
        word_list= new_word_list;   //editing copy of word array
    }
        
        struct distinct_words* new_entry = malloc(sizeof(struct distinct_words));
                
        if (new_entry == NULL)
            printf("error: unable to make room for new word");

        new_entry-> word= strdup(token); //duplicate token

        if (new_entry->word == NULL)    //AKA: uninitialized val. inside tree
        {
            printf("Error: Unable to allocate memory for word.\n");
            free(new_entry);  // Free struct. if alloc. fails
        }
        new_entry->occurences = 1;  //for first occurence
        word_list[word_count] = new_entry;  //overwrite (will remain 1 if count=1)
        word_count++;   
}
