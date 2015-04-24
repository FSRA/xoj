#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100000

bool flag[maxn];
int su[10000];

void sushu()
{
	memset(flag,0,sizeof(flag));
	for(int i=2;i<sqrt(maxn);i++)
	{
		if(!flag[i])
		{
			for(int j=i*i;j<=maxn;j+=i)
				flag[j]=true;
		}
	}
	int j=0;
	for(int i=2;i<maxn;i++)
	{
		if(!flag[i])
			su[j++]=i;
	}
//	printf("%d\n",j);
}

int main()
{
	sushu();
	int t,n,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i=0,cnt=0;
		while(su[i]<=sqrt(n))
		{
			if(n%su[i]==0)
			{
				cnt++;
				while(n%su[i]==0)
					n/=su[i];
			}
			i++;
		}
		if(n!=1)
			cnt++;
		res=pow(2,cnt);
		printf("%d\n",res);
	}
}
