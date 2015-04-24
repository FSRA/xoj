#include<cstdio>
#include<cmath>
#include<cstring>

bool flag1[1500000];
bool flag2[1500000];

int main()
{
	long long t,a,b,ans=1,j;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		for(long long i=0 ;i*i<=b ;i++)
			flag1[i]=false ;
        for(long long i=0 ;i<=b-a ;i++)
			flag2[i]=false ;
		for(long long  i=2;i*i<=b;i++)
		{
			if(!flag1[i])
			{
				for(j=2*i;j*j<=b;j+=i)
					flag1[j]=true;
				if((a+i-1)/i==1)
					j=2*i;
				else
					j=(a+i-1)/i*i;
				for(;j<=b;j+=i)
					flag2[j-a]=true;
			}
		}
		int ans=0;
		for(long long i=0;i<=b-a;i++)
			if(!flag2[i])
				ans++;
		if(a==1)
			ans--;
		printf("%d\n",ans);
			
	}
}
