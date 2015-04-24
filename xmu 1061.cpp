#include<cstdio>
#include<algorithm>
using namespace std;

struct time
{
	char name[20];
	int sh;
	int sm;
	int eh;
	int em;
};

bool cmp(time a,time b)
{
	if(a.eh*60+a.em!=b.eh*60+b.em)
		return a.eh*60+a.em<b.eh*60+b.em;
	else
		return a.sh*60+a.sm<b.sh*60+b.sm;
}

int main()
{
	int n;
	time p[1005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s %d:%d %d:%d",p[i].name,&p[i].sh,&p[i].sm,&p[i].eh,&p[i].em);
	sort(p+1,p+n+1,cmp);
//	for(int i=1;i<=n;i++)
//		printf("%s %d:%d %d:%d\n",p[i].name,p[i].sh,p[i].sm,p[i].eh,p[i].em);
	int num=0,flag=-1;
	int a[1005];
	for(int i=1;i<=n;i++)
	{
		if(p[i].sh*60+p[i].sh>=flag)
		{
			a[++num]=i;
			flag=p[i].eh*60+p[i].em;
		}
		
	}
	printf("%d\n",num);
	for(int i=1;i<=num;i++)
		printf("%s ",p[a[i]].name);
}
