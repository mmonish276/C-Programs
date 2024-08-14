#ifndef BLUEPRINT_H
#define BLUEPRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LINE_LEN 1000

struct distinct_words
{
    char* word;
    int occurences; //freq. of each word
};

struct distinct_words** word_list;  //dynamic array 
int word_count= 0;   //overall # of words
int word_list_size= MAX_WORDS;

//function declarations
void sort_by_freq(struct distinct_words* word_list[], int word_count);
int compare_freq(const void* element1, const void* element2);
void print_order(void);

//below functions DO NOT have *occurences as arg --> they DO NOT increment by line
void readlines(FILE* fp, void (*process_line)(const char* line));
void process_line(const char* line);
void add_word(char* token);

#endif
