#include <stdio.h>
#include <stdlib.h>
#include "library1.h"

#define A_ROWS 4
#define A_COLS 2
#define B_ROWS 2
#define B_COLS 4

void main()
{
    int **A = (int**)malloc(sizeof(int)*A_ROWS);
    int **B = (int**)malloc(sizeof(int)*B_ROWS);


    printf("A Matrix:\n");
    // A initialization
    for (size_t i = 0; i < A_ROWS; i++)
    {
        *(A+i) = malloc(sizeof(int)*A_COLS);
     
        for (size_t j = 0; j < A_COLS; j++)
        {
            *(*(A+i)+j) = i+j;
        } 
        printf("\n");
    }

    print_matrix(A, A_ROWS, A_COLS);
    sum_rows_and_cols(A,A_ROWS,A_COLS);

    printf("\n\nB Matrix:\n");
    // B initialization
    for (size_t i = 0; i < B_ROWS; i++)
    {
        *(B+i) = malloc(sizeof(int)*B_COLS);
        for (size_t j = 0; j < B_COLS; j++)
        {
            *(*(B+i)+j) = i+j;
        }
    }

    print_matrix(B, B_ROWS, B_COLS);
    multiply(A, B, A_ROWS, A_COLS, B_ROWS, B_COLS);

    for (size_t i = 0; i < A_ROWS; i++)
    {
        free(A+i);
    }

    for (size_t i = 0; i < B_ROWS; i++)
    {
        free(B+i);
    }

    free(A);
    free(B);    
}


