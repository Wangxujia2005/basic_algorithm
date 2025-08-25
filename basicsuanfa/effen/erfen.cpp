#include <iostream>
using namespace std;
//整数二分
const int N = 1e5+10;
int n,m;
int q[N];
//板子
int bsearchleft(int l,int r,int x)
{
    while(l<r)
    {
        int mid = l+r>>1;
        if(q[mid]>=x) r = mid;
        else l = mid+1;
    }
    return l;
}

int bsearchright(int l,int r,int x)
{
    while(l<r)
    {
        int mid = l+r+1>>1;
        if(q[mid]<=x) l = mid;
        else r = mid-1;
    }
    return l;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        int l = bsearchleft(0,n-1,x);
        if(q[l] != x) cout << "-1 -1" << endl;
        else
        {
            int r = bsearchright(0,n-1,x);
            cout << l << ' ' << r << endl;
        }
    }

    return 0;
}


/*
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        int l = 0, r = n-1;
        while(l<r)
        {
            int mid = l+r>>1;
            if(q[mid]>=x) r = mid;
            else l = mid+1;
        }
        if(q[l]!=x) cout<<"-1 -1"<<endl;
        else{
            cout<<l<<' ';
            l = 0,r = n-1;
            while(l<r)
            {
                int mid = l+r+1>>1;
                if(q[mid]<=x) l = mid;
                else r = mid-1;
            }
            cout<<l<<endl;
        }
    }
*/