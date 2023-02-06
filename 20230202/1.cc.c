#include <stdio.h>

double old_avg = 0.0;
double new_avg = 0.0;

void avg(double a, double b) 
{
	new_avg = (old_avg * b) + (a * (1 - b));
	old_avg = new_avg;
}

int main(void)
{
	float b = 0;
	float n = 0.8;

	while (1)
	{
		scanf("%f", &b);
		avg(b, n);
		printf("%f \n", new_avg);
	}
}