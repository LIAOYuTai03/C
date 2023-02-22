/*******************
**文件名：circle
**创建人：廖雨泰
**日期：11.5
**修改人：廖雨泰
**日期：11.6
********************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char goal[20]={};
    int i=0;
    int flag=0;
    int flag1=0;

    gets(goal);

    while(goal[i]!='\0')
    {
        i++;
    }

    char *p=goal;

    if(i%2==1)                                    //判断长度是奇数还是偶数
    {
        flag=1;

    }else
    {
        flag=0;
    }

    if(flag==1)
    {
        for(int j=0;j<(i-1)/2;j++)
        {
            if(p[j]!=p[i-1-j])
            {
                printf("不是回文字符串");
                flag1=1;
                break;

            }
        }
    }else
    {
        for(int j=0;j<i/2;j++)
        {
            if(p[j]!=p[i-1-j])
            {
                printf("不是回文字符串");
                flag1=1;
                break;

            }
        }
    }

    if(flag1==0)
    {
        printf("是回文字符串");
    }
    return 0;
}
