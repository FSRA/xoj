#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,a[1005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d",a[n]);
}
