#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100005
int tree[maxn*4];

void build(int start,int low,int high)
{
	if(low==high)
	{
		scanf("%d",&tree[start]);
		return ;
	}
	else
	{
		int  mid=(high+low)/2;
		build(start*2,low,mid);
		build(start*2+1,mid+1,high);
		tree[start]=max(tree[2*start],tree[2*start+1]);
	}
}


int query(int start,int a,int b,int low,int high,int ans)
{
	if(a<=low&&b>=high)
		return tree[start];
	else
	{
		int mid=(low+high)/2;
		if(a<=mid)
			ans=query(2*start,a,b,low,mid,ans);
		if(b>mid)
			ans=max(query(2*start+1,a,b,mid+1,high,ans),ans);
	}
	return ans;
		
}

int main()
{
	int n,q,a,b;
	scanf("%d %d",&n,&q);
	build(1,1,n);
	while(q--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",query(1,a,b,1,n,-maxn));
	}
	return 0;
}
