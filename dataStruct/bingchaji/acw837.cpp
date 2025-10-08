#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
int n,m;
int p[N],cnt[N];

int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i] = i;
        cnt[i] = 1;
    }
    while(m--)
    {
        string op;
        cin>>op;
        int a,b;
        if(op=="C")
        {
            cin>>a>>b;
            a = find(a),b = find(b);
            if(a!=b)
            {
                p[a] = b;
                cnt[b] += cnt[a];
            }
        }
        else if(op=="Q1")
        {
            cin>>a>>b;
            a = find(a),b = find(b);
            if(a==b) puts("Yes");
            else puts("No");
        }
        else
        {
            cin>>a;
            cout<<cnt[find(a)]<<endl;
        }
    }
    return 0;
}