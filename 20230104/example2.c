#include <stdio.h>

int main(void)
{
	int N,M;
	int imsi;
	int i;
	
	while(1)
	{
		printf("임의의 정수 두 개를 입력하시오(예:1 10): ");
		scanf("%d %d", &N, &M);
		if((N>=0 && N<100000)&&(M>=0 && M<100000)) break;
		printf("입력된 수가 0<=N, M<100000의 조건을 벗어났습니다.\n");
		printf("다시 입력하시오..\n");
	}	
	
	if(N>M)
	{
		imsi=N;
		N=M;
		M=imsi;
	}
	
	printf("%d~%d까지의 숫자 출력결과\n", N, M);
	for(i=N; i<=M; i++)
		printf("%d ", i);
	printf("\n");
	
	return 0;
}	