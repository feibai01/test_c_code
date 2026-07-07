#include <stdio.h>
long long int fun(long long int n){
     if(n==1) return 1;
     return n * fun(n-1);
 }

 int main(){
    int n,i=1;
    long long int result = 0;
     scanf("%d",&n);
    for (i = 1; i <= n; i++)
        result += fun(i);
    printf("%lld",result);
}
