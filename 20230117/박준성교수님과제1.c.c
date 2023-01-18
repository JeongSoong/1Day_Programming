#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student
{
	int value;
	int number;
	char name[20];
	int national_score;
	int english_score;
	int math_score;
	struct student *next;
}ListNode;

int insertNode(ListNode **ptrHead, int value)
{
	int tempnumber;
	char tempname[20];
	int tempnation_score;
	int tempenglish_score;
	int tempmath_score;
	
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
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

int printlist(ListNode *head)
{
	char rank = 1;
	
	printf("============================================\n");
	printf(" 등수 학번 이름   국어 영어 수학 총점 평균\n ");
	while(head)
	{
		int sum;
        double avg;
	    sum = head->national_score + head->english_score + head->math_score;
	    avg = sum/3;
		printf(" %d등   %d   %s      %d    %d    %d    %d    %lf\n ", rank, head->number, head->name, head->national_score, head->english_score, head->math_score, sum, avg);
		head = head->next;
		rank++;
	}
	printf("============================================\n");
}

void deleteNode(ListNode **ptrHead, int delValue)
{
	printf("\n노드삭제\n");
	ListNode *currNode = *ptrHead;
	ListNode *nextNode;
	
	if(currNode && currNode->value == delValue)
	{
		*ptrHead = currNode->next;
		free(currNode);
		return;
	}
	while(currNode != NULL)
	{
		nextNode = currNode->next;
		if(nextNode && nextNode->value == delValue)
		{
			currNode->next = nextNode->next;
			free(nextNode);
			return;
		}
		else
		{
			currNode = nextNode;
		}
	}
}

int main(void)
{
	int n=0;
	ListNode *head = NULL;
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);
	printlist(head);
	return 0;
}