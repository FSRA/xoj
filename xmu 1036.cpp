#include<cstdio>

int main()
{
	int n,ans=0,t;
	scanf("%d",&n);
	for(int i=0;i<2*n-1;i++)
	{
		scanf("%d",&t);
		ans^=t;
	}
	printf("%d\n",ans);
}
