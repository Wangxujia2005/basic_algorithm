#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,k;
const int N = 510,M = 10010;

struct edge
{
    int u,v,w;
}edges[M];

int dist[N];
int backup[N];

void bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    for(int i=1;i<=k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=1;j<=m;j++)
        {
            auto e = edges[j];
            dist[e.v] = min(dist[e.v],backup[e.u]+e.w);
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges[i] = {a,b,c};
    }

    bellman_ford();
    if(dist[n]>0x3f3f3f3f/2) puts("impossible");
    else cout<<dist[n]<<endl;
    return 0;
}