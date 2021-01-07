#include<stdio.h>
#include<omp.h>

int main(){
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{1, 2}, {3, 4}};
    int c[2][2];
    int numThreads = omp_get_num_procs();
    for (size_t i = 0; i <= numThreads - 1; i++)
    {
        #pragma omp for
            for (size_t k = 0; k <= numThreads - 1; k++)
            {
                c[i][k] = 0;
            }
        for (size_t j = 0; j <= numThreads - 1; j++)
        {
            #pragma omp for
                for (size_t k = 0; k <= numThreads - 1; k++)
                {
                    c[i][k] += a[i][j] * b[j][k];
                }
                
        }        
    }
    for (size_t i = 0; i < numThreads; i++)
    {
        for (size_t j = 0; j < numThreads; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}