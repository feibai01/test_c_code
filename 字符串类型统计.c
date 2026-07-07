#include <stdio.h>
int main() {
	char s[201];
	scanf("%[^\n]",&s);
	int i=0,abc=0,sz=0,kg=0,qt=0;
	while(s[i]!='\0'){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			++abc;
		else if(s[i]>='0'&&s[i]<='9')
			++sz;
		else if(s[i]==' ')
			++kg;
		else
			++qt;
		++i;
		}
	printf("%d %d %d %d",abc,sz,kg,qt);
	return 0;
}
