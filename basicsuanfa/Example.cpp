#include<iostream>
using namespace std;
int n;
const int N = 20;
bool col[N],dg[N],rdg[N];//列，对角线，反对角线
char q[N][N];
//以行来进行深搜
//行末不能有多余空格
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<q[i][j];
            }
            puts("");
        }
        puts("");
    }

    for(int i=0;i<n;i++)
    {
        if(col[i]==0&&dg[i-u+n]==0&&rdg[i+u]==0)
        {
            q[u][i]='Q';
            col[i]=dg[i-u+n]=rdg[i+u]=1;
            dfs(u+1);
            col[i]=dg[i-u+n]=rdg[i+u]=0;
            q[u][i]='.';
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