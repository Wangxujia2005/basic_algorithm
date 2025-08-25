#include<iostream>
using namespace std;
//有点问题，右边界r应该设为max(1,x)
int main()
{
    double x;
    scanf("%lf",&x);
    double l = 0,r = x;
    while(r-l>1e-8)
    {
        double mid = (l+r)/2;
        if(mid*mid>=x) r = mid;
        else l = mid;//因为是浮点数，不能-1
    }
    printf("%.6f\n",l);
    return 0;
}