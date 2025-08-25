#include<iostream>
using namespace std;

const int N = 1e5+10;
int l[N],r[N],e[N],idx;
int m;

/*
0相当于虚拟头结点，1相当于虚拟尾结点
*/
//在节点a右边插入一个值
void insert(int a,int x)
{
    e[idx] = x;
    r[idx] = r[a];
    l[r[a]] = idx;
    r[a] = idx;
    l[idx] = a;
    idx++;
}

//删除节点a
void remove(int a)
{
    r[l[a]] = r[a];
    l[r[a]] = l[a];
}

int main()
{
    scanf("%d",&m);
    r[0] = 1;
    l[1] = 0;
    idx = 2;
    string pp;
    for(int i=1;i<=m;i++)
    {
        cin>>pp;
        if(pp=="L")
        {
            int x;
            scanf("%d",&x);
            insert(0,x);
        }
        else if(pp=="R")
        {
            int x;
            scanf("%d",&x);
            insert(l[1],x);
        }
        else if(pp=="D")
        {
            int k;
            scanf("%d",&k);
            remove(k+1);
        }
        else if(pp=="IL")
        {
            int k,x;
            scanf("%d%d",&k,&x);
            insert(l[k+1],x);
        }
        else
        {
            int k,x;
            scanf("%d%d",&k,&x);
            insert(k+1,x);
        }
    }
    for(int i=r[0];i!=1;i=r[i]) printf("%d ",e[i]);
    cout<<endl;
    return 0;
}