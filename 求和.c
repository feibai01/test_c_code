#include<stdio.h>
int main(){
	int a=2,b=1,N=0,i=1;
	double sum=0.0;
	scanf("%d",&N);
	while(i<=N){
	sum+=(double)a/b;
	int s1=a+b,s2=a;
	a=s1;
	b=s2;
	i++;
	}
	printf("%.2f",sum);
	return 0;
}
