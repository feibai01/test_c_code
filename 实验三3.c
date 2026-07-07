#include <stdio.h>
int letter=0,digit=0,space=0,other=0;
void Count(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            letter++;
        else if(s[i]>='0'&&s[i]<='9')
            digit++;
        else if(s[i]==' ')
            space++;
        else
            other++;
        i++;
    }
}
void Count2(char s[],int cnt[])
{
    int i=0;
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    while(s[i]!='\0')
    {
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))
            cnt[0]++;
        else if(s[i]>='0'&&s[i]<='9')
            cnt[1]++;
        else if(s[i]==' ')
            cnt[2]++;
        else
            cnt[3]++;
        i++;
    }
}

int main()
{
    char str[100];
    int res[4];
    printf("请输入字符串：");
    gets(str);
    
    Count(str);
    printf("Count 字母:%d 数字:%d 空格:%d 其他:%d\n\n",letter,digit,space,other);

    Count2(str,res);
    printf("Count1 字母:%d 数字:%d 空格:%d 其他:%d\n",res[0],res[1],res[2],res[3]);

    return 0;
}
