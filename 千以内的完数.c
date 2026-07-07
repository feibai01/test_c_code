#include<stdio.h>
int main(){
	int n=1000,sum,i,j;
	for(i=1;i<n;i++){
		sum=0;
		for(j=1;j<i;j++){
			if(i%j==0)
			sum += j;
		}
		if(sum==i) 
		printf("%5d",i);
	}
	return 0;
} 
