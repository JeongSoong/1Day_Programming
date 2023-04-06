#include <stdio.h>

float new_average=0;
float old_average=0;
float basic_data[5]={0,0,0,0,0};


void nomal_move_average (float a,int z)
{
	new_average=(old_average*(z-1)/z)+(a/z);
    old_average=new_average ;
}

 void nomal_move_average_data (float a)
 {
	 for(int i=0; i<4; i++)
	 {
		 basic_data[i]=basic_data[i+1];
	 }
	 basic_data[4]=a;
     new_average=old_average+(basic_data[4]-basic_data[0])/5;
     old_average=new_average ;
  }

int main(void)
{
	float b=0;
	int x=1;
	
	for(int i=0; i<6; i++)
	{
		
		printf("넣을 값을 입력하세요: ");
		scanf("%f",&b);
		nomal_move_average (b,x);
		x = x+1;
		printf("%f \n",new_average);
		basic_data[5-i]=b;
	}
	while(1)
	{
		printf("넣을 값을 입력하세요: ");
		scanf("%f",&b);
		nomal_move_average_data(b);
		printf("%f \n",new_average);
	}
}