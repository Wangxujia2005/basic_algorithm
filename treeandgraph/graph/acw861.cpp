#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
//匈牙利算法求解二分图的最大匹配
int n1,n2,m;
const int N = 505,M = 100010;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j = e[i];
        /*
        //当find(match[j])时，由于st[j]=true了，已经被现在男生预定
        所以前男友并不能匹配它，而是看看有没有别的女生。
        如果有，那么这个女生让给新男生
        */
        if(!st[j])
        {
            st[j] = true;
            if(match[j]==0||find(match[j]))//详细看上文注释
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(h,-1,sizeof(h));
    cin>>n1>>n2>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    int res = 0;
    for(int i = 1;i<=n1;i++)
    {
        memset(st,false,sizeof(st));
        if(find(i)) res++;
    }
    cout<<res<<endl;
    return 0;
}