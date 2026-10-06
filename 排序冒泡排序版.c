//ð������
#include<stdio.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    int a[100],i,j,n,temp;

    while(scanf("%d",&n) == 1){
        // ��ȡn������
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        // ð�����򣨴�С����
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                if(a[j] > a[j+1]){
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        // ����ĿҪ�������ÿ��������ո�ÿ��ռһ��
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
} 
