#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int a,b,c;
	printf("请输入两个整数：");
	scanf("%d %d",&a,&b) ; 
	if(a>b){
		c=a;
		a=b;
		b=c;
	}
	printf("从小到大:%d %d\n",a,b);
	return 0;
 } 
