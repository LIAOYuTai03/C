#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int m,i,j,flag,x,sum,flag1;
    int inum[999];
    int inumble;
    scanf("%d",&m);
    flag=1;
    i=0;
    if(m<=0||m>=10){
        flag=0;
    }

    while(i<m&&flag==1){
        i++;
        j=0;
        sum=0;
        scanf("%d",&inumble);

        if(inumble>=1000||inumble<=0){
            break;
        }

        while(j<inumble){
            scanf("%d",&inum[j]);
            j++;
        }

        for(j=0;j<inumble;j++){
            flag1=1;
            if(inum[j]<=1){
                continue;
            }
            for(x=2;x<=sqrt(inum[j]);x++){
                if(inum[j]%x==0){
                    break;
                }
            }if(x==(int)sqrt(inum[j])+1){
            sum+=inum[j];
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
