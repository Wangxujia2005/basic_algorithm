#include<iostream>
using namespace std;
typedef long long LL;
LL n,m,x;
const int N = 1e5+10;
LL a[N],b[N];
int main()
{
    scanf("%lld%lld%lld",&n,&m,&x);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<m;i++) scanf("%lld",&b[i]);

    for(int i=0,j=m-1;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x) 
        {
            printf("%lld %lld",i,j);
            printf("\n");
            break;
        }
    }
    return 0;
}