#include<stdio.h> 
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int w;
	float m; 
	scanf("%d",&w);
	if(w<=5)
		printf("�˷�10Ԫ");
	else if(w<=10)
		{
		m=10+(w-5)*1.5;
		printf("�˷�%fԪ",m);}
	else
		{
		m=17.5+(w-10)*2;
		printf("�˷�%fԪ",m);}
	return 0;
}
