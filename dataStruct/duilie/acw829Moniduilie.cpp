#include<iostream>
using namespace std;

const int N = 1e5;
int m;
int q[N],hh,tt=-1;

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            q[++tt] = x;
        }
        else if(op=="pop") hh++;
        else if(op=="empty") cout<<(hh<=tt?"NO":"YES")<<endl;
        else cout<<q[hh]<<endl;
    }

    return 0;
}