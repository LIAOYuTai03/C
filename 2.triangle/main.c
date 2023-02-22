#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
 float a,b,c;
 float p,s;
 printf("请输入三边长");
 scanf("%f %f %f",&a,&b,&c);
 if(a+b-c<1E-2||a+c-b<1E-2||b+c-a<1E-2){
    printf("不是三角形");
 }else{
    if(fabs(a-b)<1E-2&&fabs(a-c)<1E-2&&fabs(c-b)<1E-2)
    {
        printf("等边三角形");
    }else if(fabs(a-b)<1E-2||fabs(a-c)<1E-2||fabs(c-b)<1E-2){
        if(fabs(a*a+b*b-c*c)<=1E-2||fabs(a*a+c*c-b*b)<=1E-2||fabs(b*b+c+c-a*a)<=1E-2)
            {
                printf("等腰直角三角形");
            }else
            {
               printf("等腰三角形");
            }
    }else if(fabs(a*a+b*b-c*c)<=1E-2||fabs(a*a+c*c-b*b)<=1E-2||fabs(b*b+c+c-a*a)<=1E-2){
        printf("直角三角形");
    }else{
        printf("一般三角形");
    }
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("\n面积为%.2f",s);
    return 0;
 }
}
