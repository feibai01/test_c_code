#include<stdio.h>
int main()
{
	int a,b;
	a=sizeof(3+5.0);/*计算表达式 （3+0.5） 的类型所占字节数*/ 
	b=sizeof 3+5.0;/*再计算表达式 3+0.5 的类型所占字节数*/ 
	printf("%d,%d,%d\n",a,b,sizeof("china"));
	return 0;
 } 
