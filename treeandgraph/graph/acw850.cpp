#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> PII;

int n,m;
const int N = 2e5,M = N*2;
int h[N],e[M],ne[M],idx,w[M];
int dist[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;

    heap.push({0,1});//距离，编号
    while(heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver];i!=-1;i=ne[i])
        {
            int j = e[i];
            //w[i]是ver到i为idx的编号顶点也就是j的距离
            if(dist[j]>dist[ver]+w[i]) 
            {
                dist[j] = dist[ver]+w[i];
                heap.push({dist[j],j});
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    cout<<dijkstra()<<endl;
    return 0 ;
}