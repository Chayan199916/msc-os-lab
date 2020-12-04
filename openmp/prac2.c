#include<stdio.h>
#include<omp.h>

int main(int argc, char const *argv[])
{
    
    omp_set_dynamic(1); // 0 requests os to set threads as per user requirements; 1 doesn't send request
    omp_set_num_threads(6);
    #pragma omp
    printf("hello from thread %d of a total of %d threads\n", omp_get_thread_num(), omp_get_num_threads());
    return 0;
}
