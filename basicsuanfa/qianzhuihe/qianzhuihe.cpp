#include<iostream>
using namespace std;

int n,m;
const int N = 1e5+10;
int a[N],s[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];//前缀和的初始化
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]); //区间和的计算
    }
    return 0;
}