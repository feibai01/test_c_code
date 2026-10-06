#include<stdio.h>// ѡ������ 
#include <windows.h>
int main(){
	SetConsoleOutputCP(65001);
	int nums[10];
	int i,j,min_index,temp;
	// ����10������
	for(i=0;i<10;i++){
		scanf("%d",&nums[i]);
	}
	// ѡ�����򣺴�С����
	for(i=0;i<9;i++){
		min_index=i; // ���赱ǰλ������Сֵ
		for(j=i+1;j<10;j++){
			if(nums[j]<nums[min_index]){
				min_index=j; 
			}// �ҵ���nums[min_index]Ϊ������������С������������Сֵ�±�
		}
		 // �����Сֵ���ڵ�ǰλ�ã��ͽ���
		if(min_index != i){
			temp=nums[i];
			nums[i]=nums[min_index];
			nums[min_index]=temp;
		}
	}
	 // ��������Ľ�������ո�ָ���
	for(i=0;i<10;i++){
		printf("%d ",nums[i]);
	}	
	return 0;
} 
