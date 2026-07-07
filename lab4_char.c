#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001); // 强制控制台UTF-8
	char c1,c2;
	c1='A';
	c2='b';
	printf("数字%d",c1+c2);
	return 0;
}
