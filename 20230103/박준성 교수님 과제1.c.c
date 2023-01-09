#include <stdio.h>
#include <stdlib.h>

#define ERROR_VALUE 404

typedef struct tempNode
{
	int value;
	struct tempNode *next;
} ListNode;	

int insertNode(ListNode **ptrHead, int value)
{
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
	if(!temp)
	{
		printf("메모리 할당 오류");
		return -1;
	}
	temp->value = value;
	temp->next = *ptrHead;
	*ptrHead = temp;
	return 1;
}	

int printlist(ListNode **ptrHead)
{
	ListNode *deleteMe;
	int value;
	if(*ptrHead)
	{
		deleteMe = *ptrHead;
		*ptrHead = deleteMe->next;
		value = deleteMe->value;
		free(deleteMe);
		return value;
	}
	else
	{
		printf("스택이 비었습니다. \n");
		return ERROR_VALUE;
	}
}	

int SumArray(int list[], int size)
{
	ListNode *head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	insertNode(&head, 5);
	insertNode(&head, 7);
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", printlist(&head));
	}	
	printf("\n");
	
	return 0;
}	

int main(void)
{
	int list[10] = {1, 2, 3, 5, 7};
	
	printf("배열 = %d\n", SumArray(list, 5));
	
	return 0;
}	