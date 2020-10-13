#include <stdio.h>

int multiply(int **A, int **B, int nRowA, int nColA, int nRowB, int nColB)
{
    int aux;
    if (nColA != nRowB)
    {
        printf("\n\n Incompatible dimensions for matrix multiplication\n\n");
        return 1;
    }
        
    printf("\n\nMatrix multiplication : \n");

    for (int i = 0; i < nRowA; i++)
    {
        for (int j = 0; j < nColB; j++)
        {
            aux=0;
            for (int k = 0; k < nColA; k++)
            {
                aux+=*(*(A+i)+k)* *(*(B+k)+j);
            }
            printf("%d\t",aux);
        }
        printf("\n");
    }

    return 0;
}