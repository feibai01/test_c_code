#include <stdio.h>
int main(){
	float a,b,c,sum=0,max,i=1;
	scanf("%f %f %f",&a,&b,&c);
	max=a>b?a:b;
	max=max>c?max:c;
	for(i=1;i<=max;i++){
		if(i<=a){
			sum+=i;}
		if(i<=b){
			sum+=i*i;}
		if(i<=c){
			sum+=1/i;}
		}
	printf("%.2f",sum);
	return 0;
}
