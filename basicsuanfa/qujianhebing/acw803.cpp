#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//就是多个区间把它合并

/*
这道题
1 按区间左端点排序
2 有三种情况  第二个区间包含在第一个区间中
            第二个区间和第一个区间相交
            第二个区间在第一个区间外
*/

/*
左右端点初始化无限大
开始遍历，如果end小于了左端点，如果start不是无限大
那么压入start和end
让start等于左端点，end等于右端点，这里其实就是在更换下一个区间了

循环出来之后还要压入最后一个区间
*/

typedef pair<int,int> PII;
vector<PII> p;

void merge(vector<PII> &p)
{
    vector<PII> res;
    //左端点排个序,这里如果定义了结构，是默认左端点是排序依据
    sort(p.begin(),p.end());
    //左右端点初始化
    int start = -2e9,end = -2e9;
    for(auto item:p)
    {
        if(end<item.first)
        {
            if(start!=-2e9) res.push_back({start,end});
            start = item.first,end = item.second;
        }
        else{
            end = max(end,item.second);
        }
    }

    if(start!=-2e9) res.push_back({start,end});
    p = res;
}

int n;

int main()
{
    cin>>n;
    while(n--)
    {
        int l,r;
        cin>>l>>r;
        p.push_back({l,r});
    }

    merge(p);
    cout<<p.size()<<endl;
    return 0;
}