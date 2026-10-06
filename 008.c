#include<stdio.h>
#include <windows.h>
int main(){
	SetConsoleOutputCP(65001);
	int n;
	scanf("%d",&n);
	switch(n) 
	{case 1: case 2: case 3:
	printf("%d�����ڵ�һ����",n);break;
	case 4: case5: case6:
	printf("%d�����ڵڶ�����",n);break;
	case 7: case 8: case 9:
	printf("%d�����ڵ�������",n);break;
	case 10: case 11: case 12:
	printf("%d�����ڵ��ļ���",n);break;
	default: printf("�������");
	} 
	return 0;
} 
