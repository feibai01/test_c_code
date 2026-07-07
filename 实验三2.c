#include <stdio.h>
void fun(int n)
{
    if(n<0)
    {
        putchar('-');
        n = -n;
    }
    if(n/10 != 0)     
        fun(n/10);
    putchar(n%10 + '0');
}
void Nofun(int n)
{
    char buf[20];
    int i=0,flag=1;
    if(n<0)
    {
        putchar('-');
        n=-n;
    }
    do{
        buf[i++] = n%10 + '0';
        n /=10;
    }while(n!=0);
    while(i>0)
        putchar(buf[--i]);
}

int main()
{
    int num;
    printf("请输入整数：");
    scanf("%d",&num);
    printf("递归输出：");
    fun(num);
    printf("\n非递归输出：");
    Nofun(num);
    return 0;
}
