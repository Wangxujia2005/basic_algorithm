#include<iostream>
using namespace std;

//完全背包,这里其实就是把01背包正着遍历，这样可以达到多次选一个物品的情况
int n,m;
const int N = 1010;
int w[N],v[N];
int dp[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=w[i];j<=m;j++)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
    return 0;
}