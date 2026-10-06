#include<stdio.h>
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	char s;
	int a,b;
	scanf("%c %d %d",&s,&a,&b);
	switch(s){
		case'+':printf("%d\n",a+b);break;
		case'-':printf("%d\n",a-b);break;
		case'*':printf("%d\n",a*b);break;
		case'/':
			if(b!=0)
				{printf("%d\n",a/b);}
			else
				{printf("��������Ϊ0\n");} 
			break;
		default:printf("�������\n");
		
	}
	return 0;
 } 
