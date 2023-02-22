/*******************
**文件名：keepaccounts3.0
**创建人：廖雨泰
**日期：11.17
**修改人：廖雨泰
**日期：11.17
********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account
{
    int id;
    char yhm[11];
    int earn;
    int cost;
}ACCOUNT;

void SelectionSort(void);
void SelectionSort1(void);

ACCOUNT s[10];
ACCOUNT v[10];
int mid=0;
int tmp;
char temp[11];
int num=0;

int main()
{
    int input=0;
    int num1=0;
    char target[11]={};
    int sum1=0,sum2=0,ave1=0,ave2=0;
    int i=0;
    char c=0;
    char target1[10]={};
    char target2[10]={};
    FILE *fp=NULL;
    FILE *fp1=NULL;
    int w=0;
    int x=0;

    while(1)
    {
        printf("1.Input record\n");
        printf("2.Sort and list records in alphabetical order by user name\n");
        printf("3.Search records by user name\n");
        printf("4.Calculate and list per capita income and expenses\n");
        printf("5.List records which have more expenses than per capita expenses\n");
        printf("6.List all records\n");
        printf("7.write to file\n");
        printf("8.Read from file\n");
        printf("0．Exit\n");
        printf("Please enter your choice:");

        scanf("%d",&input);

        switch (input)
        {
            case 1:

                printf("请输入用户人数:");
                scanf("%d",&num1);
                while(num+num1>10||num+num1<=0)
                {
                    printf("人数异常，请重新输入");
                    scanf("%d",&num1);
                }

                for(int i=num;i<num+num1;i++)
                {
                    scanf("%d",&s[i].id);
                    while(s[i].id<10000||s[i].id>99999)
                    {
                        printf("id异常，请重新输入");
                        scanf("%d",&s[i].id);
                    }

                    memset(s[i].yhm,0,sizeof(s[i].yhm));
                    scanf("%s",s[i].yhm);
                    while(s[i].yhm[10]!='\0')
                    {
                        printf("用户名过长，请重新输入");
                        memset(s[i].yhm,0,sizeof(s[i].yhm));
                        scanf("%s",s[i].yhm);
                    }

                    scanf("%d",&s[i].earn);
                    while(s[i].earn<0)
                    {
                        printf("输入异常，请重新输入");
                        scanf("%d",&s[i].earn);
                    }

                    scanf("%d",&s[i].cost);
                    while(s[i].cost<0)
                    {
                        printf("输入异常，请重新输入");
                        scanf("%d",&s[i].cost);
                    }

                }
                num+=num1;
                break;
            case 2:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                SelectionSort();
                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<num;i++)
                {
                    printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                }
                break;
            case 3:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                SelectionSort();
                printf("Please input the user name:");
                memset(target,0,sizeof(target));
                scanf("%s",target);

                for(i=0;i<num;i++)
                {
                    if(strcmp(s[i].yhm,target)==0)
                    {
                        printf("ID      UserName    income  expenses\n");
                        printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                        break;
                    }
                }

                if(i==num)
                {
                    printf("Not Found\n");
                }
                break;
            case 4:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                for(int i=0;i<num;i++)
                {
                    sum1+=s[i].earn;
                    sum2+=s[i].cost;
                }

                ave1=sum1/num;
                ave2=sum2/num;
                printf("Per capita income:  %d\n",ave1);
                printf("Per capita expenses:%d\n",ave2);
                break;
            case 5:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<num;i++)
                {
                    if(s[i].cost>ave2)
                    {
                        printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                    }
                }
                break;
            case 6:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                SelectionSort1();
                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<num;i++)
                {
                    printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                }
                break;
            case 7:
                if(num==0)
                {
                    printf("无数据");
                    break;
                }
                getchar();
                w=0;
                printf("please input the file name:");

                while((c=getchar())!='\n')
                {
                    target2[w]=c;
                    w++;
                }

                if((fp=fopen(target2,"w"))==NULL)
                {
                    printf("Cannot find this file！\n");
                    break;
                }

                for(int i=0;i<num;i++)
                {
                    fprintf(fp,"%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                }

                fclose(fp);
                printf("Save Successfule\n");
                break;
            case 8:
                x=0;
                int j=0;
                printf("please input the file name:");
                getchar();

                while((c=getchar())!='\n')
                {
                    target1[x]=c;
                    x++;
                }

                if((fp1=fopen(target1,"r"))==NULL)
                {
                    printf("Cannot find this file！\n");
                    break;
                }

                while(fscanf(fp1,"%d",&v[j].id)!=EOF)
                {
                    fscanf(fp1,"%s",v[j].yhm);
                    fscanf(fp1,"%d",&v[j].earn);
                    fscanf(fp1,"%d",&v[j].cost);
                    j++;
                }

                if(j==0)
                {
                    printf("请先执行操作7");
                    break;
                }

                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<j;i++)
                {
                    printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                }
                break;
            case 0:
                printf("退出程序\n");
                exit(0);
            default:
                printf("请输入正确的选项\n");
        }
    }
    return 0;
}

/**********************
**函数名：SelectionSort
**输入：无
**功能描述：按用户名升序选择排序
**全局变量：s[j].id,s[j].earn,s[j].cost,s[j].yhm
*********************/
void SelectionSort(void)
{
    for(int i=0;i<num-1;i++)
    {
        mid=i;
        for(int j=i+1;j<num;j++)
        {
            if(strcmp(s[j].yhm,s[mid].yhm)<0)
            {
                mid=j;
            }
        }
        if(i!=mid)
        {
            tmp=s[i].id;
            s[i].id=s[mid].id;
            s[mid].id=tmp;
            tmp=s[i].earn;
            s[i].earn=s[mid].earn;
            s[mid].earn=tmp;
            tmp=s[i].cost;
            s[i].cost=s[mid].cost;
            s[mid].cost=tmp;
            strcpy(temp,s[i].yhm);
            strcpy(s[i].yhm,s[mid].yhm);
            strcpy(s[mid].yhm,temp);
        }
    }
}

/**********************
**函数名：SelectionSort1
**输入：无
**功能描述：按id升序选择排序
**全局变量：s[j].id,a[j].earn,a[j].cost,s[j].yhm
*********************/
void SelectionSort1(void)
{
    for(int i=0;i<num-1;i++)
    {
        mid=i;
        for(int j=i+1;j<num;j++)
        {
            if(s[j].id<s[mid].id)
            {
                mid=j;
            }
        }
        if(i!=mid)
        {
            tmp=s[i].id;
            s[i].id=s[mid].id;
            s[mid].id=tmp;
            tmp=s[i].earn;
            s[i].earn=s[mid].earn;
            s[mid].earn=tmp;
            tmp=s[i].cost;
            s[i].cost=s[mid].cost;
            s[mid].cost=tmp;
            strcpy(temp,s[i].yhm);
            strcpy(s[i].yhm,s[mid].yhm);
            strcpy(s[mid].yhm,temp);
        }
    }
}
