#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
const int N = 505;
int g[N][N],dist[N];
bool st[N];

int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    for(int i=1;i<=n-1;i++)
    {
        int t = -1;//最小距离的坐标初始化
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j])) t = j;
        }

        for(int j=1;j<=n;j++)
        {
            dist[j] = min(dist[j],g[t][j]+dist[t]);
        }
        st[t] = true;
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y] = min(g[x][y],z);
    }
    cout<<dijkstra()<<endl;
    return 0;
}