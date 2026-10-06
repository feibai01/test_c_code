#include <stdio.h>
#include <windows.h>
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
    SetConsoleOutputCP(65001);
    int m,n,h;
    printf("��������������");
    scanf("%d %d",&m,&n);

    h=MAX2(m,n);
    int l=MIN2(m,n,h);
    printf("2 ���Լ����%d ��С��������%d\n\n",h,l);

   
    MAX1(m,n);
    MIN1(m,n);
    printf("1 ���Լ����%d ��С��������%d",max,min);

    return 0;
}
