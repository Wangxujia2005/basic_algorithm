#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int,int> PII;//坐标
const int N = 105;
int n,m;
int g[N][N],d[N][N];//g用来装这个图，d用来装该点到原点的距离

int bfs()
{
    queue<PII> q;
    memset(d,-1,sizeof(d));
    d[0][0] = 0;
    q.push({0,0});
    int dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};

    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x = t.first+dx[i],y = t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1)
            {
                d[x][y] = d[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    
    cout<<bfs()<<endl;

    return 0;
}