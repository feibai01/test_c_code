#include<stdio.h>
main()
{ 
int i,j,s=0; 
int a[4][4]={1,2,3,4,0,2,4,6,3,6,9,12,3,2,1,0};
for(j=0;j<4;j++)
{i=j;
if(i>2) i=3-j;
s+=a[i][j];}
printf("%d\n",s);
return 0; 
} 
