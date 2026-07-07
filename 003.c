#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>b)
		printf("较大的数是：%d",a);
	else
		printf("较大的数是：%d",b);
	return 0;
 } 
