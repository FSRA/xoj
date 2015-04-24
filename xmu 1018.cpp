#include<cstdio>



int main()
{

	int m,n,t,fib0,fib1,temp;
	scanf("%d",&t);
	while(t--)
	{
		fib0=0;
		fib1=1;
		scanf("%d %d",&n,&m);
		for(int i=2;i<=n;i++)
		{
			temp=fib0;
			fib0=fib1;
			fib1=(fib0+temp)%m;
		}
		printf("%d\n",fib1);
	}
	return 0;
}
