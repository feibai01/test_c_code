#include<stdio.h>
int main()
{
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
				{printf("除数不能为0\n");} 
			break;
		default:printf("输入错误\n");
		
	}
	return 0;
 } 
