#include<stdio.h>// 选择排序法 
int main(){
	int nums[10];
	int i,j,min_index,temp;
	// 输入10个整数
	for(i=0;i<10;i++){
		scanf("%d",&nums[i]);
	}
	// 选择排序：从小到大
	for(i=0;i<9;i++){
		min_index=i; // 假设当前位置是最小值
		for(j=i+1;j<10;j++){
			if(nums[j]<nums[min_index]){
				min_index=j; 
			}// 找到以nums[min_index]为起点的数组中最小数，并更新最小值下标
		}
		 // 如果最小值不在当前位置，就交换
		if(min_index != i){
			temp=nums[i];
			nums[i]=nums[min_index];
			nums[min_index]=temp;
		}
	}
	 // 输出排序后的结果（带空格分隔）
	for(i=0;i<10;i++){
		printf("%d ",nums[i]);
	}	
	return 0;
} 
