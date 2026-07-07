#include<stdio.h> 
#include <windows.h>
int main()
{
	SetConsoleOutputCP(65001);
	int x;
	scanf("%d",&x);
	if(x%2==0)
		printf("%d是偶数\n",x);
	else
		printf("%d是奇数\n",x);
	return 0;
}
