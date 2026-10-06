#include<stdio.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    int a[100],i,j,n,k,temp;

    // ֻҪ�ܳɹ�����1���������ͼ���ѭ�����ȼ���!=EOF��
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

