#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
typedef long long ll ; 
bool prime[1500000] ;
bool prime1[1500000] ;
int main()
{
    int t ;
    scanf("%d",&t) ;
    while(t--)
    {
        ll a,b ;
        scanf("%lld%lld",&a,&b) ;
        for(ll i=0 ;i*i<=b ;i++)prime[i]=true ;
        for(ll i=0 ;i<=b-a ;i++)prime1[i]=true ;
        for(ll i=2 ;i*i<=b ;i++)
        {
            if(prime[i])
            {
                for(ll j=2*i ;j*j<=b ;j+=i)prime[j]=false ;
                for(ll j=max(2LL,(a+i-1)/i)*i ;j<=b ;j+=i)prime1[j-a]=false ;
            }
        }
        int ans=0 ;
        for(ll i=0 ;i<=b-a ;i++)
            if(prime1[i])ans++ ;
        if(a==1)ans-- ;
        printf("%d\n",ans) ;
    }
    return 0 ;
}
