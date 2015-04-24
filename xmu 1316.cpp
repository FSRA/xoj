#include<cstdio>
#include<algorithm>
using namespace std;

struct goods{
	int v;
	int w;
	double aver;
};

bool cmp(goods a1,goods a2){
	return a1.aver>a2.aver;
}

goods a[100005];

int main()
{
	int m,n;
	double res=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].w,&a[i].v);
		a[i].aver=1.0*a[i].v/a[i].w;
	}
	sort(a+1,a+n+1,cmp);
	int i=1;
	while(m)
	{
		if(m>a[i].w)
		{
			m-=a[i].w;
			res+=a[i].v;
			i++;
		}
		else{
			res+=m*a[i].aver;
			break;
		}
	}
	printf("%.6lf",res);
}
