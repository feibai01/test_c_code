#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	char a;
	scanf("%c",&a);
	if (65<=a&&a<=90)
		printf("��д��ĸ");
	else if (97<=a&&a<=122)
		printf("Сд��ĸ");
	else
		printf("����ĸ�ַ�");
	return 0;
 } 
