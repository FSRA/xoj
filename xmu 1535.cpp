#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int a[105][105];
bool flag[105];
int dis[105];
int n;


int bfs(int x)
{
	queue<int> q;
	memset(flag,0,sizeof(flag));
	memset(dis,0,sizeof(dis));
	q.push(x);
	flag[x]=true;
	int t=x;
	while(!q.empty())
	{
		x=q.back();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(a[x][i]&&!flag[i])
			{
				q.push(i);
				flag[i]=true;
				dis[i]=dis[x]+1;
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]>maxn)
			maxn=i;
		if(i!=t&&dis[i]==0)
		{
			maxn=0;
			break;
		}
	}
	return maxn;
}

int main()
{
	int dis0=0,x1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	x1=bfs(1);
	if(x1==0)
	{
		printf("-1\n");
		return 0;
	}
	dis0=dis[x1];
	for(int i=2;i<=n;i++)
	{
		x1=bfs(i);
		dis0=max(dis0,dis[x1]);
	}
	printf("%d\n",dis0);
/*	int x1=bfs(1),x2;
	int dis1=dis[x1],dis2;
	if(x1==0)
	{
		printf("-1\n");
		return 0;
	}
	x2=bfs(x1);
	dis2=dis[x2];
	printf("%d\n",dis2);
	return 0;*/
}
