/**************************
** 文件名: pickpeach
** 创建人: 廖雨泰
** 日 期: 2021.10.26
** 修改人: 廖雨泰
** 日 期: 2021.11.1
**------------------------
 *************************/
#include <stdio.h>
#include <stdlib.h>
int pick1(int n);
int pick2(int n);
int peanum=1;
int main()
{
    int day;
    int a,b;
    printf("请输入天数");
    scanf("%d",&day);
    a=pick1(day);          //递归
    b=pick2(day);           //迭代
    printf("%d %d",a,b);
    return 0;
}

/********************************** 
** 函数名: pick1
** 输 入: n
** n--- 天数
** 功能描述: 通过迭代算出桃子数
 ************************************/ 
int pick1(int n)
{
   for(int i=1;i<=n-1;i++)
   {
       peanum=(peanum+1)*2;
   }
   return peanum;
}

/********************************** 
** 函数名: pick2
** 输 入: n
** n--- 天数
** 功能描述: 通过递归算出桃子数
 ************************************/ 
int pick2(int n)
{
    if(n==1)
    {
     return 1;
    }else
    {
    return (pick2(n-1)+1)*2;
    }
}
