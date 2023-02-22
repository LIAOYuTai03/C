#include <stdio.h>
#include <stdlib.h>

int main()
{int fm1,fm2,fz1,fz2,a,b;
printf("input a/b,c/d:");
scanf("%d/%d,%d/%d",&fz1,&fm1,&fz2,&fm2);
a=fz1*fm2;
b=fz2*fm1;
if(a>b){
    printf("%d/%d>%d/%d",fz1,fm1,fz2,fm2);
}else if(a==b){
printf("%d/%d=%d/%d",fz1,fm1,fz2,fm2);
}else{
printf("%d/%d<%d/%d",fz1,fm1,fz2,fm2);
}
return 0;
}
