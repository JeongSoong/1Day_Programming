#include <stdio.h>

float sum = 0.0;
int count = 0;

void average_filter(float input) 
{
    sum += input;
    count++;
    float output = sum / count;
    printf("평균값: %f\n", output);
}

int main() 
{
    float input;
    while (1) 
    {
        printf("넣을 값을 입력하세요: ");
        scanf("%f", &input);
        average_filter(input);
    }
    return 0;
}