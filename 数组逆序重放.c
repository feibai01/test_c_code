#include<stdio.h>
int main(){
	int i,j=0,n;
	int a[100];
	scanf("%d ",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<n/2;i++){
		j=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=j;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
