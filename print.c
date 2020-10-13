#include <stdio.h>

void print(int **A, int nRows, int nCols)
{
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            *(*(A+i)+j) = i+j;
            printf("%d  ",*(*(A+i)+j));
        }
        printf("\n");
    }
}