#include<stdio.h>
int main() 
{
	int n;
	scanf("%d",&n);
	if(n<=0){
		printf("Data error!\n");
	}
	else if(n%5==0 && n%7==0){
		printf("Yes!\n");
	}
	else{
		printf("No!\n");
	}
	return 0;
	}

