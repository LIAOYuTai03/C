/*******************
**文件名：numbleadd
**创建人：廖雨泰
**日期：11.5
**修改人：廖雨泰
**日期：11.6
********************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a[50]={};
    int b[50]={};
    char c[102]={};                     //存储两个数
    int d[51]={};
    int count=0;                       //标记第一个数的位数
    int count1=0;
    int count2=0;                      //标记第二个数的位数
    int count3=0;                      //两数位数的最大值
    int carry=0;                       //进位

    gets(c);

    for(count=0;count<=100;count++)
    {
        if(c[count]==' ')
        {
            break;
        }
    }

    for(int i=count-1;i>=0;i--)
    {
        a[count-1-i]=c[i]-'0';
    }

    for(count1=count+1;count1<=100;count1++)
    {
        if(c[count1]=='\0')
        {
            break;
        }
    }

    for(int i=count1-1;i>count;i--)
    {

        b[count1-1-i]=c[i]-'0';
        count2++;
    }

    if(count>count2)
    {
        count3=count;
    }else if(count<=count2)
    {
        count3=count2;
    }

    for(int i=0;i<=count3;i++)
    {
        d[i]=a[i]+b[i]+carry;
        carry=d[i]/10;
        d[i]%=10;
    }

    if(d[count3]!=0)
    {
        printf("%d",d[count3]);
    }

    for(int i=count3-1;i>=0;i--)
    {
        printf("%d",d[i]);
    }
    return 0;
}
