#include<stdio.h>
int main(){
    int a[100],i,j,n,k,temp;

    // 只要能成功读到1个整数，就继续循环（等价于!=EOF）
    while(scanf("%d",&n) == 1){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        } 
        for(i=0;i<n-1;i++){
            k=i;
            for(j=i+1;j<n;j++){
                if(a[j]<a[k]){
                    k=j;
                }
            }
            if(k!=i){
                temp=a[i];
                a[i]=a[k];
                a[k]=temp;
            }
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}

