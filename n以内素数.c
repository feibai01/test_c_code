#include <stdio.h>
#define m 1000
int main(){
	int i,j,n;
	scanf("%d",&n);
	for(i=2;i<n;i++){
	for(j=2;j<i;j++){
	if(i%j==0){
	break;}}
	if(i==j){
	printf("%d\n",i);}}
	return 0;
}
