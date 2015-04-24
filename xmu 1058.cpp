#include<cstdio>

int main()
{
	int x1,y1,w1,h1,x2,y2,w2,h2;
	scanf("%d %d %d %d",&x1,&y1,&w1,&h1);
	scanf("%d %d %d %d",&x2,&y2,&w2,&h2);
	if(x1+w1>x2&&x2+w1>x1&&y1+h1>y2&&y2+h2>y1)
		printf("Yes\n");
	else
		printf("No\n");
}
