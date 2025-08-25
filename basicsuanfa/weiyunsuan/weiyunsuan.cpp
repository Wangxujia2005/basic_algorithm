#include<iostream>
using namespace std;

//n的二进制表示中，第k位是几？ (n>>k)&1
/*
1.先把第k位移到最后一位  n>>k
2.看个位是几  x&1
3.如果是1，说明第k位是1，否则是0
*/

/*  lowbit比较适合求解二进制表示中1的个数
lowbit(x) :返回x的最后一位1
x=1010         lowbit(x) = 10;
x = 101000     lowbit(x) = 1000;
lowbit(x) = x & (-x);
-x = ~x+1   //取反加一
*/

/*
与运算是合取
或运算是析取
非运算是反
*/

/*
正数 三码是一样的
负数 补码是取反加一
*/

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int res = 0;
        int x;
        cin>>x;
        while(x)
        {
            x-=lowbit(x);
            res++;
        }
        cout<<res<<' ';
    }
    return 0;
}