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
int mid=0;
int tmp;
char temp[11];
int num=0;

int main()
{
    int input=0;
    int num1=0;
    char target[11];
    int sum1=0,sum2=0,ave1=0,ave2=0;
    int i=0;
    while(1)
    {
        printf("1.Input record\n");
        printf("2.Sort and list records in alphabetical order by user name\n");
        printf("3.Search records by user name\n");
        printf("4.Calculate and list per capita income and expenses\n");
        printf("5.List records which have more expenses than per capita expenses\n");
        printf("6.List all records\n");
        printf("0．Exit\n");
        printf("Please enter your choice:");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                printf("请输入用户人数:");
                scanf("%d",&num1);
                for(int i=num;i<num+num1;i++)
                {
                    scanf("%d",&s[i].id);
                    scanf("%s",s[i].yhm);
                    scanf("%d",&s[i].earn);
                    scanf("%d",&s[i].cost);
                }
                num+=num1;
                break;
            case 2:
                SelectionSort();
                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<num;i++)
                {
                    printf("%-8d%-12s%-8d%-8d\n",s[i].id,s[i].yhm,s[i].earn,s[i].cost);
                }
                break;
            case 3:
                SelectionSort();
                printf("Please input the user name:");
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
                SelectionSort1();
                printf("ID      UserName    income  expenses\n");
                for(int i=0;i<num;i++)
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
