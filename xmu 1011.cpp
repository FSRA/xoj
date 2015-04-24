#include<stdio.h>
#include<math.h>
#include<string.h>
int flag[100002],ans[100010];
int main()
{
    int i,n,d,num,len;
    memset(flag,0,sizeof(flag));
    scanf("%d%d",&n,&d);
    num=1;
    printf("???\n");
    printf("%d.",n/d);
    if(n>d)len=int(log(n/d)/log(10)+2.00001);
    else len=2;
    n=n%d;
    while(!flag[n]&&n)
    {
        flag[n]=num;
        n=n*10;
        ans[num++]=n/d;
        n=n%d;
    }
    if(num==1)printf("0");
    for(i=1;i<num;i++)
    {
        if(flag[n]==i)
        {
            len++;
            printf("(");
        }
        if(len%76==0)
        	printf("\n");
        printf("%d",ans[i]);
        len++;
    }
    if(n)printf(")");
    printf("\n");
    return 0;
}
