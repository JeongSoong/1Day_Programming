#include <stdio.h>

#define FILTER_SIZE 5

float filtered_data[FILTER_SIZE] = {0};

float sum = 0;

void moving_average_filter(float new_data)
{
    for (int i = FILTER_SIZE - 1; i > 0; i--)
	{
        filtered_data[i] = filtered_data[i - 1];
    }
    filtered_data[0] = new_data;

    sum = 0;
    for (int i = 0; i < FILTER_SIZE; i++) 
	{
        sum += filtered_data[i];
    }
    float average = sum / FILTER_SIZE;

    printf("이동평균값: %f\n", average);
}

int main(void) 
{
    float input = 0;
    while (1)
	{
        printf("넣을 값을 입력하세요: ");
        scanf("%f", &input);
        moving_average_filter(input);
    }
    return 0;
}