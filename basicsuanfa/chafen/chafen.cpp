#include<iostream>
using namespace std;
//差分是前缀和的逆运算
//适用于：区间内所有的数都加一个相同的数
const int N = 1e5+10;
int n,m;
int a[N],b[N];

//板子
void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c; //结合第19行就是，b[i] = a[i+1]-a[i]
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) insert(i,i,a[i]); //初始化差分数组
    while(m--)
    {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    //b[1] = b[1]+b[0];b[2] = b[2]+b[1];
    for(int i=1;i<=n;i++) b[i] += b[i-1]; //差分数组转化为前缀和
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    return 0;
}

/*
int n,m;
const int N = 1e5+10;
int a[N],b[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i] = a[i] - a[i-1];
    }

    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        b[l]+=c;
        b[r+1]-=c;
    }
    for(int i=1;i<=n;i++)
    {
        b[i] += b[i-1];
        cout<<b[i]<<' ';
    }
    return 0;

}

*/