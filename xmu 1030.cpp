#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[1005][1005];

int main()
{
	for(int i=0;i<=1005;i++)
		dp[i][0]=0;
	for(int i=0;i<=1005;i++)
		dp[0][i]=0;
		

	int n,m;
	scanf("%d %d\n",&n,&m);
//	getchar();
	char a[1005],b[1005];
//	scanf("%s",a);
//	getchar();
//	scanf("%s",b);
	for(int i=1;i<=n;i++)
		scanf("%c",&a[i]);
	getchar();
	for(int i=1;i<=m;i++)
		scanf("%c",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	printf("%d",dp[n][m]);

}
