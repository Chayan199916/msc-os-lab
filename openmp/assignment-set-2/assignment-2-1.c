/*
OpenMP program to multiply two matrices.
*/

#include <stdio.h>
#include <omp.h>
int main()
{
    int A[3][3] = {1, 1, 1,
                   1, 1, 1,
                   1, 1, 1};
    int B[3][3] = {2, 2, 2,
                   2, 2, 2,
                   2, 2, 2};
    int C[3][3], i, j, k;
    #pragma omp parallel for shared(C)
        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                C[i][j] = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            #pragma omp parallel for shared(C, B, A)
                for (k = 0; k < 3; k++)
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
            printf(" %d", C[i][j]);
    }
    fgetc(stdin);
}
