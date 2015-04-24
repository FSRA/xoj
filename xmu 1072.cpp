#include<cstdio>
#include<cmath>
int main()
{
	int n,a[35]={0},res=1;
	scanf("%d",&n);
	a[n]=1;
	while(n>3)
	{
		while(a[n])
		{
			a[n]--;
			a[n/2]++;
			a[(n+1)/2]++;
		}
		n--;
	}
	res=pow(2,a[2])*pow(3,a[3]);
	printf("%d\n",res);
	printf("%d\n",9*9*3*16);
}
