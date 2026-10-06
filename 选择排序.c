#include<stdio.h>
#include <windows.h>
int main(){
	SetConsoleOutputCP(65001);
	int a[100],i,j,k,temp;
	int n;
	scanf("%d\n",&n);
	// ��������Ԫ��
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	// ѡ�����򣨴�С����
	for(i=0;i<n;i++){
		k=i;// ���赱ǰ����Сֵ
		for(j=i+1;j<n;j++){
			if(a[j]<a[k]){
				k=j;// ������Сֵλ��
			}
		}
		// ����
		if(k!=i){
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;	
		}
		
	}
	// ���������
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
} 
