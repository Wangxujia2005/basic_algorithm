#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110,V = 110;
int n,m;
int v[N][N],w[N][N],s[N];
int f[N];
void sovle()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j = 1;j<=s[i];j++)
        {
            cin>>w[i][j]>>v[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            for(int k = 1;k<=s[i];k++)
            {
                if(w[i][k]<=j)
                {
                    f[j] = max(f[j],f[j-w[i][k]]+v[i][k]);
                }
            }
        }
    }
    cout<<f[m]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(f,0,sizeof(f));
    sovle();
    return 0;
}