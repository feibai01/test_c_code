#include<stdio.h>
int main()
{
	float a,b,h,area;
	printf("Enter a,b,h=");
	scanf("%f %f %f",&a,&b,&h);
	area=1.0/2*(a+b)*h; 
	printf("area=%8.2f\n",area);
	return 0;
 } 
