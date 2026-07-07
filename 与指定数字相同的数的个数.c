#include <stdio.h>
#define m 1000
int main(){
	int N,a[m],i,c,n;
	scanf("%d",&N);
	for(i=0;i<N;i++){
	scanf("%d ",&a[i]);
	}
	scanf("%d",&n);
	c=0;
	for(i=0;i<N;i++){
	if(a[i]==n)
	c++;
	}
	printf("%d",c);
	return 0;
}
