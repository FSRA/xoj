#include<stdio.h>
#include<stdlib.h>
#define max 1000000000
int d[105][105];
int main()
{
	int i,j,k,n,maxn=0;
	scanf("%d",&n);
	 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			d[i][j]=max;
	 
	for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&d[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(d[i][j]==0)
				d[i][j]=max;
		}
	 
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
					d[i][j]=d[i][k]+d[k][j];
			}
	 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(maxn<d[i][j])
				maxn=d[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	if(maxn>10000)
		printf("-1\n");
	else
		printf("%d\n",maxn);
	return 0;
}
