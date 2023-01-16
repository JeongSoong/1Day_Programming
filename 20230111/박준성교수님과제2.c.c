#include <stdio.h>

int main(void)
{
	int x=10, y=20;
	int *p;
		
	p=&x;
	printf("p = %d\n", p);
	printf("p = %d\n", *p);
	
	*p=*p+10;
	printf("p = %d\n", *p);
	printf("p = %d\n", x);
	
	p=&y;
	printf("p = %d\n", p);
	printf("p = %d\n", *p);
	
	*p=*p+10;
	printf("p = %d\n", *p);
	printf("p = %d\n", y);
	
	return 0;
}