#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;

vector <vector <int> > v(100005);

int n,m;

struct pos
{
	int f;
	int v;
	int t;	
};

pos a[200005];
bool flag[100005];

bool cmp(pos b1,pos b2)
{
	return b1.t>b2.t;
}

bool dfs1()
{
	memset(flag,0,sizeof(flag));
	flag[1]=true;
	stack<int> s;
	s.push(1);
	int i,temp;
	flag[1]=true;
	while(!s.empty())
	{
		temp=s.top();
		if(s.top()==n)
			break;
		for(i=0;i<v[temp].size();i++)
		{
			if(!flag[v[temp][i]])
			{
				s.push(v[temp][i]);
				flag[v[temp][i]]=true;
				break;
			}
		}
		if(i==v[temp].size())
			s.pop();
	}
	return !s.empty();
}

bool bfs()
{
	int temp;
	memset(flag,0,sizeof(flag));
	queue<int> q;
	q.push(1);
	flag[1]=true;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		for(int i=0;i<v[temp].size();i++)
		{
			if(!flag[v[temp][i]])
			{
				q.push(v[temp][i]);
				flag[v[temp][i]]=true;
			}
			if(v[temp][i]==n)
				break;
				
		}
		if(q.back()==n)
			break;
	}
	return !q.empty();
}

void dfs()
{
	memset(flag,0,sizeof(flag));
	flag[1]=true;
	stack<int> s;
	s.push(1);
	int i,temp;
	flag[1]=true;
	while(1)
	{
		temp=s.top();
		if(s.top()==n)
			break;
		for(i=0;i<v[temp].size();i++)
		{
			if(!flag[v[temp][i]])
			{
				s.push(v[temp][i]);
				flag[v[temp][i]]=true;
				break;
			}
		}
		if(i==v[temp].size())
			s.pop();
	}
	vector<int> vv;
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		vv.push_back(temp);
	}
	reverse(vv.begin(),vv.end());
	for(i=0;i<vv.size();i++)
		printf("%d ",vv[i]);
}

int main()
{
	int res=-1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a[i].f,&a[i].v,&a[i].t);
	}
	sort(a+1,a+m+1,cmp);
//	for(int i=1;i<=m;i++)
//		printf("%d %d %d\n",a[i].f,a[i].v,a[i].t);
	for(int i=1;i<=m;i++)
	{
		v[a[i].f].push_back(a[i].v);
		v[a[i].v].push_back(a[i].f);
		if(bfs())
		{
			res=a[i].t;
			dfs();
			printf("\n");
			return 0;
		}
	}
	printf("%d\n",res);
	return 0;
}
