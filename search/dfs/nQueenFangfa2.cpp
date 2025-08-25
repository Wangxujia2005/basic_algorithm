#include<iostream>
using namespace std;
const int N = 20;
int n;
char q[N][N];//皇后数组
//行,列,正对角线,反对角线
bool row[N],col[N],dg[N],rdg[N];

void dfs(int x,int y,int s) //x行y列，，s是已经放的皇后个数
{
    if(s>n) return;
    if(y==n) y=0,x++;//下一行，第一列
    if(x==n)
    {
        if(s==n)
        {
            for(int i=0;i<n;i++) puts(q[i]);
            puts("");
        }
        return;
    }

    //当前不放皇后,处理下一列
    q[x][y] = '.';
    dfs(x,y+1,s);
    
    //当前要放皇后
    if(!row[x]&&!col[y]&&!dg[x+y]&&!rdg[x-y+n])
    {
        q[x][y] = 'Q';
        row[x]=col[y]=dg[x+y]=rdg[x-y+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=rdg[x-y+n]=false;
        q[x][y] = '.';
    }

}

int main()
{
    cin>>n;
    dfs(0,0,0);
    return 0;
}