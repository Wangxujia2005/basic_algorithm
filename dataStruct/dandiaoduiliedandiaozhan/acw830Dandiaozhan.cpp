#include<iostream>
using namespace std;
int n;
const int N = 1e5+10;
int st[N],tt;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        while(tt&&st[tt]>=x) tt--;
        if(tt==0) printf("-1 ");
        else printf("%d ",st[tt]);
        st[++tt] = x;
    }
    return 0;
}