#include<iostream>
#include<vector>
#include<algorithm>
//acwing802
using namespace std;
/*
离散化的思想
值域 0~10^9 很大   个数 10^5 却比较小  大材小用
a[] 1 3 100 2000 500000
    0 1 2   3    4
1：a[]中可能有重复元素  去重
2：如何算出x离散化后的值是多少  二分
3：比如我离散化之前的数据的位置是L和R
   在离散化之后的位置是Kl和kr,
   那么就使用离散化后的位置进行操作
*/

/*
alls 存储所有的位置 ->排序加去重
add 存储位置和加的值 ->先找离散化后的位置，再加值
query 存储要计算的区间 ->先找离散化后的位置，再计算前缀和
*/

typedef pair<int,int> PII;
int n,m;
vector<int> alls; //存储下标
vector<PII> add,query; // 存储位置和加的值，，，存储询问位置的值
const int N = 3e5+10;
int a[N],s[N];
int find(int x)
{
    int l = 0,r = alls.size()-1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(alls[mid]>=x) r = mid;
        else l = mid+1;
    }

    return r+1;
}

int main()
{
    cin>>n>>m;
    while(n--)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }

    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    for(auto item:add)
    {
        int x = find(item.first);
        a[x] +=item.second;
    }
    
    for(int i=1;i<=alls.size();i++)
    {
        s[i] = s[i-1]+a[i];
    }

    for(auto item:query)
    {
        int l = find(item.first);
        int r = find(item.second);
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}

