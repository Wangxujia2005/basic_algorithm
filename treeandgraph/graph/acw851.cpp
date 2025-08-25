//spfa算法
/*
先初始化dist数组为INF，dist[1] = 0。
从第一个点开始，将其加入队列
循环操作：
    如果队列不为空，则取出队首元素u。
    松弛操作，如果dist[u]+w(u,v) < dist[v]，则更新dist[v] = dist[u] + w(u,v)，并将v加入队列。
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int n,m;
int dist[N],h[N],e[N*2],ne[N*2],w[N*2];
int idx;
bool st[N];

//插入一个a到b的边，h[a]为a的链表头
void add(int a,int b,int c)
{
    e[idx] = b,ne[idx] = h[a],w[idx]=c,h[a] = idx++;
}

int spfa()
{
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j] = dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return dist[n];
}

void solve()
{
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    int t = spfa();
    if(t==0x3f3f3f3f) cout<<"impossible"<<endl;
    else cout<<t<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}