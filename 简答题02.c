#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int a,b,c,number;
	number=369;
	a=number/100;
	b=(number-a*100)/10;
	c=number-a*100-b*10;
	printf("�������ǣ�%d%d%d \n",c,b,a);
	return 0;
 } 
