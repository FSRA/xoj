#include<cstdio>
#include<algorithm>
using namespace std;

int a[1000005];

void sort2(int low,int high)
{
	if(low>=high)
		return;
	int mid=(low+high)/2;
	swap(a[low],a[mid]);
	int key=a[low],low1=low,high1=high;
	while(low<high)
	{
		while(low<high&&a[high]>=key)
			high--;
		a[low]=a[high];
		while(low<high&&a[low]<=key)
			low++;
		a[high]=a[low];
	}
	a[low]=key;
	sort2(low1,low-1);
	sort2(low+1,high1);
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort2(0,n-1);
	for(int i=0;i<n-1;i++)
		printf("%d ",a[i]);
	printf("%d",a[n-1]);
}
