#include<stdio.h>
int main(){
	int a[100],i,temp;
	int n=9,num,k;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&num);
	k=n;
	for(i=0;i<n;i++){
		if(a[i]>num){
			k=i;
			break; 
		}
	}
	for(i=n;i>k;i--){
		a[i]=a[i-1];
	}
	a[k]=num;
	n++;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
} 
