#include <stdio.h>
#include <omp.h>
int main()
{
    int Q[100], front = 0, rear = -1, count = 0;
    int id, d, ins = 0;
    omp_set_dynamic(0);
#pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();
        if (id == 0) /*Producer*/
            while (1)
            {
#pragma omp critical
                {
                    if (count < 100)
                    {
                        rear = (rear + 1) % 100;
                        ins++;
                        Q[rear] = ins;
                        printf("\nProducer %d", ins);
                        count++;
                    }
                    else
                        printf("\nProducer no space");
                }
            }
        else
        {
            while (1) /*Consumer*/
            {
#pragma omp critical
                {
                    if (count != 0)
                    {
                        d = Q[front];
                        front = (front + 1) % 100;
                        printf("\nConsumer %d", d);
                        count--;
                    }
                    else
                        printf("\nConsumer no items");
                }
            }
        }
    }
}