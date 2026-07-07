#include<stdio.h>
int main(){
	int n,i,j,sum=1;
	scanf("%d",&n);
	for(i=1;sum<=n;i+=2){
		sum++;
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
