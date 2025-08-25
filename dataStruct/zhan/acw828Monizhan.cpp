#include<iostream>
using namespace std;

const int N = 1e5+10;
int st[N],tt;
int m;

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        string op;
        cin>>op;
        int x;
        if(op=="push")
        {
            cin>>x;
            st[++tt] = x;
        }
        else if(op=="pop") tt--;
        else if(op=="empty") cout<<(tt?"NO":"YES")<<endl;
        else cout<<st[tt]<<endl;
    }
    return 0;
}