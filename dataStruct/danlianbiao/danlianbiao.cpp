#include<iostream>
using namespace std;
/*
单链表：用途基本是邻接表  用来存树和图
双链表：用来优化某些问题

单链表 e[N]值  next[N]当前结点指向的下一个结点  head是头指针
*/

// 在头结点插入一个数，也就是第一个结点前面插入一个数
// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
const int N = 1e5+10;
int head,e[N],ne[N],idx;
int m;

void init()
{
    head = -1;
    idx = 0;
}

// x插在头结点前面
void addHead(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

//在k结点的后插入x
void addAfterK(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}


//删除k结点后的点
void removeAfterK(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    scanf("%d",&m);
    char cz;
    for(int i=1;i<=m;i++)
    {
        cin>>cz;
        if(cz=='H')
        {
            int x;
            cin>>x;
            addHead(x);
        }
        else if(cz=='D')
        {
            int k;
            cin>>k;
            if(k==0) head = ne[head];
            else removeAfterK(k-1);
        }
        else
        {
            int k,x;
            cin>>k>>x;
            addAfterK(k-1,x);
        }
    }

    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
    cout<<endl;
    return 0;
}