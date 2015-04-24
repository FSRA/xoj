#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000005];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	printf("%d\n",a[k]);
	return 0;
	
}
