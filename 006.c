#include<stdio.h>
int main()
{
	char a;
	scanf("%c",&a);
	if (65<=a&&a<=90)
		printf("´óÐ´×ÖÄ¸");
	else if (97<=a&&a<=122)
		printf("Ð¡Ð´×ÖÄ¸");
	else
		printf("·Ç×ÖÄ¸×Ö·û");
	return 0;
 } 
