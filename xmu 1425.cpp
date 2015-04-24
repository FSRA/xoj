#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string a;
	int n,pos;
	char c;
	char aa[1005];
	scanf("%s",aa);
	a=aa;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",aa);
		if(aa[0]=='d')
		{
			scanf("%d",&pos);
			a.erase(a.begin()+pos-1);
//			cout<<a<<endl;
		}
		if(aa[0]=='a')
		{
			scanf("%d %c",&pos,&c);
			a.insert(a.begin()+pos-1,c);
//			cout<<a<<endl;
		}
	}
	cout<<a<<endl;
}
