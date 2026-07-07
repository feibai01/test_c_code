#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	switch(n) 
	{case 1: case 2: case 3:
	printf("%d月属于第一季度",n);break;
	case 4: case5: case6:
	printf("%d月属于第二季度",n);break;
	case 7: case 8: case 9:
	printf("%d月属于第三季度",n);break;
	case 10: case 11: case 12:
	printf("%d月属于第四季度",n);break;
	default: printf("输入错误");
	} 
	return 0;
} 
