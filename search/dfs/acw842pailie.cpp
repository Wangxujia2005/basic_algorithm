#include<iostream>
using namespace std;

/*
画树来模拟
*/
const int N = 10;
int n;
int path[N]; //路径
bool st[N]; //状态数组，是否用过？

void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++) cout<<path[i]<<' ';
        puts("");
    }

    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u] = i; 
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}