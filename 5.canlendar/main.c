/**************************
** 文件名: calendar
** 创建人: 廖雨泰
** 日 期: 2021.10.26
** 修改人: 廖雨泰
** 日 期: 2021.11.1
**------------------------
 *************************/
#include <stdio.h>
#include <stdlib.h>
int gap = 7;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int year , firstday , days ;
void PrintCalendar(int i);
void Pan(int n);
int main()
{
    printf("请输入年份");
    scanf("%d", &year );
    Pan(year);            //判断是否为闰年
    days = year-1 + (year-1)/400 + (year-1)/4 - (year-1)/100;
    firstday = (days+1)%7;
    //printf("%d",firstday);
    for(int i=1;i<=12;i++)
    {
        PrintCalendar(i);
    }
    return 0;
}

/********************************** 
** 函数名: PrintCalendar
** 输 入: i
** i--- 距离上一个星期日的天数
** 功能描述: 输出日历
** 全局变量: gap,firstday,a[]
 ************************************/
void PrintCalendar(int i)
{
    int day=1;
    for(int i=1;i<=3*gap;i++)
    {
        printf(" ");
    }

    printf("%d-%d",year,i);
    printf("\nSun    Mon    Tues   Wed    Thur   Fri    Sat\n");

    for(int i=1;i<=firstday*gap;i++)
    {
        printf(" ");
    }

    while(day<=a[i-1])
    {
    printf("%-7d",day);
    day++;
    if((day+firstday-1)%7==0)
     {
      printf("\n");
     }
    }
    printf("\n");
    firstday=(day+firstday-1)%7;
}

/********************************** 
** 函数名: pan
** 输 入: n
** n--- 年份 
** 功能描述: 将闰年二月设置为29天
** 全局变量: a[2]
 ************************************/
void Pan(int n)
{
    if((n%4==0&&n%100!=0)||n%400==0)
    {
        a[2]=29;
    }
}
