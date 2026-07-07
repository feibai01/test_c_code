#include<stdio.h>
int main()
{
	int s;
	scanf("%d",&s);
	if(s>=0&&s<=59){
	printf("不及格");}
	else if(s>=60&&s<70){printf("及格");}
	else if (s>=70&&s<80){printf("中等");}
	else if (s>=80&&s<90){printf("良好");}
	else {printf("优秀");}
	return 0;
 } 
