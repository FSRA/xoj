#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int a[105][105];

struct poi
{
	int v;
	int w;
};

struct cmp
{
	bool operator()(poi a1,poi a2)
	{
		return a1.w>a2.w;
	}
};

int prim(int n)
{
	bool flag[105];
	memset(flag,0,sizeof(flag));
	priority_queue<poi,vector<poi>,cmp> pq;
	flag[1]=true;
	poi p;
	for(int i=2;i<=n;i++)
	{
		p.v=i;
		p.w=a[1][i];
		pq.push(p);
	}
	int num=1,sum=0,temp;
	while(num<n)
	{
		if(!pq.top().v)
		{
			sum+=pq.top().w;
			temp=pq.top().v;
			flag[temp]=true;
			pq.pop();
			for(int i=1;i<=n;i++)
			{
				if(!flag[i]&&i!=temp)
				{
					p.v=i;
					p.w=a[temp][i];
					pq.push(p);
				}
			}
			num++;
		}
		else
			pq.pop();
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int sum=prim(n);
	printf("%d\n",sum);
}
