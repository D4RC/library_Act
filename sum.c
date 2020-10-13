#include <stdio.h>
#include <stdlib.h>

int sum_rows_and_cols(int **A, int nRows, int nCols)
{
    int *row_sum = (int*)malloc(sizeof(int)*nRows);
    int *col_sum = (int*)malloc(sizeof(int)*nCols);

    for (size_t i = 0; i < nRows; i++)
        *(row_sum+i) = 0;

    for (size_t i = 0; i < nCols; i++)
        *(col_sum+i) = 0;

    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            printf("%d  ",*(*(A+i)+j));
            *(row_sum+i) += *(*(A+i)+j);
            *(col_sum+j) += *(*(A+i)+j);
        } 
        printf("\n");
    }

    printf("\n\nSum by rows\n");
    for (int i = 0; i < nRows; i++)
        printf("%d   ", *(row_sum+i));
    printf("\n\nSum by cols\n");
    for (int i = 0; i < nCols; i++)
        printf("%d   ", *(col_sum+i));

    free(row_sum);
    free(col_sum);

    return 0;
}