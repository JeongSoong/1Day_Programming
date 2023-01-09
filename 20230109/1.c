#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int main(void)
{
	int i, j, temp = 0;
	int num;
	int scores[SIZE];
	
	for(i=0; i<SIZE; i++)
		scores[i] = rand() % 100;
	
	for(i=0; i<SIZE; i++)
		printf("[%d]=%d\n", i, scores[i]);
	
	printf("내림차순\n");
	
	for (i=0; i<SIZE; i++)
	{
        for (j=i; j<SIZE; j++)
		{
            if (scores[i]<scores[j])
			{
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
        printf("[%d]=%d\n", i, scores[i]);
    }
	
	printf("오름차순\n");
	
	for (j=0; j<SIZE; j++)
	{
        for (i=j; i<SIZE; i++)
		{
            if (scores[i]<scores[j])
			{
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
        printf("[%d]=%d\n", j, scores[j]);
    }
	
	printf("배열에 넣을 수를 입력하십시오: ");
	scanf("%d", &num);
	
	printf("내림차순\n");
	
	for (i=0; i<SIZE; i++)
	{
        for (j=i; j<SIZE; j++)
		{
            if (scores[i]<scores[j])
			{
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
        printf("[%d]=%d\n", i, scores[i+1]);
    }
	
	printf("오름차순\n");
	
	for (j=0; j<SIZE; j++)
	{
        for (i=j; i<SIZE; i++)
		{
            if (scores[i]<scores[j])
			{
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
        printf("[%d]=%d\n", j, scores[j]);
    }
	
	return 0;
}	