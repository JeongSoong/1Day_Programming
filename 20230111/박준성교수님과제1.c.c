#include <stdio.h>

int main(void)
{
	int i=10;
	double f=12.3;
	int *pi = NULL;
	
	double *pf = NULL;
	pi = &i;
	pf = &f;
	
	printf("%u %u %d\n", pi, &i, i);
	printf("%u %u %f\n", pf, &f, f);
	
	return 0;
}