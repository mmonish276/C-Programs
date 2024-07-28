//main function that runs Polish Calculator
#include "calc.h"
#include "functions.c"
#include "input.c"
#include "operation.c"

int main()
{
    int type;   //return val. of getop() --> function, num, op, etc.
    double op2; //second argument (supplementary to first)
    char s[MAXOP];

    for (int j = 0; j < MAX_VARIABLES; j++) 
    {
        variables[j]= 0.0;
    }

    while ((type = getop(s)) != EOF) 
    {
        switch (type) 
        {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '*':
                push(pop() * pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            
            case '%':
                op2= pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else 
                    printf("error: zero divisor\n");
                break;

            case 'd':
                duplicate();
                break;

            case 's':
                swap();
                break;

            case 'c':
                clear();
                break;

            case 'p':
                printf("top element: %.8g\n", peek());
                break;
            
            case FUNCTION:
            {
                char function[MAXOP];
                strcpy(function, s);
                
                // Check for arguments
                if ((type = getop(s)) == NUMBER) {
                    double argument1 = atof(s);

                    //check power function declaration
                    if (strcmp(function, "pow") == 0) 
                    {
                        // Read the second argument for 'pow' (exponent)
                        if ((type = getop(s)) == NUMBER) 
                        {
                            double argument2 = atof(s);
                            push(pow(argument1, argument2)); //argument1= common for all functions (base for power)
                        } else {
                            printf("error: pow function requires two inputs: base & exponent\n");
                        }
                    } 
                    
                    else if (strcmp(function, "sin") == 0) 
                        push(sin(argument1));
                    
                    else if (strcmp(function, "exp") == 0)
                        push(exp(argument1));
                    
                    else 
                    {
                        printf("error: unknown function %s\n", function);
                    }
                } 
               
                else 
                    printf("error: function call requires value\n");

                break;
            }

            case 'l':   //codename: pos. of val. in stack
                type= getop(s); //variable 'letter'
                if (type >= 'a' && type <= 'z')
                {
                    variables[type - 'a'] = pop(); //places val. into corresponding index val.
                    printf("%c set to %.8g\n", type, variables[type - 'a']);    //showing val.
                }

                else
                    printf("error: variable cannot be assigned\n");

                break;

            case 'r':   //codename: print stack val
                type = getop(s);
                if (type >= 'a' && type <= 'z')
                {
                    printf("%c is %.8g\n", type, variables[type - 'a']);    //printing var_val
                    recent_val = variables[type - 'a']; //update stack val.
                }

                else
                    printf("error: invalid variable retrieval\n");

                    break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;
    
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
