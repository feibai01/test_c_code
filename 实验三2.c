#include <stdio.h>
#include <windows.h>
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
    SetConsoleOutputCP(65001);
    int num;
    printf("������������");
    scanf("%d",&num);
    printf("�ݹ������");
    fun(num);
    printf("\n�ǵݹ������");
    Nofun(num);
    return 0;
}
