#include<stdio.h>
int main(){
	int a[100],i,j,k,temp;
	int n;
	scanf("%d\n",&n);
	// 输入数组元素
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	// 选择排序（从小到大）
	for(i=0;i<n;i++){
		k=i;// 假设当前是最小值
		for(j=i+1;j<n;j++){
			if(a[j]<a[k]){
				k=j;// 更新最小值位置
			}
		}
		// 交换
		if(k!=i){
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;	
		}
		
	}
	// 输出排序结果
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
} 
