#include<stdio.h>
int main(){
	int n=0,z=0,f=0,sum=0;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		else if(n>0)z++;
		else f++;
		sum+=n;
	}
	printf("%d %d %d",z,f,sum);
	return 0;
} 
