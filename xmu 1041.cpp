#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define INF 9999999

struct pos{
	int x;
	int y;
};

bool cmp(pos a1,pos b1){
	if(a1.x==b1.x)
		return a1.y>b1.y;
	else
		return a1.x>b1.x;
}

pos a[1000005];
int dp[1000005];

int main()
{
	int n,maxn=0;
	int low,high,len,mid;
	while(scanf("%d",&n)!=EOF)
	{
		len=1;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d %d",&a[i].x,&a[i].y);
		sort(a+1,a+n+1,cmp);
		dp[0]=-1;
		for(int i=1;i<=n;i++)
		{
			dp[len]=INF;
			low=0;
			high=len;
			while(low<=high)
			{
				mid=(low+high)/2;
				
				if(dp[mid]>a[i].y)
					high=mid-1;
				else if(dp[mid]<a[i].y)
					low=mid+1;
				else
				{
					low=mid;
					break;
				}
			}
			if(low==len) len++;
			dp[low]=a[i].y;
		}
		printf("%d\n",len-1);
		
	}
}
