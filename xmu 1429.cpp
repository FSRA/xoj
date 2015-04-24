#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int n,x,k,num=0,a[30];
	scanf("%d %d",&n,&x);
	a[0]=1;
	for(int i=1;i<=30;i++)
		a[i]=a[i-1]*x+1;
	while(n)
	{
		for(int i=0;i<=30;i++)
		{
			if(n<a[i])
			{
				n=n-a[i-1];
				num+=pow(x,i-1);
				break;
			}
		}
	}
	printf("%d\n",num);
	
}
