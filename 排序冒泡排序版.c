//冒泡排序
#include<stdio.h>
int main(){
    int a[100],i,j,n,temp;

    while(scanf("%d",&n) == 1){
        // 读取n个整数
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        // 冒泡排序（从小到大）
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                if(a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        // 按题目要求输出：每个数后带空格，每组占一行
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
} 
