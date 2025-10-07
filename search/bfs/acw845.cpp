#include<iostream>
#include<cstring>
#include<algorithm>
#include <unordered_map>
#include <queue>


using namespace std;
//八数码,使用BFS
/*
队列？
如何记录每个状态的距离
*/

int bfs(string start)
{
    queue<string> q;
    unordered_map<string,int> d;
    q.push(start);
    d[start] = 0;
    int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0};
    string end = "12345678x";
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        if(t==end) return d[t];

        int distance = d[t];
        int k = t.find('x');
        int x = k/3,y = k%3;
        for(int i=0;i<4;i++)
        {
            int a = x+dx[i],b = y+dy[i];
            if(a>=0&&a<3&&b>=0&&b<3)
            {
                swap(t[a*3+b],t[k]);
                if(!d.count(t))
                {
                    d[t]+=distance+1;
                    q.push(t);
                }
                swap(t[a*3+b],t[k]);//恢复一下，好枚举其他的状态
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string start;
    for(int i=1;i<=9;i++)
    {
        char c;
        cin>>c;
        start+=c;
    }
    cout<<bfs(start)<<endl;
    return 0;
}