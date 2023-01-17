#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student
{
	int number;
	char name[20];
	int national_score;
	int english_score;
	int math_score;
	struct student *next;
}Listnode;

int insertNode(Listnode **ptrHead, int value)
{
	int tempnumber;
	char tempname[20];
	int tempnation_score;
	int tempenglish_score;
	int tempmath_score;
	
	Listnode *temp = (Listnode*)malloc(sizeof(Listnode));
	if(!temp)
	{
		printf("메모리 할당 오류");
		return -1;
	}
	
	printf("학번을 입력하시오: ");
	scanf("%d", &tempnumber);
	printf("이름을 입력하시오: ");
	scanf("%s", tempname);
	printf("국어점수를 입력하시오: ");
	scanf("%d", &tempnation_score);
	printf("영어점수를 입력하시오: ");
	scanf("%d", &tempenglish_score);
	printf("수학점수를 입력하시오: ");
	scanf("%d", &tempmath_score);
	printf("\n");
	
	//temp-- 사용자로부터 입력
	temp->number = tempnumber;
	temp->name == tempname;
	temp->national_score = tempnation_score;
	temp->english_score = tempenglish_score;
	temp->math_score = tempmath_score;
	
	for(int i =0; i<20; i++)
	{
		temp->name[i] = tempname[i];
	}
	temp->next = *ptrHead;
	*ptrHead = temp;
	return 1;
}	

int printlist(Listnode *head)
{
	printf("============================================\n");
	while(head)
	{
		printf("학번: %d ", head->number);
		printf("이름: %s ", head->name);
		printf("국어: %d ", head->national_score);
		printf("영어: %d ", head->english_score);
		printf("수학: %d ", head->math_score);
		printf("\n");
		head = head->next;
	}
	printf("============================================\n");
}	

int main(void)
{
	Listnode *head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	printlist(head);
	return 0;
}