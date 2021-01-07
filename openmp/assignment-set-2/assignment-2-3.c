/*
OpenMP program to find the determinant of a
3x3 matrix.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

/*void allocate_mem(int **temp){
    temp = (int **)malloc(2 * sizeof(int *));
    for (size_t i = 0; i < 2; i++)
    {
        temp[i] = (int *)malloc(2 * sizeof(int));
    }
}
void deallocate_mem(int **temp){
    for (size_t i = 0; i < 2; i++)
    {
        free(temp[i]);
    }
    free(temp);
}*/
void display_matrix(int input_matrix[3][3], int order)
{
    for (size_t i = 0; i < order; i++)
    {
        for (size_t j = 0; j < order; j++)
        {
            printf("%d\t", input_matrix[i][j]);
        }
        printf("\n");
    }
}
int **get_cofactor(int input_matrix[3][3], int selected)
{
    int row = 0, col = 0;
    int temp[2][2];
    for (size_t i = 1; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (j != selected)
            {
                temp[row][col++] = input_matrix[i][j];
            }
        }
        row++;
        col = 0;
    }
    //display_matrix(temp, 2);
    return temp;
}
int get_minor(int input_matrix[3][3], int selected)
{
    int **temp, result = 0;
    temp = (int **)malloc(2 * sizeof(int *));
    for (size_t i = 0; i < 2; i++)
    {
        temp[i] = (int *)malloc(2 * sizeof(int));
    }
    temp = get_cofactor(input_matrix, selected);
    result = temp[0][0] * temp[1][1] - temp[1][0] * temp[0][1];
    for (size_t i = 0; i < 2; i++)
    {
        free(temp[i]);
    }
    free(temp);
    return result;
}

int get_determinant(int input_matrix[3][3])
{
    int i, result = 0;
    #pragma omp parallel for shared(input_matrix) reduction(+ \
                                                        : result)
    for (i = 0; i < 3; i++)
        result += (int)pow(-1, i) * input_matrix[0][i] * get_minor(input_matrix, i);
    return result;
}

int main(int argc, char *argv[])
{
    int input_matrix[3][3];
    int counter = 1;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            input_matrix[i][j] = atoi(argv[counter++]);
        }
    }
    display_matrix(input_matrix, 3);
    printf("Determinant of the matrix : %d", get_determinant(input_matrix));
    return 0;
}
