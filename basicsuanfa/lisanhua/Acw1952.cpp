#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,x,y,z;

vector<int> zhi; //存储A,B;
typedef pair<int,int> PII;
vector<PII> cow;
const int N = 4e4+10;
int a[N];
int find(int x)
{
    int l = 0,r = zhi.size()-1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(zhi[mid]>=x) r = mid;
        else l = mid+1;
    }
    return l;
}

int main()
{
    cin>>n>>x>>y>>z;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        zhi.push_back(a);
        zhi.push_back(b);
        cow.push_back({a,b});
    }

    sort(zhi.begin(),zhi.end());
    zhi.erase(unique(zhi.begin(),zhi.end()),zhi.end());

    for(auto item:cow)
    {
        int l = find(item.first);
        int r = find(item.second);
        a[0]+=x;
        a[l]+=y-x;
        a[r+1]+=z-y;
    }
    int ans = 0,sum=0;
    for(int i=0;i<zhi.size();i++)
    {
        sum+=a[i];
        ans = max(sum,ans);
    }

    cout<<ans<<endl;
    return 0;
}