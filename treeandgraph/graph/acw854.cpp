#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int N = 210,INF=1e9;
int n,m,q;
int d[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}

void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
        }
    }

    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
    }

    floyd();

    while(q--)
    {
        int x,y;
        cin>>x>>y;
        //可能存在到达不了负环的情况，但是它实实在在更新了
        if(d[x][y]>INF/2) cout<<"impossible"<<endl;
        else cout<<d[x][y]<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}