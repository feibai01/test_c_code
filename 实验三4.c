#include <stdio.h>
int max,min;   
void MAX1(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    max=a;
}
void MIN1(int a,int b)
{
    min = a*b/max;
}

int MAX2(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int MIN2(int a,int b,int h)
{
    return a*b/h;
}

int main()
{
    int m,n,h;
    printf("输入两个整数：");
    scanf("%d %d",&m,&n);

    h=MAX2(m,n);
    int l=MIN2(m,n,h);
    printf("2 最大公约数：%d 最小公倍数：%d\n\n",h,l);

   
    MAX1(m,n);
    MIN1(m,n);
    printf("1 最大公约数：%d 最小公倍数：%d",max,min);

    return 0;
}
