#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
//拓扑序列，任意一个有向边u->v，顶点u都在顶点v的前面

int n,m;
const int N = 1e5+10,M = N*2;
int h[N],e[M],ne[M],idx;
int q[N],d[N];//d[N]记录每个点的入度

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool topsort()
{
    int hh = 0 , tt = -1;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0) //每个入度为0的点均可以作为起始的点，他们是并列输出的，不具备先后关系
        {
            q[++tt] = i;
        }
    }

    while(hh<=tt)
    {
        int t = q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int m = e[i];
            d[m]--;  //入度要减一
            if(d[m]==0)
            {
                q[++tt] = m;
            }
        }
    }
    return tt==n-1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topsort()==true)
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<' ';
        }
    }

    else cout<<"-1"<<endl;
    return 0;
}