#include<iostream>
using namespace std;
int n,m;
const int N = 1e5+10;
int a[N],b[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    int count = n;
    for(int i=0,j=0;i<n;i++)
    {
        while(j<m&&a[i]!=b[j]) j++;
        if(a[i]==b[j]&&j<m)
        {
            count--;
            j++;
        }
    }
    if(count==0) printf("Yes\n");
    else printf("No\n");
    return 0;
}