#include<stdio.h>
int main(){
	int a=0,b=0,c=0,d=0,e=0;
	char s[81];
	int i,j;
	for(i=0;i<3;i++){
		gets(s);
		for(j=0;s[j]!='\0';j++){
			if('A'<=s[j]&&s[j]<='Z')a++;
			else if('a'<=s[j]&&s[j]<='z')b++;
			else if('0'<=s[j]&&s[j]<='9')c++;
			else if(s[j]==' ')d++;
			else e++;
		}
	}
	printf("%d %d %d %d %d ",a,b,c,d,e);
	return 0;
} 
