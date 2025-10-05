#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

//prim算法求最小生成树
/*
dist[]距离
s 集合，当前已经在连通块里的点？
*/
const int N = 505,INF = 0x3f3f3f3f;
int n,m;
int g[N][N];//邻接矩阵
int dist[N];//每个未加入集合的点到当前连通块的最小距离
bool st[N];//当前每个点的状态

int prim()
{
    int res = 0;
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<n;i++)
    {
        int t = -1;//需要放进去的点t
        for(int j=1;j<=n;j++)
        {
            if(st[j]==false&&(t==-1||dist[t]>dist[j])) t = j;//找到当前距离连通块最近的点
        }
        if(i>0&&dist[t]==INF) return INF;//如果不是第一个点且不连通
        if(i>0) res+=dist[t];//如果不是第一个点且连通（这里是距离连通块最近的点）
        st[t]=true;
        for(int k=1;k<=n;k++) dist[k] = min(dist[k],g[t][k]);//更新距离连通块的距离，g[t][k]代表新的点进去后会有新的连线边
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(w<=g[u][v])
        {
            g[u][v] = w;
            g[v][u] = g[u][v];
        }
    }
    int r = prim();
    if(r==INF) puts("impossible");
    else cout<<r<<endl;
    return 0;
}