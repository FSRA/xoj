#include<cstdio> 
#include<vector> 
#include<algorithm> 
#include<stack> 
#include<cstring> 
#include<queue> 
using namespace std; 
    
vector <vector <int> > v(100005); 
    
int n,m; 
int uset[100005];
    
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
  
int fd(int x)
{
    while(uset[x]!=x)
        x=uset[x];
    return x;
}
  
void unions(int x,int y)
{
    uset[x]=min(uset[x],uset[y]);
    uset[y]=min(uset[x],uset[y]);
}
    
int main() 
{ 
    int res=-1; 
    scanf("%d %d",&n,&m); 
    for(int i=0;i<100005;i++)
        uset[i]=i;
    for(int i=1;i<=m;i++) 
    { 
        scanf("%d %d %d",&a[i].f,&a[i].v,&a[i].t); 
    } 
    sort(a+1,a+m+1,cmp); 
//    for(int i=1;i<=m;i++) 
//        printf("%d %d %d\n",a[i].f,a[i].v,a[i].t); 
    for(int i=1;i<=m;i++) 
    { 
        if(fd(a[i].f)!=fd(a[i].v))
            unions(a[i].f,a[i].v);
        v[a[i].f].push_back(a[i].v); 
        v[a[i].v].push_back(a[i].f); 
        if(fd(n)==1) 
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
