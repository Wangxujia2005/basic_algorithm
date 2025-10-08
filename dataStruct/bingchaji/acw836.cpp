#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int n,m;
int p[N];
int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i] = i;
    }
    while(m--)
    {
        char action;
        int a,b;
        cin>>action>>a>>b;
        p[a] = find(a);
        p[b] = find(b);
        if(action=='M')
        {
            //这里可以画图理解一下，理解祖宗的含义
            if(p[a]!=p[b]) p[p[a]] = p[b];
        }
        if(action=='Q')
        {
            if(p[a]==p[b]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}