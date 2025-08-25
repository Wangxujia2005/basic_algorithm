#include<iostream>
using namespace std;
const int N = 1e6+10;
int n,k;
int a[N],q[N];
/*
这里q存储的是入队后的数的下标
1. 不空且长度大于滑窗的长度，那么滑出第一个数字
2. 不空且队尾的数不满足单调性，那么就把队尾的数滑出
3. 队尾加入新的数
4. 每满足滑窗长度，就放出队头的数，这里妙用了i>=k-1
*/
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i-q[hh]+1>k) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        q[++tt] = i;
        if(i+1-k>=0) printf("%d ",a[q[hh]]);
    }
    puts("");
    hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i-q[hh]+1>k) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[++tt] = i;
        if(i-k+1>=0) printf("%d ",a[q[hh]]); 
    }
    puts("");
    return 0;
}