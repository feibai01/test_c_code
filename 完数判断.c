#include<stdio.h>
int main(){
	int num = 0;
	scanf("%d", &num);
	int sum = 0,i = 0,j = 0;
	for (i = 1; i <= num; i++){
		sum = 0;
		for (j = 1; j < i; j++){
			if (i % j == 0){
				sum += j;}}
		if (sum == i){
			printf("%d its factors are ", i);
			sum = 0;
			for (j = 1; j < i; j++){
				if (i % j == 0){
				sum += j;
				printf("%d ", j);}}
			printf("\n");}}
	return 0;
}
