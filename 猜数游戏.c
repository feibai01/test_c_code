#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>
int main(){
	SetConsoleOutputCP(65001);
	srand((unsigned)time(NULL));
	int N;
	char s[10];
	printf("��Ϸ�˵�\n");
	printf("*******������Ϸ*******\n");
	printf("���� ����0��1��2�е�����\n");
	printf("�м�����0��1��2��3��4�е�����\n");
	printf("�߼�����0��1��2��3��4��5��6�е�����\n");
	printf("��ѡ����Ϸ�ȼ�:");
	scanf("%s",&s);
	if(strcmp(s,"����")==0)N=2;
	else if(strcmp(s,"�м�")==0)N=4;
	else if(strcmp(s,"�߼�")==0)N=6;
	else {
	printf("ѡ�����");
	return 0;
	}
	int n=rand()%N+1;
	int g,count=2;
	for(count;count>=0;count--){
		printf("��������µ���:");
		scanf("%d",&g);
		if(count>0){
			if(g==n){
				printf("�������\n");
				break;
				}
			else
				printf("�´��ˣ��㻹��%d�λ���\n",count); 
		}
		else
			printf("Game Over");
	}
	return 0;
} 
