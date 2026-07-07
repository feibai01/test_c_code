#include<stdio.h>
int main(){
	int n,num,s=0;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		num=n;
		s=0;
		while(num!=0){
			s=s*10+num%10;
			num /=10;
		}
		if(s==n){
			printf("ÊÇ");
		}else{
			printf("·ñ");
		}
	}
	return 0;
} 
