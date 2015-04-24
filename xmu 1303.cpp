#include<cstdio>

int main()
{
	int t,n,flag;
	char a[200];
	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		scanf("%d",&n);
		getchar();
		for(int i=1;i<=n;i++)
			scanf("%c",&a[i]);
		if(t)
			getchar();
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
				flag++;
		}
		printf("%d\n",flag/2);
	}
	return 0;
}
