#include<cstdio>
#include<algorithm>
using namespace std;



int  main()
{
	int n,e1,e2,x1,x2;
	int a1[1005],a2[1005],t1[1005],t2[1005];
	int dp1[1005],dp2[1005];
	scanf("%d",&n);
	scanf("%d %d %d %d",&e1,&e2,&x1,&x2);
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&a2[i]);
	for(int i=1;i<=n-1;i++)
		scanf("%d",&t1[i]);
	for(int i=1;i<=n-1;i++)
		scanf("%d",&t2[i]);
	dp1[1]=e1+a1[1];
	dp2[1]=e2+a2[1];
	for(int i=2;i<=n;i++)
	{
		dp1[i]=min(dp1[i-1]+a1[i],dp2[i-1]+t2[i-1]+a1[i]);
		dp2[i]=min(dp2[i-1]+a2[i],dp1[i-1]+t1[i-1]+a2[i]);
	}
	int final;
	final=min(dp1[n]+x1,dp2[n]+x2);
	printf("%d",final);
	return 0;
}
