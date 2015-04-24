#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct pos{
	int x;
	int y;
};

bool cmp(pos a1,pos a2){
	if(a1.y==a2.y)
		return a1.x>a2.x;
	else
		return a1.y<a2.y;
}

vector<pos> a;

int main()
{
	int n;
	pos a1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a1.x,&a1.y);
		a.push_back(a1);
	}
	sort(a.begin(),a.end(),cmp);
	vector<pos>::iterator it;
	bool flag=true,flag1=false;
	while(!a.empty())
	{
		flag=true;
		flag1=false;
		for(it=a.begin();it!=a.end();it++)
		{
			if(flag)
			{
				printf("%d %d ",(*it).x,(*it).y);
				flag=false;
				flag1=true;
			}
			if((it+1)!=a.end()&&(*it).y!=(*(it+1)).y)
			{
				flag=true;
			}
			if(flag1)
			{
				a.erase(it);
				flag1=false;
			}
		}
		printf("\n");
	}
}
