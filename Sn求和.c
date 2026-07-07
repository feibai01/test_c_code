#include <stdio.h>
int main(){
	int sum=0,s=1,n,y=0,i=1;
	scanf("%d",&n);
	for(i=1;i<=5;i++){
	sum=sum+s;
	s=s*10;
	y=y+sum;}
	y=y*2;
	printf("%d",y);
	return 0;
}
