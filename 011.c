#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int d=2019%7;
	switch(d){
		case 0: printf("������");break;
		case 1: printf("����һ");break;
		case 2: printf("���ڶ�");break;
		case 3: printf("������");break;
		case 4: printf("������");break;
		case 5: printf("������");break;
		case 6: printf("������");break;
		return 0; 
	}
}
