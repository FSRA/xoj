#include<cstdio>
#define INF 1<<30-2

int a[205];
long long dp[205][205];

long long dpmatrix(int n)
{
	long long q;
	for(int c=2;c<=n;c++)
		for(int i=1;i<=n-c+1;i++)
		{
			int j=i+c-1;
			for(int k=i;k<=j-1;k++)
			{
				q=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
				if(q<dp[i][j])
					dp[i][j]=q;
			}
		}
	return dp[1][n];
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<205;i++)
		for(int j=0;j<205;j++)
			dp[i][j]=INF;
	for(int i=0;i<205;i++)
		dp[i][i]=0;
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	long long time;
	time=dpmatrix(n);
	printf("%lld",time);
}
