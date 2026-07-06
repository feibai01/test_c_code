#include<stdio.h>
int main()
{
	int a,b,c,number;
	number=123;
	a=number/100;
	b=(number-a*100)/10;
	c=number-a*100-b*10;
	printf("Reverse number:%d%d%d \n",c,b,a);
	return 0;
 } 
