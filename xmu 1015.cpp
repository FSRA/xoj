#include<cstdio>

int main()
{
	char c;
	bool flag=true;
	while(scanf("%c",&c)!=EOF)
	{
		if(flag)
		{
			if(c>='A'&&c<='Z')
			{
				flag=false;
				printf("%c",c);
			}
			else
				printf("%c",c);
		}
		else
		{
			if(c=='!'||c=='.'||c=='?')
			{
				flag=true;
				printf("%c",c);
			}
			else
			{
				if(c>='A'&&c<='Z')
					printf("%c",c-'A'+'a');
				else
					printf("%c",c);
			}
		}
	}
	return 0;
}
