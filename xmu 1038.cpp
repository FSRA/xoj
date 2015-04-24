#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[25][2005];

int close(int b1[],int b2[],int t,int m)
{
	int i,j=0,temp,clo=1<<15;
	int sum[2005];
	memset(sum,0,sizeof(sum));
	for( i=1;i<=m;i++)
	{
		sum[i]=sum[i-1]+b2[i]-b1[i];
//		printf("%d ",sum[i]);
	}
	for(i=1;i<=m;i++)
	{
		if(sum[i]<t)
		{
			if(t-sum[i]<=abs(t-clo))
				clo=sum[i];
		}
		else{
			while(j<i)
			{
				temp=sum[i]-sum[j];
				if(temp<t)
				{
					if(t-temp<=abs(t-clo))
						clo=temp;
					break;
				}
				else{
					if(abs(t-temp)<abs(t-clo))
						clo=temp;
					j++;
				}
			}
		}
	}
	return clo;
		
		
}

int main()
{
	int m,n,t,cnt=0;
	while(scanf("%d %d %d",&n,&m,&t)!=EOF)
	{
		for(int i=0;i<2005;i++)
			a[0][i]=0;
		cnt++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				a[i][j]+=a[i-1][j];
			}
		int clo,cloest=1<<15;
//		printf("%d\n",cloest);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				clo=close(a[i],a[j],t,m);
				if(abs(clo-t)<abs(cloest-t)||(abs(clo-t)==abs(cloest-t)&&clo<cloest))
					cloest=clo;
			}
		printf("Case %d:\n%d\n",cnt,cloest);
	}
	return 0;
}
