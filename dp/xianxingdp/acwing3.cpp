#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N,W;
int v[1005],w[1005];
int dp[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>N>>W;
    for(int i=1;i<=N;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=w[i];j<=W;j++)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[W]<<endl;

    return 0;
}