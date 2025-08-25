#include<iostream>
using namespace std;
/*
//j只会右移
for(int i=0,j=0;i<n;i++)
{
    while(j<=i&&check(i,j)) j++;
    //每道题的具体逻辑
}
*/
//最长连续无重复子序列
int n;
const int N = 1e5+10;
int q[N];
int m[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    int le=0;
    int ans = 0;
    for(int rt=0;rt<n;rt++)
    {
        m[q[rt]]++;
        while(m[q[rt]]>1)
        {
            m[q[le]]--;
            le++;
        }
        ans = max(ans,rt-le+1);
    }
    cout<<ans<<endl;
    return 0;
}