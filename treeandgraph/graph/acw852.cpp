#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
const int N = 1e5+10;
int n,m;
int h[N],e[N*2],ne[N*2],w[N*2],idx;
int cnt[N],dist[N];
bool st[N];
void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfaFh()
{
    memset(dist,0x3f,sizeof(dist));
    queue<int> q;
    //全部都入队是怕负环和起始点不连通
    for(int i=1;i<=n;i++)
    {
        st[i]=true;
        q.push(i);
    }

    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j] = dist[t]+w[i];
                cnt[j]=cnt[t]+1;//cnt[j]是到j点所要经过的点数，t是到j点所要经过的点数

                if(cnt[j]>=n) return true;
                if(!st[j])
                {
                    st[j] = false;
                    q.push(j);
                }
            }
        }
    }
    return false;
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
    if(spfaFh()) cout<<"Yes";
    else cout<<"No";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}