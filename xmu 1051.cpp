#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 1000005
bool aa[maxn];
int a[100005],b[100005];

int sushu()
{
	memset(aa,0,sizeof(aa));
	int cnt=1;
	for(int i=2;i<sqrt(maxn);i++)
	{
		for(int j=i*i;j<maxn;j+=i)
			aa[j]=true;
	}
	for(int i=2;i<maxn;i++)
		if(!aa[i])
			a[cnt++]=i;
	return cnt;
}

int main()
{
	int cnt=0;
	int n;
	sushu();
//	printf("%d\n",a[2]);
	while(scanf("%d",&n)&&n>0)
	{
		cnt++;
		memset(b,0,sizeof(b));
		int i=1,j,t;
		while(a[i]<=n)
		{
			t=n;
			while(t>=a[i])
			{
				b[i]+=t/a[i];
				t=t/a[i];
			}
			i++;
		}
		printf("Case %d:\n",cnt);
		i=1;
		while(b[i])
		{
			printf("%d",a[i]);
			if(b[i]!=1)
				printf("^%d",b[i]);
			if(b[i+1])
				printf("*");
			i++;
		}
		printf("\n");
	}
	return 0;
}
