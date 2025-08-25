#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
const int N = 1e5+10,M = N*2;
int h[N],e[M],ne[M],idx;
int q[N],d[N];

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int bfs()
{
    //h装的是idx，e装的是编号，ne装的是idx
    memset(d,-1,sizeof(d));
    d[1] = 0;
    int hh = 0,tt=0;
    q[tt++] = 1;
    while(hh<=tt)
    {
        int s = q[hh++];
        for(int i = h[s];i!=-1;i = ne[i])
        {
            int j = e[i];
            if(d[j]==-1)
            {
                q[tt++] = j;
                d[j] = d[s]+1;
            }
        }
    }

    return d[n];
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
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    cout<<bfs()<<endl;
    return 0;
}