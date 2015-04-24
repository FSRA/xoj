#include<cstdio>
#include<cmath>

bool sushu(long long t){
	bool flag=false;
	for(long long i=2;i<=sqrt(t);i++)
	{
		if(t%i==0)
		{
			flag=true;
			break;
		}
	}
	return !flag;
}

int main()
{
	int t;
	long long a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&a);
		if(sushu(a))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
