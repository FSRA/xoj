#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,a[35];
	scanf("%d",&n);
	for(int i=0;i<=4;i++)
		a[i]=i;
	for(int i=5;i<=n;i++)
	{
		a[i]=max(2*a[i-2],3*a[i-3]);
//		a[i]=max(a[i],4*a[i-4]);
	}
	printf("%d\n",a[n]);
	return 0;
}
