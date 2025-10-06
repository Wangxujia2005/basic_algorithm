#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

//染色法二分图
/*
把所有的点分为两边 A集合和B集合
集合内部没有边

二分图当且仅当图中不含奇数环，奇数环就是边数是奇数的环
相邻的只能是不同颜色的点
*/

const int N = 1e5+6,M = 2e5+6;
int h[N],e[M],ne[M],idx=0;
int n,m;
int color[N];

void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u,int c)
{
    color[u] = c;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j = e[i];
        //如果没染色
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        //如果染色了
        else
        {
            if(color[j]==c) return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    bool flag = true;
    //保证非连通图也能遍历到每个点
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                flag = false;
                break;
            }
        }
    }

    if(flag) puts("Yes");
    else puts("No");
    return 0;
} 