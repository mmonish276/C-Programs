//major function declarations & libraries

#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h> //atof() lib.
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNCTION '2' //flag val. for function 
#define OPERATOR '1' //flag val. for operator
#define MAXVAL 100  //mutable
#define BUFSIZE 100 //mutable
#define MAX_VARIABLES 26 //a to z

//all declarations
int getop(char []);
double peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char []);
int get_line(char [], int);

//global vars.
char buf[BUFSIZE]; // buffer for ungetch 
int bufp = 0; // next free position in buffer
int sp = 0; // next free stack position
double val[MAXVAL]; // stack for vals
double variables[MAX_VARIABLES]; //stores variables' vals when user assigns
double recent_val; //print thru call

#endif
