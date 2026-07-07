#include <stdio.h>
#define m 10000
int main(){
	int N,a[m],i,c=-1,n;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
	scanf("%d ",&a[i]);
	}
	scanf("%d",&n);
	for(i=1;i<=N;i++){
		if(a[i]==n){
			c=i;
			break;
		}
	} 
	printf("%d",c);
	return 0;
}
