#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct pos{
	int x;
	int y;
};

bool cmp(pos a1,pos a2)
{
	if(a1.y==a2.y)
		return a1.x>a2.x;
	else
		return a1.y<a2.y;
}

pos a[2005];
bool flag[2005];

int main()
{
	int n,cnt=0;
	bool flag1=true;
	scanf("%d",&n);
	a[n+1].x=0;
	a[n+1].y=0;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",a[i].x,a[i].y);
	}
	while(cnt!=n)
	{
		flag1=true;
		for(int i=1;i<=n;i++)
		{
			if(flag1&&!flag[i])
			{
				printf("%d %d ",a[i].x,a[i].y);
				flag1=false;
				flag[i]=true;
				cnt++;
			}
			if(a[i].y!=a[i+1].y)
				flag1=true;
		}
		printf("\n");
	}
}
