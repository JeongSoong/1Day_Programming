#include <stdio.h>

double old_avg = 0.0;
double new_avg = 0.0;

void frq_avg(double a, double b) 
{
    new_avg = (old_avg * b) + (a * (1 - b));
    old_avg = new_avg;
}

int main(void)
{
    float i = 0;
    float n = 0.8;

    while (1)
    {
        printf("넣을 값을 입력하세요: ");
        scanf("%f", &i);
        frq_avg(i, n);
        printf("%f \n", new_avg);
    }
}