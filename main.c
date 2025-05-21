#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_X 100
#define SIZE_Y 80

void calculate_positive(const double *arr, int size, double *sum, int *count) 
{
    *sum = 0.0;
    *count = 0;
    
    for (const double *p = arr; p < arr + size; p += 1) 
    {
        if (*p > 0) 
        {
            *sum += *p;
            (*count)++;
        }
    }
}

int main() 
{
    system("chcp 65001");
    double x[SIZE_X], y[SIZE_Y];
    double s1, s2;
    int k1, k2;
    double z;
    
    srand(time(NULL));
    
    for (int i = 0; i < SIZE_X; i += 1) 
    {
        x[i] = (double)(rand() % 100 - 50);
    }
    
    for (int i = 0; i < SIZE_Y; i += 1) 
    {
        y[i] = (double)(rand() % 100 - 50);
    }
    
    calculate_positive(x, SIZE_X, &s1, &k1);
    
    calculate_positive(y, SIZE_Y, &s2, &k2);

    if (k1 * k2 != 0) 
    {
        z = (exp(s1) + exp(s2)) / (k1 * k2);
        printf("Результат z = %lf\n", z);
    } 
    else 
    {
        printf("Помилка: один з масивів не має додатних елементів (ділення на 0)\n");
    }
    
    printf("Масив x: s1 = %lf, k1 = %d\n", s1, k1);
    printf("Масив y: s2 = %lf, k2 = %d\n", s2, k2);
    
    return 0;
}