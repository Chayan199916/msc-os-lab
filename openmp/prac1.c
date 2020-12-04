#include<stdio.h>
#include<omp.h>

int main(){

    int m, k;
    
    m = omp_get_num_procs();
    k = omp_get_max_threads();

    printf("No of processors available : %d and max no of threads : %d", m, k);

}