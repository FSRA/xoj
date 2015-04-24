#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,b[105],a[105][105];

int maxsum(int b[])
{
	int sum,res,max0=b[1];
	sum=0;
	res=-9999;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		if(sum>res)
			res=sum;
		if(sum<0)
			sum=0;
	}
	return res;
	
}

int main()
{
	int sum,maxsum0;
//	while(scanf("%d",&n)!=EOF)
//	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		maxsum0=a[1][1];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				memset(b,0,sizeof(b));
				for(int p=1;p<=n;p++)
					for(int k=i;k<=j;k++)
						b[p]+=a[k][p];
				sum=maxsum(b);
				if(sum>maxsum0)
					maxsum0=sum;
			}
		printf("%d\n",maxsum0);
//	}
}
