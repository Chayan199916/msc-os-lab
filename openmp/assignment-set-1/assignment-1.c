/*
openmp program to define 3 int arrays A, B, C of same size and calculate 
A[i] = B[i] + C[i] parallely for all i
*/
#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
    int A[5], B[5] = {1, 2, 3, 4, 5}, C[5] = {1, 2, 3, 4, 5};
    int m, i;
    
    omp_set_dynamic(0);
    m = omp_get_num_procs();
    omp_set_num_threads(m);

    #pragma omp parallel for shared (A, B, C) private (i)
    for (i = 0; i < 5; i++)
    {
        A[i] = B[i] + C[i];
        printf("\nA[%d] = %d from thread %d of threads %d", i, A[i], omp_get_thread_num(), omp_get_num_threads());
    }    
    return 0;
}
