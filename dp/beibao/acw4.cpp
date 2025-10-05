#include<iostream>
#include<cstring>
#include<algorithm>

//多重背包问题
/*
集合，所有只从前i个物品中选，并且总体积不超过j的选法

属性 f[i][j] = max(f[i-1][j-v[i]*k]+w[i]*k) k=0,1,2,3,4........
*/
using namespace std;

const int N = 12100;
const int M = 2010;

int n,m;
int v[N],w[N],s[N];
int f[N][N];
int t[M];


void sovle1()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i]>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=s[i]&&k*w[i]<=j;k++)
            {
                f[i][j] = max(f[i][j],f[i-1][j-w[i]*k]+k*v[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
}

void sovle2()
{
    cin>>n>>m;
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        int a,b,s,k=1;
        cin>>a>>b>>s;
        while(k<=s)
        {
            w[++cnt] = k*a;
            v[cnt] = k*b;
            s = s-k;
            k = k*2;
        }
        if(s>0)
        {
            w[++cnt] = s*a;
            v[cnt] = s*b;
        }
    }

    n = cnt;

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=w[i];j--)
        {
            t[j] = max(t[j],t[j-w[i]]+v[i]);
        }
    }
    cout<<t[m]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(t,0,sizeof(t));
    sovle2();
    return 0;
}