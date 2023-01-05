#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, M, i, cnt, chk, imsi;
	
	printf("막대기 수 입력:");
	scanf("%d", &N);
	if(N>=2 && N<=100000)
	{
		int *M = (int *)malloc(sizeof(int)*N);
		
		for(i=0; i<N; i++)
		{
			scanf("%d", &imsi);
			if(imsi>=1 && imsi<=100000)
			{
				M[i] = imsi;
			}
		else
		{
			return 0;
		}
	}	
	
	cnt = 1;
	chk = M[N-1];
	for(i=N-2; i>=0; i--)
	{
		if(M[i]>chk)
		{
			cnt++;
			chk = M[i];
		}
	}
	
	printf("\n%d", cnt);
	
	free(M);
	}
	return 0;
}	