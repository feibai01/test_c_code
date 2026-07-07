#include<stdio.h>
int main(){
	// 定义有序数组，预留足够空间
	int nums[100]={0,2,4,6,8,10,12,14,16,18};
	int len=10;		// 当前有效元素个数
	int num,n,i;
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
	// 输入要插入的数字
	scanf("%d",&num);
	// 查找第一个大于num的位置，确定插入点n
	for(i=0;i<len;i++){
		if(nums[i]>num){
			n=i;
			break;
		}
		n=len;// 若都小，插在末尾
	}
	// 从后往前，元素后移，腾出位置
	for(i=len;i>n;i--){
		nums[i]=nums[i-1];
	}
	// 插入数字	
	nums[n]=num;
	len++;// 有效长度+1
	
	// 输出插入后的数组
	for(i=0;i<len;i++){
		printf("%d ",nums[i]);
	}
	return 0;
} 
