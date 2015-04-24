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
		return a1.x<a2.x;
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
//	for(int i=1;i<=n;i++)
//		printf("%d %d\n",a[i].x,a[i].y);
	while(cnt!=n)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			flag1=true;
			if(!flag[i])
			{
				for(int j=i+1;j<=n;j++)
					if(!flag[j]&&a[j].x>=a[i].x)
					{
						flag1=false;
						break;
					}
				if(flag1)
				{
					if(t==0)
					{
						printf("%d %d",a[i].x,a[i].y);
						t++;
					}
					else
						printf(" %d %d",a[i].x,a[i].y);
					flag[i]=true;
					cnt++;
				}
			}
		}
		printf("\n");
	}
}
