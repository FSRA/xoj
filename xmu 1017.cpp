#include<cstdio>
#include<algorithm>
using namespace std;

int a[1030][1030],t=0;

void piece(int x0,int y0,int x1,int y1,int size)
{
	int s,flag;
	if(size==1)
	return;
	t++;
	flag=t;
	s=size/2;
	if(x1<x0+s&&y1<y0+s)
		piece(x0,y0,x1,y1,s);
	else{
		a[x0+s-1][y0+s-1]=flag;
		piece(x0,y0,x0+s-1,y0+s-1,s);
	}
	if(x1<x0+s&&y1>=y0+s)
		piece(x0,y0+s,x1,y1,s);
	else{
		a[x0+s-1][y0+s]=flag;
		piece(x0,y0+s,x0+s-1,y0+s,s);
	}
	if(x1>=x0+s&&y1<y0+s)
		piece(x0+s,y0,x1,y1,s);
	else{
		a[x0+s][y0+s-1]=flag;
		piece(x0+s,y0,x0+s,y0+s-1,s);
	}
	if(x1>=x0+s&&y1>=y0+s)
		piece(x0+s,y0+s,x1,y1,s);
	else{
		a[x0+s][y0+s]=flag;
		piece(x0+s,y0+s,x0+s,y0+s,s);
	}
	
}

int main()
{
	int n,x1,y1;
	scanf("%d",&n);
	scanf("%d %d",&x1,&y1);
	a[x1][y1]=0;
	piece(1,1,x1,y1,1<<n);
	for(int i=1;i<=1<<n;i++)
	{
		for(int j=1;j<=1<<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;

//	printf("%d",1<<n);
}
