#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
 float a,b,c;
 float p,s;
 printf("���������߳�");
 scanf("%f %f %f",&a,&b,&c);
 if(a+b-c<1E-2||a+c-b<1E-2||b+c-a<1E-2){
    printf("����������");
 }else{
    if(fabs(a-b)<1E-2&&fabs(a-c)<1E-2&&fabs(c-b)<1E-2)
    {
        printf("�ȱ�������");
    }else if(fabs(a-b)<1E-2||fabs(a-c)<1E-2||fabs(c-b)<1E-2){
        if(fabs(a*a+b*b-c*c)<=1E-2||fabs(a*a+c*c-b*b)<=1E-2||fabs(b*b+c+c-a*a)<=1E-2)
            {
                printf("����ֱ��������");
            }else
            {
               printf("����������");
            }
    }else if(fabs(a*a+b*b-c*c)<=1E-2||fabs(a*a+c*c-b*b)<=1E-2||fabs(b*b+c+c-a*a)<=1E-2){
        printf("ֱ��������");
    }else{
        printf("һ��������");
    }
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("\n���Ϊ%.2f",s);
    return 0;
 }
}
