#include<stdio.h>
#include<stdlib.h>

int list[10] = {0,1,2,3,4,5,6,7,8,9};


int insertlist(int list1[],int i,int value)
{
	int templist=0;
	int j;

	for(j=10;j>=i;j--)
	{
	 	templist=list1[j-1];
	 	list1[j]=templist;
	 }
	
	list1[i]=value;
return 1;
}
int insertlist_end(int list1[],int value)
{
	int j;
	
	for(j=10;j>0;j--)
	{
		if(list1[j-1]!=0)
		{
			list1[j-1] = value;
			break;
		}
	}
	return 1;
}

int main()
{
	int value;
	int arr_num;
	int i;
	
	
	printf("배열 (번호 값): ");
	scanf("%d %d",&arr_num,&value);
	insertlist(list,arr_num-1,value);
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("배열    %d = %d\n",i+1,list[i]);
	}
	printf("\n");
	printf("마지막 배열 (값): ");
	scanf("%d",&value);
	insertlist_end(list,value);
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf("배열    %d = %d\n",i,list[i]);
	}

return 0;
}