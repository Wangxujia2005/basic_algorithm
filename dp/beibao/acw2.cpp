#include<iostream>
#include<algorithm>


using namespace std;

const int N = 1010;
int dp[N][N];
int v[N],w[N];
int n,m;
int f[N];

void solve1()
{
    //dp[i][j]表示i个物品中选，背包容量不超过j的最大价值
    //i表示的是第i个物品，j始终表示的是容量
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j<w[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            } 
        }
    }
    cout<<dp[n][m];
}

void solve2()
{
    //如果正着更新
    /*
    for(int j=w[i];j<=m;j++)
    假如当前重量是2，价值是3，m是4
    那么f[2] = max(f[2],f[0]+3);
    到后面，f[4] = max(f[4],f[2]+3);
    重量是2的物品是不是相当于多放入一次，
    这并不是因为f[2]因为f[2]+3这条语句而更新，
    而是因为我的f[2]在f[2] = max(f[2],f[0]+3);中已经加了价值为3的这个物品了
    而f[2]+3这里相当于又多放了一次。这样就不符合01背包的要求了
    */

    //如果反方向更新
    /*
    f[4] = max(f[4],f[2]+3);
    f[2] = max(f[2],f[0]+3);
    并不会存在多加的情况
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=w[i];j--)
        {
            //同样的道理，第i个物品要不要装
            //要是不装，那么继承之前的状态，要是要装，那么就是不装i的最好结果加上i的价值
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout<<f[m]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i] ;
    solve2();
    return 0;
}