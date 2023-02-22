#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ichicken,ihen,icock;
    int money,num;
    for(icock=0;icock<20;icock++){
        money=100-icock*5;
        num=100-icock;

        for(ichicken=0;ichicken*3<=num&&ichicken<=money;ichicken++){
            if(((num-ichicken*3)*3+ichicken)==money){
                    ihen=num-ichicken*3;
                printf("公鸡：%d只,母鸡：%d只,小鸡：%d只\n",icock,ihen,ichicken*3);
            }
        }
    return 0;
}
