/*******************
**文件名：roll
**创建人：廖雨泰
**日期：11.5
**修改人：廖雨泰
**日期：11.6
********************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row,column;
    int *p;
    scanf("%d %d",&row,&column);
    p=(int*)malloc(row*column*sizeof(int));
    int i=0;
    int j=0;

    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",p+i*column+j);
        }
    }

    for(j=0;j<column;j++)
    {
        for(i=0;i<row;i++)
        {
            printf("%-3d",*(p+i*column+j));
            if(i==row-1)
            {
                printf("\n");
            }
        }
    }
    return 0;
}
