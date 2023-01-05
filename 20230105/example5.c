#include <stdio.h>
//#include <stdlib.h>

int main(void)
{
	int N, Ans = 1;
	
	printf("숫자를 입력하십시오: ");
	scanf("%d", &N);
	
	if(N>1 && N<=100)
	{
		while(1<N)
		{
			N>>=1;
			Ans<<=1;
		}	
		printf("%d\n",Ans);
	}
	return 0;
}

