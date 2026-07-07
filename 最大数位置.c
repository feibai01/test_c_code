#include <stdio.h>
#define m 1000
int main(){
	int N,a[m],i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
	scanf("%d",&a[i]);
	}
	j=1;
	for(i=1;i<=N;i++){
		if(a[i]>a[j]){
			j=i;
		} 
	} 
	printf("%d",j);
	return 0;
}
