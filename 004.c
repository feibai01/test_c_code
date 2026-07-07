#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x%4==0 && x%100!=0)
		printf("闰年");
	else if(x%400==0)
		printf("闰年");
	else
		printf("平年");
	return 0;
 } 
