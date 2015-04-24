#include<cstdio>

int main()
{
	bool flag=true;
	char a1,a2,b1,b2,c1,c2;
	scanf("%c%c:%c%c:%c%c",&a1,&a2,&b1,&b2,&c1,&c2);
	if(a1=='2'&&a2=='4')
	{
		a1-=1;
		a2-=2;
	}
	else if(a1=='0'&&a2=='0')
	{
		a1+=1;
		a2+=2;
	}
	else if(a1=='1'&&a2=='2')
	{
		flag=false;
	}
	else if(a1>='1'&&a2>='2')
	{
		a1-=1;
		a2-=2;
		flag=false;
	}
	else if(a1=='2')
	{
		a1-=2;
		a2+=8;
		flag=false;
	}
	if(flag)
		printf("AM %c%c:%c%c:%c%c\n",a1,a2,b1,b2,c1,c2);
	else
		printf("PM %c%c:%c%c:%c%c\n",a1,a2,b1,b2,c1,c2);
	return 0;
}
