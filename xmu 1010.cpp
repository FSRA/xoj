#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1005][1005];
int dp[1005][1005];


int main()
{
	memset(dp,0,sizeof(dp));
	int n,res=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
	for(int i=1;i<=n;i++)
		if(res<dp[n][i])
			res=dp[n][i];
	printf("%d",res);
}
