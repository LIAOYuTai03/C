/**************************
** 文件名: keepaccounts
** 创建人: 廖雨泰
** 日 期: 2021.10.26
** 修改人: 廖雨泰
** 日 期: 2021.11.1
**------------------------
 *************************/
#include <stdio.h>
#include <stdlib.h>
#define N 10
void SelectionSort(int a[],int (*compare)(int a,int b));
void BubbleSort(int a[]);
void SelectionSort1(int a[]);
void BinarySearch(int a);

int Ascending(int a,int b);
int Descending(int a,int b);
int compare(int a,int b);
    int id[N]={};
    int earn[N]={};
    int cost[N]={};
    int imid;
    int itemp;
    int inum=0;

int main()
{
    int ikey;
    int input;

    while(1){
    printf("1.Input record\n2.Selection Sort in descending order by expenses\n3.Selection Sort in ascending order by expenses\n4.Bubble Sort in ascending order by income\n5.Search records by ID using Binary Search\n6.List records which have more expenses than income\n7.List all records\n0.Exit\n");
    printf("Please enter your choice:");
    scanf("%d",&input);

    switch (input){
    case 1:while(id[inum-1]!=-1&&earn[inum-1]!=-1&&cost[inum-1]!=-1)
                {
                 scanf("%d,%d,%d",&id[inum],&earn[inum],&cost[inum]);
                 inum++;
                }
            break;
    case 2:SelectionSort(cost,Descending);
            break;
    case 3:SelectionSort(cost,Ascending);
            break;
    case 4:BubbleSort(earn);
            break;
    case 5:printf("Please input the user id:");
            scanf("%d",&ikey);
            SelectionSort1(id);
            BinarySearch(ikey);
            break;
    case 6:
        for(int i=0;i<=inum-2;i++)
                {
                    if(earn[i]<cost[i])
                    {
                        printf("Id      Income  Expenses\n");
                        printf("%-8d%-8d%-8d\n",id[i],earn[i],cost[i]);
                    }
                }
            break;
    case 7:SelectionSort(id,Ascending);
            break;
    case 0:printf("退出系统");
            exit(0);
    default:printf("请输入正确的选项\n");
    }
    }
    return 0;
}

/********************************** 
** 函数名: SelectionSort
** 输 入: a[],compare
** a---排序关键字
** compare---函数指针确定升降序
** 功能描述: 选择排序并输出
** 全局变量:imid,id[],earn[],cost[]
*/

void SelectionSort(int a[],int (*compare)(int a,int b))
{
    for(int i=0;i<=inum-2;i++)
    {
        imid=i;
        for(int j=i+1;j<=inum-2;j++)
        {
            if((*compare)(a[imid],a[j]))
            {
                imid=j;
            }
        }
        if(imid!=i)
        {
            itemp=id[imid];
            id[imid]=id[i];
            id[i]=itemp;
            itemp=earn[imid];
            earn[imid]=earn[i];
            earn[i]=itemp;
            itemp=cost[imid];
            cost[imid]=cost[i];
            cost[i]=itemp;
        }
    }
    printf("Id      Income  Expenses\n");
    for(int i=0;i<=inum-2;i++)
    {
        printf("%-8d%-8d%-8d\n",id[i],earn[i],cost[i]);
    }
}

/********************************** 
** 函数名: BubbleSort
** 输 入: a[]
** a--- 排序关键字
** 功能描述: 冒泡排序并输出
** 全局变量:imid,id[],earn[],cost[]
*/
void BubbleSort(int a[])
{
    int flag1;
    for(int i=0;i<=inum-2;i++)
    {
        for(int j=1;j<=inum-2-i;j++)
        {
            flag1=0;
            if(earn[j-1]>earn[j])
            {
                itemp=id[j-1];
                id[j-1]=id[j];
                id[j]=itemp;
                itemp=earn[j-1];
                earn[j-1]=earn[j];
                earn[j]=itemp;
                itemp=cost[j-1];
                cost[j-1]=cost[j];
                cost[j]=itemp;
                flag1=1;
            }
        }
        if(flag1==0)
        {
            break;
        }
    }
    printf("Id      Income  Expenses\n");
    for(int i=0;i<=inum-2;i++)
    {
        printf("%-8d%-8d%-8d\n",id[i],earn[i],cost[i]);
    }
}

/********************************** 
** 函数名: BrinarySearch
** 输 入: a[]
** a--- 排序关键字
** 功能描述: 二分查找排序并输出
** 全局变量:imid,id[imid],earn[imid],cost[imid]
*/
void BinarySearch(int a)
{
    int left=0;
    int right=inum-2;
    while(left<=right)
    {
        imid=(right-left)/2+left;
        if(id[imid]<a)
        {
            left=imid+1;
        }else if(id[imid]>a)
        {
            right=imid-1;
        }else
        {
            break;
        }
    }
    if(left<=right)
    {
    printf("Id      Income  Expenses\n");
    printf("%-8d%-8d%-8d\n",id[imid],earn[imid],cost[imid]);
    }else
    {
        printf("Not Found!\n");
    }
}

/********************************** 
** 函数名: SelectionSort1
** 输 入: a[]
** a--- 排序关键字
** 功能描述: 只进行选择排序
** 全局变量:imid,id[],earn[],cost[]
*/
void SelectionSort1(int a[])
{
    for(int i=0;i<=inum-2;i++)
    {
        imid=i;
        for(int j=i+1;j<=inum-2;j++)
        {
                if(a[imid]<a[j])
            {
                imid=j;
            }
        }
        if(imid!=i)
        {
            itemp=id[imid];
            id[imid]=id[i];
            id[i]=itemp;
            itemp=earn[imid];
            earn[imid]=earn[i];
            earn[i]=itemp;
            itemp=cost[imid];
            cost[imid]=cost[i];
            cost[i]=itemp;
        }
    }
    return;
}

/********************************** 
** 函数名: Ascending
** 输 入: a,b
** 功能描述: 提供升序的判断
*/
int Ascending(int a,int b)
{
    return a>b;
}

/********************************** 
** 函数名: Ascending
** 输 入: a,b
** 功能描述: 提供降序的判断
*/
int Descending(int a,int b)
{
    return a<b;
}
