#include <stdio.h>

float old_average=0;
float new_average=0;
float data[5]={0,0,0,0,0};


 void nomal_average (float a,int X){
    new_average=(old_average*(X-1)/X)+(a/X);
    old_average=new_average ;
  }

 void nomal_average_data (float a){
	 for(int i=0; i<4; i++){
		 data[i]=data[i+1];
	 }
	 data[4]=a;
     new_average=old_average+(data[4]-data[0])/5;
     old_average=new_average ;
  }

int main(void){
	float b=0;
	int X=1;
	
	for(int i=0; i<6; i++){
		
		printf("값을 넣으세요 : ");
		scanf("%f",&b);
		nomal_average (b,X);
		X = X+1;
		printf("%f \n",new_average);
		data[5-i]=b;
	}
	while(1){
		printf("값을 넣으세요 : ");
		scanf("%f",&b);
		nomal_average_data(b);
		printf("%f \n",new_average);
	}
}