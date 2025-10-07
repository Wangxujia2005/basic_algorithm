#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5+10,M = 1e6+10;
char p[N],s[M];
int ne[N];
int n,m;
/*
实现next数组，next数组是模式串p中前缀等于后缀的最大长度数组
*/
void kmp()
{
    cin>>n>>p+1>>m>>s+1;//p+1，s+1这里是故意让字符串的起始坐标从1开始
    //' sdsjalkdj'就是这样，j=0时就是空
    //模式串p 来求next数组
    for(int i=2,j=0;i<=n;i++)
    {
        //画图理解
        //把模式往右滑，使得原来已匹配的后缀对齐到模式的前缀位置，检查是否能从那里继续匹配
        while(j&&p[i]!=p[j+1]) j = ne[j];
        if(p[i]==p[j+1]) j++;
        ne[i] = j;
    }
    //字符串s
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s[i]!=p[j+1]) j = ne[j];
        if(s[i]==p[j+1]) j++;
        if(j==n)
        {
            cout<<i-n<<' ';
            j = ne[j];
        } 
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    kmp();
    return 0;
}