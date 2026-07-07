#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main(){
	srand((unsigned)time(NULL));
	int N;
	char s[10];
	printf("游戏菜单\n");
	printf("*******猜数游戏*******\n");
	printf("初级 （猜0、1、2中的数）\n");
	printf("中级（猜0、1、2、3、4中的数）\n");
	printf("高级（猜0、1、2、3、4、5、6中的数）\n");
	printf("请选择游戏等级:");
	scanf("%s",&s);
	if(strcmp(s,"初级")==0)N=2;
	else if(strcmp(s,"中级")==0)N=4;
	else if(strcmp(s,"高级")==0)N=6;
	else {
	printf("选择错误");
	return 0;
	}
	int n=rand()%N+1;
	int g,count=2;
	for(count;count>=0;count--){
		printf("请输入你猜的数:");
		scanf("%d",&g);
		if(count>0){
			if(g==n){
				printf("你真棒！\n");
				break;
				}
			else
				printf("猜错了，你还有%d次机会\n",count); 
		}
		else
			printf("Game Over");
	}
	return 0;
} 
