//Binary search program that will tell you position of specified value in user-chosen array
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int* num_array_gen (int starting_val, int ending_val, int size);
int binsearch(int random_number, int low, int high, int num_array[], int size);

int main()
{
    int number= printf("Pick an integer: ");
    scanf("%d", &number);

    int start_val= printf("Pick starting value: ");
    scanf("%d", &start_val);

    int end_val= printf("Pick ending value: ");
    scanf("%d", &end_val);

    int array_size= printf("Array size: ");
    scanf("%d", &array_size);

    (array_size >= 0 && array_size < MAX_SIZE && array_size % 2 == 0)
        ? printf("Array size is valid.\n")
        : printf("Error: Only positive, non-zero, even array sizes less than 100 are allowed.\n");

    int* symmetricArray = num_array_gen(start_val, end_val, array_size);
    int position= binsearch(number, start_val, end_val, symmetricArray, array_size);

    
    if (position == -2 || position == -3)
        printf("Error code: %i\nNOTE: -3 means size is too small (try one larger) & -2 means your number is out of array's range\n", position);
    
    else
    {
        printf("Position of your integer: %ith position\n", position);
    }
}

int* num_array_gen(int starting_val, int ending_val, int size) 
{
    int* symmetricArray = (int*) malloc(size * sizeof(int)); // Allocate memory dynamically for the array

    for (int i = 0; i < size / 2; i++) {
        symmetricArray[i] = starting_val + i;              
        symmetricArray[size - 1 - i] = ending_val - i;
    }
    return symmetricArray;
}

int binsearch(int x, int low, int high, int v[], int n)
{
    low= low;
    int mid;
    high = n - 1;
    
    if (x < v[low] || x > v[high]) 
    {
        return -2;  // x is outside range
    }

    if (n == high)
        return -3;

    while (low <= high) 
    {
        mid = (low + high) / 2;
        
        if (x > v[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }
    if (x == v[mid])
        return mid;

    else
        return -1;
}
