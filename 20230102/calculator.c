#include <stdio.h>

int sum(int a, int b)
{
	return a + b;
}

int diff(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

int main(void)
{
	int x, y;
	char z;
	
	printf("수식을 입력하십시오: ");
	scanf("%d %c %d", &x, &z, &y);
	
	int (*fp)(int,int);
	
	if(z=='+'){
		fp=sum;	
	}
	if(z=='-'){
		fp=diff;
	}
	if(z=='*'){
		fp=mul;
	}
	if(z=='/'){
		fp=div;
	}
	printf("%d %c %d = %d\n", x, z, y, fp(x,y));  //결과값
	return 0;
}	