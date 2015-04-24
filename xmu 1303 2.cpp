#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int t,i,n;
    char num[105];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",num);
        int count0=0,count1=0;
        for(i=0;i<strlen(num)-1;i++)
        {
            if(num[i]!=num[i+1]&&num[i]=='0')
               count0++;
            else if(num[i]!=num[i+1]&&num[i]=='1')
               count1++;
        }
        if(num[strlen(num)-1]=='0')
          count0++;
        else
          count1++;
        if(count0>count1)
           printf("%d\n",count1);
        else
           printf("%d\n",count0);
    }
    return 0;
}
