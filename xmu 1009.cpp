#include<cstdio>
#include<cmath>
int a[9][512];

bool sushu(int t){
	bool flag=false;
	for(int i=2;i<=sqrt(t);i++)
	{
		if(t%i==0)
		{
			flag=true;
			break;
		}
	}
	return !flag;
}

int main()
{
	int n,t=2,i,j;
	scanf("%d",&n);
	a[1][0]=4;
	a[1][1]=2;
	a[1][2]=3;
	a[1][3]=5;
	a[1][4]=7;
	while(t<=n)
	{
		i=1;
		j=1;
		while(j<=a[t-1][0])
		{
			if(sushu(a[t-1][j]*10+1))
				a[t][i++]=a[t-1][j]*10+1;
			if(sushu(a[t-1][j]*10+3))
				a[t][i++]=a[t-1][j]*10+3;
			if(sushu(a[t-1][j]*10+7))
				a[t][i++]=a[t-1][j]*10+7;
			if(sushu(a[t-1][j]*10+9))
				a[t][i++]=a[t-1][j]*10+9;
			j++	;
		}
		a[t][0]=i-1;
		t++;
	}
	for(i=1;i<=a[n][0];i++)
		printf("%d\n",a[n][i]);	
}
