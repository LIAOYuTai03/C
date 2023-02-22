/*******************
**文件名：keepaccounts2.0
**创建人：廖雨泰
**日期：11.5
**修改人：廖雨泰
**日期：11.6
********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *id;
char yhm[10][10];
int *earn;
int *cost;
char temp[10];
char target[10];
int count=0;
void SelectionSort(char a[][10]);
void BrinarySearch(char *a);
void SelectionSort1(int a[]);

int main()
{
    int input;
    int sum1=0;
    int sum2=0;
    int ave1=0;
    int ave2=0;
    id=(int *)malloc(10*sizeof(int));
    earn=(int *)malloc(10*sizeof(int));
    cost=(int *)malloc(10*sizeof(int));

    printf("1.Input record\n2.Sort and list records in alphabetical order by user name\n3.Search records by user name\n4.Calculate and list per capita income and expenses\n5.List records which have more expenses than per capita expenses\n6.List all records\n0．Exit\nPlease enter your choice:\n");

    while(1)
    {
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                while(1)
                {
                scanf("%d",&id[count]);
                count++;
                if(id[count-1]!=-1)
                {
                scanf("%s %d %d",&yhm[count-1][0],&earn[count-1],&cost[count-1]);
                }else
                {
                    realloc(id,(count-1)*sizeof(int));
                    realloc(earn,(count-1)*sizeof(int));                //重新分配
                    realloc(cost,(count-1)*sizeof(int));
                    while(getchar()!='\n');                             //清除缓存
                    break;
                }
                }
                break;
            case 2:
                printf("ID        UserName  Income    Expeses\n");
                SelectionSort(yhm);
                for(int i=0;i<=count-2;i++)
                {
                    printf("%-10d%-10s%-10d%-10d\n",id[i],yhm[i],earn[i],cost[i]);
                }
                break;
            case 3:
                printf("Please input the user name:");
                scanf("%s",target);
                BrinarySearch(target);
                break;
            case 4:
                for(int i=0;i<=count-2;i++)
                {
                    sum1+=earn[i];
                    sum2+=cost[i];
                }
                ave1=sum1/(count-1);
                ave2=sum2/(count-1);
                printf("Per capita income:%d\n",ave1);
                printf("Per capita expenses:%d\n",ave2);
                break;
            case 5:
                printf("ID        UserName  Income    Expeses\n");
                for(int i=0;i<=count-2;i++)
                {
                    if(ave2<cost[i])
                    {
                        printf("%-10d%-10s%-10d%-10d\n",id[i],yhm[i],earn[i],cost[i]);
                    }
                }
                break;
            case 6:
                SelectionSort1(id);
                printf("ID        UserName  Income    Expeses\n");
                for(int i=0;i<=count-2;i++)
                {
                    printf("%-10d%-10s%-10d%-10d\n",id[i],yhm[i],earn[i],cost[i]);
                }
                break;
            case 0:
                free(id);
                free(earn);
                free(cost);
                printf("退出系统");
                exit(0);
            default:
                printf("请输入正确的选项\n");
        }
    }

    return 0;
}

/**********************
**函数名：SelectionSort
**输入：a[][10]
**a[][10]--用户名
**功能描述：选择排序
**全局变量：id,earn,cost,yhm[][10]
*********************/
void SelectionSort(char a[][10])
{
    int mid;
    int tmp;
    for(int i=0;i<=count-3;i++)
    {
        mid=i;
        for(int j=i+1;j<=count-2;j++)
        {
           if(strcmp(a[mid],a[j])>0)
            {
                mid=j;
            }
        }
        if(mid!=i)
        {
            tmp=id[i];
            id[i]=id[mid];
            id[mid]=tmp;
            tmp=earn[i];
            earn[i]=earn[mid];
            earn[mid]=tmp;
            tmp=cost[i];
            cost[i]=cost[mid];
            cost[mid]=tmp;
            strcpy(temp,yhm[mid]);
            strcpy(yhm[mid],yhm[i]);
            strcpy(yhm[i],temp);
        }
    }
}

/**********************
**函数名：BrinarySearch
**输入：a[]
**a[][10]--目标用户名
**功能描述：二分查找
**全局变量：id,earn,cost,yhm[][10]
*********************/
void BrinarySearch(char a[])
{
    int mid;
    int left=0;
    int right=count-2;
    while(left<=right)
    {
        mid=(right-left)/2+left;
        if(strcmp(a,yhm[mid])>0)
        {
            left=mid+1;
        }else if(strcmp(a,yhm[mid])<0)
        {
            right=mid-1;
        }else
        {
            break;
        }
    }
    if(left<=right)
    {
        printf("ID        UserName  Income    Expeses\n");
        printf("%-10d%-10s%-10d%-10d\n",id[mid],yhm[mid],earn[mid],cost[mid]);
    }else
    {
        printf("Not Found\n");
    }
}

/**********************
**函数名：SelectionSort1
**输入：a[]
**a[]--用户id
**功能描述：选择排序
**全局变量：id,earn,cost,yhm[][10]
*********************/
void SelectionSort1(int a[])
{
    int mid;
    int tmp;
    for(int i=0;i<=count-3;i++)
    {
        mid=i;
        for(int j=i+1;j<=count-2;j++)
        {
           if(id[mid]>id[j])
            {
                mid=j;
            }
        }
        if(mid!=i)
        {
            tmp=id[i];
            id[i]=id[mid];
            id[mid]=tmp;
            tmp=earn[i];
            earn[i]=earn[mid];
            earn[mid]=tmp;
            tmp=cost[i];
            cost[i]=cost[mid];
            cost[mid]=tmp;
            strcpy(temp,yhm[mid]);
            strcpy(yhm[mid],yhm[i]);
            strcpy(yhm[i],temp);
        }
    }
}
