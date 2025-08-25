#include<iostream>
using namespace std;
const int N = 20;
//col是第n行是否存在皇后
//dg是正对角线，rdg是反对角线
//y=-x+b       y=x+b
//b=x+y        b=y-x由于这里会出现负数，所以采取+n的操作
//所以为什么N要定为20
int n,col[N],dg[N],rdg[N];
char q[N][N];
//u是行，i是列
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",q[i][j]);
            }
            puts("");
        }

        puts("");
    }

    for(int i=0;i<n;i++)
    {
        if(!col[i]&&!dg[u+i]&&!rdg[i-u+n])
        {
            /*
            恢复现场
            */
            q[u][i] = 'Q';
            col[i] = dg[u+i] = rdg[i-u+n] = true;
            dfs(u+1);
            col[i] = dg[u+i] = rdg[i-u+n] = false;
            q[u][i] = '.';
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            q[i][j] = '.';
    dfs(0);
    return 0;
}