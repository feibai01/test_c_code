#include<stdio.h> 
int main()
{
	int w;
	float m; 
	scanf("%d",&w);
	if(w<=5)
		printf("运费10元");
	else if(w<=10)
		{
		m=10+(w-5)*1.5;
		printf("运费%f元",m);}
	else
		{
		m=17.5+(w-10)*2;
		printf("运费%f元",m);}
	return 0;
}
