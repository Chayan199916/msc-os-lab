#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void display(int **mat, int order_of_matrix)
{
    int i, j;
    for (i = 0; i < order_of_matrix; i++)
    {
        for (j = 0; j < order_of_matrix; j++)
        {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}
void deallocate_mem(int **mat, int order_of_matrix)
{
    int i;
#pragma omp parallel for shared(mat) private(i)
    for (i = 0; i < order_of_matrix; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
int **sum_of_matrices(int **matrix_1, int **matrix_2, int order_of_matrix)
{
    int **result = NULL;
    int i;
    result = (int **)calloc(order_of_matrix, sizeof(int *));
#pragma omp parallel for shared(result) private(i)
    for (i = 0; i < order_of_matrix; i++)
    {
        result[i] = (int *)calloc(order_of_matrix, sizeof(int));
    }
    for (size_t i = 0; i < order_of_matrix; i++)
    {
#pragma omp parallel for shared(result, matrix_1, matrix_2)
        for (size_t j = 0; j < order_of_matrix; j++)
        {
            result[i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
    return result;
}
void row_wise_average(int **matrix, int order_of_matrix)
{
    int i;
    int sum_of_row = 0;
    for (size_t i = 0; i < order_of_matrix; i++)
    {
        #pragma omp parallel for reduction(+: sum_of_row)
            for (size_t j = 0; j < order_of_matrix; j++)
            {
                sum_of_row += matrix[i][j];
            }
        printf("Average of row %d is %d\n", i, (sum_of_row / order_of_matrix));  
        sum_of_row = 0;       
    }
}
void total_sum(int **matrix, int order_of_matrix)
{
    int i;
    int sum_of_row = 0;
    int total_sum = 0;
    for (size_t i = 0; i < order_of_matrix; i++)
    {
        #pragma omp parallel for reduction(+: sum_of_row)
            for (size_t j = 0; j < order_of_matrix; j++)
            {
                sum_of_row += matrix[i][j];
            }
        total_sum += sum_of_row;  
        sum_of_row = 0;       
    }
    printf("Total sum : %d", total_sum);
}
int main()
{
    int order_of_matrix_1, order_of_matrix_2;
    int **matrix_1 = NULL;
    int **matrix_2 = NULL;
    int **result = NULL;
    int i, j;
    printf("Enter the order of first matrix : \n");
    scanf("%d", &order_of_matrix_1);
    printf("Enter the order of second matrix : \n");
    scanf("%d", &order_of_matrix_2);
    if (order_of_matrix_1 == order_of_matrix_2)
    {
        omp_set_dynamic(0);
        omp_set_num_threads(order_of_matrix_1);

        matrix_1 = (int **)calloc(order_of_matrix_1, sizeof(int *));
#pragma omp parallel for shared(matrix_1) private(i)
        for (i = 0; i < order_of_matrix_1; i++)
        {
            matrix_1[i] = (int *)calloc(order_of_matrix_1, sizeof(int));
        }
        for (i = 0; i < order_of_matrix_1; i++)
        {
            for (j = 0; j < order_of_matrix_1; j++)
            {
                printf("matrix[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &matrix_1[i][j]);
            }
        }
        matrix_2 = (int **)calloc(order_of_matrix_2, sizeof(int *));
#pragma omp parallel for shared(matrix_2) private(i)
        for (i = 0; i < order_of_matrix_2; i++)
        {
            matrix_2[i] = (int *)calloc(order_of_matrix_2, sizeof(int));
        }
        for (i = 0; i < order_of_matrix_2; i++)
        {
            for (j = 0; j < order_of_matrix_2; j++)
            {
                printf("matrix[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &matrix_2[i][j]);
            }
        }
        result = sum_of_matrices(matrix_1, matrix_2, order_of_matrix_1);
        printf("\nMatrix 1:- \n\n");
        display(matrix_1, order_of_matrix_1);
        printf("\nMatrix 2:- \n\n");
        display(matrix_2, order_of_matrix_1);
        printf("\nMatrix after summation:- \n\n");
        display(result, order_of_matrix_1);
        row_wise_average(result, order_of_matrix_1);
        total_sum(result, order_of_matrix_1);
        deallocate_mem(result, order_of_matrix_1);
        deallocate_mem(matrix_1, order_of_matrix_1);
        deallocate_mem(matrix_2, order_of_matrix_1);
    }
    else
    {
        printf("summation can't be done\n");
    }
    return 0;
}