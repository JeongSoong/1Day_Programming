#include <stdio.h>
#include <stdlib.h>

typedef struct tempNode
{
	int value;
	struct tempNode *next;
} ListNode;


void printList(ListNode *head)
{
	printf("리스트출력: ");
	while(head)
	{
		printf("%d", head->value);
		head = head->next;
	}	
	printf("\n");
}

int insertAtEnd(ListNode **ptrHead, int value)
{
	ListNode *head = *ptrHead;
	ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
	
	if(!tempNode)
	{
		return -1;
	}
	tempNode->value = value;
	tempNode->next = tempNode;
	
	if(head ==NULL)
	{
		tempNode->next = *ptrHead;
		*ptrHead = tempNode;
		return 1;
	}	
	
	while(head->next !=NULL)
	{
		head = head->next;
	}
	
	tempNode->next = head->next;
	head->next = tempNode;
	return 1;
}	

int main(void)
{
	ListNode* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
	insertAtEnd(&head, 5);
	insertAtEnd(&head, 7);
    printList(head);

    return 0;
}	