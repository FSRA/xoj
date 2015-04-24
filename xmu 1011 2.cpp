#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int ans[100005],flag[100005];

int main()
{
	memset(flag,0,sizeof(flag));
	int n,d,num=1,len;
	scanf("%d %d",&n,&d);
	len=int(log(n/d)/log(10)+2.000001);
	printf("%d.",n/d);
	while(!flag[n]&&n)
	{
		flag[n]=num;
		n*=10;
		ans[num++]=n/d;
		n=n%d;
	}
	if(num==1)
	{
		printf("0\n");
		return 0;	
	}
	for(int i=1;i<num;i++)
	{
		if(flag[n]==i)
		{
			printf("(");
			len++;
		}
		if(len%76==0)
			printf("\n");
		printf("%d",ans[i]);
		len++;
	}
	if(n)
		printf(")");
	printf("\n");
	return 0;
	
}
