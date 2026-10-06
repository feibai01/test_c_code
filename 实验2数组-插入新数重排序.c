#include<stdio.h>
#include <windows.h>
int main(){
	SetConsoleOutputCP(65001);
	// �����������飬Ԥ���㹻�ռ�
	int nums[100]={0,2,4,6,8,10,12,14,16,18};
	int len=10;		// ��ǰ��ЧԪ�ظ���
	int num,n,i;
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
	// ����Ҫ���������
	scanf("%d",&num);
	// ���ҵ�һ������num��λ�ã�ȷ�������n
	for(i=0;i<len;i++){
		if(nums[i]>num){
			n=i;
			break;
		}
		n=len;// ����С������ĩβ
	}
	// �Ӻ���ǰ��Ԫ�غ��ƣ��ڳ�λ��
	for(i=len;i>n;i--){
		nums[i]=nums[i-1];
	}
	// ��������	
	nums[n]=num;
	len++;// ��Ч����+1
	
	// �������������
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
	return 0;
} 
