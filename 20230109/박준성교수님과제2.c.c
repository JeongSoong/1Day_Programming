#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i, j, temp = 0;
	int tot = 0;
	double avg;
    double average[4] = { 0 };
	int scores[4][5];
	
	for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            scores[i][j] = rand() % 100;
 
    printf("학번");
	for(i=1; i<6; i++)
	{
		printf("     %d", i);
	}
	printf("\n");
	printf("국어: ");
	for(i=0; i<5; i++)
	{
		printf("   %d ", scores[0][i]);
	}
	printf("\n");
	printf("영어: ");
	for(i=0; i<5; i++)
	{
		printf("   %d ", scores[1][i]);
	}
	printf("\n");
	printf("수학: ");
	for(i=0; i<5; i++)
	{
		printf("   %d ", scores[2][i]);
	}
	printf("\n\n");
	
	int score_rank[3][2];
	int score_rank_who[3][2];
	
	for (int i = 0;i < 3;i++) 
	{
		for (int j = 0;j < 5;j++) {
			if (score_rank[i][0] <= scores[i+1][j]) 
			{
				score_rank[i][1] = score_rank[i][0];
				score_rank[i][0] = scores[i+1][j];					
				score_rank_who[i][1] = score_rank_who[i][0];
				score_rank_who[i][0] = j+1;
			}
			else if (score_rank[i][1] <= scores[i + 1][j]) 
			{
				score_rank[i][1] = scores[i + 1][j];
				score_rank_who[i][1] = j+1;
			}
		}
	}


	for (int i = 0;i < 3;i++) 
	{
		if (i == 0) printf("수학 등수\n");
		if (i == 1) printf("국어 등수\n");
		if (i == 2) printf("영어 등수\n");
		printf("1등 : %d번, %d점\n",score_rank_who[i][0],score_rank[i][0]);
		printf("2등 : %d번, %d점\n", score_rank_who[i][1], score_rank[i][1]);
		printf("\n\n");
	}

	
	for (int i = 0;i < 3;i++) 
	{
		int mean = 0;
		if (i == 0) printf("수학 평균 = ");
		if (i == 1) printf("국어 평균 = ");
		if (i == 2) printf("영어 평균 = ");
		for (int j = 0;j < 5;j++) mean += scores[i + 1][j];
		mean /= 5;
		printf("[%d]\n", mean);
	}
	
}