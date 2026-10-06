#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int a,b;
	a=sizeof(3+5.0);/*�������ʽ ��3+0.5�� ��������ռ�ֽ���*/ 
	b=sizeof 3+5.0;/*�ټ������ʽ 3+0.5 ��������ռ�ֽ���*/ 
	printf("%d,%d,%d\n",a,b,sizeof("china"));
	return 0;
 } 
