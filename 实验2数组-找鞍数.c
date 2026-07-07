#include<stdio.h>
int main(){
	int nar1[3][4];
	int i,j,k;
	int max,col;
	int flag; 
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
		scanf("%d",&nar1[i][j]);
		}
	}
	for(i=0;i<3;i++){
		max=nar1[i][0];
		col=0;
		for(j=1;j<4;j++){
			if(nar1[i][j]>max){
				max=nar1[i][j];
				col=j;
			}
		}
		flag=1;
		for(k=0;k<3;k++){
			if(nar1[k][col]<max){
				flag=0;
				break;
			}
		}
		if(flag==1){
			printf("鞍点：第%d行，第%d列，值=%d\n",i+1,col+1,max);
			return 0;
		}
	}
	printf("没有鞍点\n");
	return 0;
}
