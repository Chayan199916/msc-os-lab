/*OpenMP program to find the dot product, cross
product of two vectors.*/

#include <stdio.h>
#include<stdlib.h>
#include <omp.h>

void display_vector(int *result, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", result[i]);
    printf("\n");
}
int dot_product(int *first, int *second, int size)
{
    int result = 0, i;
    #pragma omp parallel for reduction(+: result)
    for (i = 0; i < size; i++)
        result += first[i] * second[i];
    return result;
}
void cross_product(int *first, int *second, int size)
{
    int *result = (int *)malloc(size * sizeof(int));
    int i, j, m;

    omp_set_dynamic(0);
    m = omp_get_num_procs();
    omp_set_num_threads(m);

    #pragma omp parallel for shared(result, first, second)
    for(i = 0; i < size; i++)
        result[i] = first[(i + 1) % size] * second[(i + 2) % size] - first[(i + 2) % size] * second[(i + 1) % size];
    display_vector(result, size);
    free(result);
}
int main()
{
    int size = 3;
    int first[3] = {3, -5, 4};
    int second[3] = {2, 6, 5};
    printf("\n Result after dot product : %d", dot_product(first, second, size));
    printf("\n Result after vector product : ");
    cross_product(first, second, size);
    return 0;
}