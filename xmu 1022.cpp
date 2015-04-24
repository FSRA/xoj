#include<cstdio>
#include<cstring>
int a[101][101],b[101][101],c[101][101];
 
int main()
{
    memset(c,0,sizeof(c));
    int n1,m1,n2,m2,i,j,k;
    scanf("%d %d",&n1,&m1);
    for(i=1;i<=n1;i++)
        for(j=1;j<=m1;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d",&n2,&m2);
    for(i=1;i<=n2;i++)
        for(j=1;j<=m2;j++)
            scanf("%d",&b[i][j]);
    for(i=1;i<=n1;i++)
        for(j=1;j<=m2;j++)
            for(k=1;k<=m1;k++)
                c[i][j]+=a[i][k]*b[k][j];
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<m2;j++)
            printf("%d ",c[i][j]);
        printf("%d",c[i][m2]);
        if(i!=n1)
            printf("\n");
    }
 
 
}
