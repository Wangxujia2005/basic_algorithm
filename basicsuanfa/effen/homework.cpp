#include<iostream>
using namespace std;

//当输入的x小于1时，开方的结果应该要大一些
//所以边界不能设为0和x，，应该是（0，max（1，x））
int main()
{
    double n;
    bool flag = true;
    cin>>n;
    if(n<0)
    {
        n = -n;
        flag = false;
    }
    double le = 0,rt = max(1.0,n);
    while(rt-le>1e-8)
    {
        double mid = (le+rt)/2;
        if(mid*mid*mid>=n) rt = mid;
        else le = mid; 
    }
    if(!flag) le = -le;
    printf("%.6lf",le);
    return 0;
}