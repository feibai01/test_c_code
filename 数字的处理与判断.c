#include <stdio.h>
int main(){
	int x,d=0,mask=1;
	scanf("%d",&x);
	int t=x,m=x,c=1;
	while(t>9){
	t/=10;
	mask*=10;
	c++;}
	printf("%d\n",c);
	do{
	d=x/mask;
	printf("%d",d);
	if(mask>9){
	printf(" ");}
	x%=mask;
	mask/=10;}
	while(mask>0);
	printf("\n");
	do{
	int n=m%10;
	printf("%d",n);
	m/=10;}
	while(m>0);
	return 0;
}
