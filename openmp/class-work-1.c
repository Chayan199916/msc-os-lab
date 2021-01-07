#include<stdio.h>
#include<omp.h>

int x = 5;

void first(){
    #pragma omp critical
    {
        x++;
        printf("%d in first\n", x);
    }
}

void second(){
    #pragma omp critical
    {
        x--;
        printf("%d in second\n", x);
    }
}

int main(){
    //stmts
    #pragma omp parallel sections
    {
        #pragma omp section
            first();
        #pragma omp section
            second();
    }
    printf("%d at end\n", x);
}




/*
here both first and second trying to access common resource x and trying to write on it
this is w-w issue. parallel execution can't be applied over here. we have to put x into 
critical section.#pragma omp atomic allows it's content to run atomically. 
for ex a = b + c consists of 3 instructions(two reading, one writing) so all these 
instructions should be part of one logical unit. if a thread is performing these instructions
it should n't get preempted by any other thread. in that case dirty value might be read
when prev thread returns after context switching.
*/