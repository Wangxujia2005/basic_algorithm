#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1e5+10,M = N*2;
int h[N],e[M],ne[M],idx=0;
bool st[N]; //表示这个结点有没有被访问过
int n;
int ans = N;
void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}
//u结点，是实实在在的结点
//e，ne都是存的下标，h存的是最前面的下标
int dfs(int u)
{
    st[u] = true;
    int sum=1,res = 0;//res是除掉当前结点的其余连通块的最大联通数量
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res,s);//先找u结点中最大的子树
            sum+=s;
        }
    }
    res = max(res,n-sum);//最大的子树和删掉整个u结点及以其子树的剩余部分进行比较，谁更大，那么谁作为最大连通数量。
    //在递归中，相当于每个结点都做了这个比较，所以ans是基于每个结点的递归的更新，因此我们dfs任意一个结点都可以获得正确的结果
    ans = min(res,ans);
    return sum;//sum是子树
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}