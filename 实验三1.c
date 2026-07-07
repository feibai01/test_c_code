#include <stdio.h>
#include <string.h>
void sortChar(char ch[],int n)
{
    int i,j;
    char t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ch[j]>ch[j+1])
            {
                t=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=t;
            }
        }
    }
}
void sortStr(char str[5][50],int n)
{
    int i,j;
    char temp[50];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(str[j],str[j+1])<0)
            {
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
    }
}
int main()
{
    char c[10];
    int i;
    for(i=0;i<10;i++)
        scanf("%c",&c[i]);
    sortChar(c,10);
    for(i=0;i<10;i++)
        printf("%c",c[i]);
    printf("\n\n");
    char s[5][50];
    for(i=0;i<5;i++)
        scanf("%s",s[i]);
    sortStr(s,5);
    for(i=0;i<5;i++)
        puts(s[i]);
    return 0;
}
