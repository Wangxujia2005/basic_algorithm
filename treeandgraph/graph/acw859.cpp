#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge
{
    int a,b,w;
}edges[M];

int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{ 
    sort(edges+1,edges+m+1,[](const Edge &a,const Edge &b){
        return a.w<b.w;
    });
    for(int i=i;i<=n;i++) p[i] = i;
    int res=0,cnt=0;//res是最小生成树总权值，cnt是已选边数
    for(int i=1;i<=m;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a!=b)//为了保证不形成环
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return INF;
    else return res;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i] = {a,b,w};
    }
    int t = kruskal();
    if(t==INF) puts("impossible");
    else cout<<t<<endl;
    return 0;
}

