#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 100000

struct pos{
	int v;
	int w;
};

vector<pos> a[100005];

int dis[100005];
bool flag[100005];
int m,n;

void dij(int v0)
{
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++)
		dis[i]=maxn;
	for(int i=0;i<a[v0].size();i++)
		dis[a[v0][i].v]=a[v0][i].w;
	dis[v0]=0;
	flag[v0]=true;
	for(int i=2;i<=n;i++)
	{
		int temp=maxn,k;
		for(int j=1;j<=n;j++)
		{
			if(!flag[j]&&dis[j]<temp)
			{
				temp=dis[j];
				k=j;
			}
		}
		flag[k]=true;
		for(int p=0;p<a[k].size();p++)
		{
			int t=dis[k]+a[k][p].w;
			if(!flag[a[k][p].v]&&t<dis[a[k][p].v])
				dis[a[k][p].v]=t;
		}
	}
}

int main()
{
	int v1,v2,w;
	pos temp;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		temp.v=v2;
		temp.w=w;
		a[v1].push_back(temp);
		temp.v=v1;
		a[v2].push_back(temp);
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size();j++)
			printf("%d %d   ",a[i][j].v,a[i][j].w);
		printf("\n");
	}*/
	dij(1);
	printf("%d\n",dis[n]);
	
}
