#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,tiji;
int v[1005],w[1005];
int dp[1005];
int dp2[2][1005];
void sovle1()
{
    //滚动数组，这是自身滚动
    for(int i=1;i<=n;i++)
    {
        for(int j=tiji;j>=w[i];j--)
        {
            dp[j] = max(dp[j-w[i]]+v[i],dp[j]);
        }
    }
    cout<<dp[tiji];
}

void sovle2()
{
    //滚动数组，不过这是交替滚动
    int now =0,old =1;
    for(int i=1;i<=n;i++)
    {
        swap(old,now);
        for(int j=0;j<=tiji;j++)
        {
            if(w[i]>j) dp2[now][j] = dp2[old][j];
            else dp2[now][j] = max(dp2[old][j],dp2[old][j-w[i]]+v[i]);
        }
    }
    cout<<dp2[now][tiji];
}



int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>tiji;

        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int j=1;j<=n;j++) cin>>w[j];
        sovle1();


    }
    return 0;
}