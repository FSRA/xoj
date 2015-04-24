#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int pre[105];
bool flag[105];

struct pos{
	int v1;
	int v2;
	int d;
};

bool cmp(pos a1,pos a2)
{
	return a1.d<a2.d;
}

int Find(int x)
{
	int r=x;
	while(r!=pre[r])
		r=pre[r];
	int i=x,j;
	while(pre[i]!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

void mix(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)
		pre[fx]=fy;
}

int main()
{
	pos a[5000];
	int n,m,sum,cnt;
	while(scanf("%d",&n)&&n>0)
	{
		for(int i=0;i<105;i++)
			pre[i]=i;
		m=n*(n-1)/2;
		sum=0;
		cnt=0;
		for(int i=1;i<=m;i++)
			scanf("%d %d %d",&a[i].v1,&a[i].v2,&a[i].d);
		sort(a+1,a+m+1,cmp);
//		for(int i=1;i<=m;i++)
//			printf("%d %d %d\n",a[i].v1,a[i].v2,a[i].d);
		for(int i=1;i<=m&&cnt<n;i++)
		{
			if(Find(a[i].v1)!=Find(a[i].v2))
			{
				sum+=a[i].d;
				mix(a[i].v1,a[i].v2);
				cnt++;
			}			
		}
		printf("%d\n",sum);
	}
}
