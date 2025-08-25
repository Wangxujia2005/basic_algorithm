#include<iostream>
using namespace std;

typedef long long LL;
int n;
const int N = 1e5+10;
int q[N],temp[N];

LL merge_sort(int l,int r)
{
    if(l>=r) return 0;
    int mid = l+r>>1;
    int i = l,j = mid+1,k=0;
    LL ans=merge_sort(l,mid)+merge_sort(mid+1,r);
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j]) temp[k++] = q[i++];
        else
        {
            temp[k++] = q[j++];
            ans+=mid-i+1;//统计逆序对
        }
    }
    while(i<=mid) temp[k++] = q[i++];
    while(j<=r) temp[k++] = q[j++];
    for(int i=l,j=0;i<=r;i++,j++) q[i] = temp[j];
    return ans;
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    
    printf("%lld",merge_sort(0,n-1));
    return 0;
}