#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int dp[105];
int v[105][105];//这个数组装的是第i组学j天可以拿到的学分
int n,m;
/*
这道题的关键是什么？
我们把分组背包看作是01背包的一种变形
dp[j] = max(dp[j-k]+v[i][k],dp[j]);
i这里代表的是组数，j代表的是天数，k也代表的是天数，不过我们这里采用了一种滚动数组的形式
实际上它的初始状态转移如下
dp[i][j] = max(dp[i-1][j],dp[i-1][j-k]+v[i][k]);

*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m&&n&&m)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>v[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                for(int k=1;k<=j;k++)
                {
                    dp[j] = max(dp[j-k]+v[i][k],dp[j]);
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}