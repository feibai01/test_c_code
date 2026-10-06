#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int s;
	scanf("%d",&s);
	if(s>=0&&s<=59){
	printf("������");}
	else if(s>=60&&s<70){printf("����");}
	else if (s>=70&&s<80){printf("�е�");}
	else if (s>=80&&s<90){printf("����");}
	else {printf("����");}
	return 0;
 } 
